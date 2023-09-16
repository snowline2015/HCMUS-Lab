using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WinFormsApp1
{
    public partial class ListConsole : Form
    {
        public ListConsole()
        {
            InitializeComponent();
            enableTextBox(false);
        }

        private bool checkTextBox()
        {
            if (!string.IsNullOrWhiteSpace(textBox1.Text) && !string.IsNullOrWhiteSpace(textBox2.Text) &&
                !string.IsNullOrWhiteSpace(textBox3.Text) && !string.IsNullOrWhiteSpace(textBox4.Text) &&
                !string.IsNullOrWhiteSpace(textBox5.Text) && !string.IsNullOrWhiteSpace(textBox6.Text))
            {
                return true;
            }
            else return false;
        }

        private void enableTextBox(bool enable)
        {
            if (enable)
            {
                textBox1.Enabled = true;    // ID
                textBox2.Enabled = true;    // Email
                textBox3.Enabled = true;    // Username
                textBox4.Enabled = true;    // Fullname
                textBox5.Enabled = true;    // Salary
                textBox6.Enabled = true;    // Password
            }
            else
            {
                textBox1.Text = string.Empty;
                textBox2.Text = string.Empty;
                textBox3.Text = string.Empty;
                textBox4.Text = string.Empty;
                textBox5.Text = string.Empty;
                textBox6.Text = string.Empty;
                textBox1.Enabled = false;
                textBox2.Enabled = false;
                textBox3.Enabled = false;
                textBox4.Enabled = false;
                textBox5.Enabled = false;
                textBox6.Enabled = false;
            }
        }

        private void label5_Click(object sender, EventArgs e)
        {
            
        }

        // Add button
        private void button1_Click(object sender, EventArgs e)
        {
            enableTextBox(true);
        }
        
        // Delete button
        private void button5_Click(object sender, EventArgs e)
        {
            if (checkTextBox())
            {

            }
        }

        // Edit button
        private void button4_Click(object sender, EventArgs e)
        {
            if (checkTextBox())
            {

            }
        }

        // Write/Save button
        private void button3_Click(object sender, EventArgs e)
        {
            if (checkTextBox())
            {
                string query = "EXEC SP_INS_PUBLIC_ENCRYPT_NHANVIEN '" + textBox1.Text.Trim() +
                    "', '" + textBox4.Text.Trim() + "', '" + textBox2.Text.Trim() + 
                    "', '" + Program.rsa.Encrypt(textBox5.Text.Trim()) + 
                    "', '" + textBox3.Text.Trim() + "', '" + Form1.Sha1(textBox6.Text.Trim()) +
                    "', '" + RSAOperation.publicKey + "'";
                SqlCommand cmd = new SqlCommand(query, Program.con);
                cmd.ExecuteNonQuery();

                query = "EXEC SP_SEL_PUBLIC_ENCRYPT_ALL_NHANVIEN";
                SqlDataAdapter sda = new SqlDataAdapter(query, Program.con);
                DataTable dtbl = new DataTable();
                sda.Fill(dtbl);

                for (int i = 0; i < dtbl.Rows.Count; i++)
                {
                    dtbl.Rows[i]["LUONG"] = Program.rsa.Decrypt(dtbl.Rows[i]["LUONG"].ToString());
                }

                dataGridView1.DataSource = dtbl;

                DataGridViewButtonColumn editButton = new DataGridViewButtonColumn();
                editButton.Name = "LOP";
                editButton.Text = "Show";
                editButton.UseColumnTextForButtonValue = true;
                if (dataGridView1.Columns["LOP"] == null)
                {
                    dataGridView1.Columns.Insert(dataGridView1.ColumnCount, editButton);
                }

                enableTextBox(false);
            }
        }

        // Cancel button
        private void button6_Click(object sender, EventArgs e)
        {
            enableTextBox(false);
        }

        // Exit button
        private void button2_Click(object sender, EventArgs e)
        {
            Program.con.Close();
            this.Hide();
            Form1 loginForm = new Form1();
            loginForm.ShowDialog();
            this.Close();
        }

        private void dataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            if (e.ColumnIndex == dataGridView1.Columns["LOP"].Index)
            {
                Class classes = new Class();
                DataGridViewRow current = dataGridView1.CurrentRow;
                classes.EmployeeID = current.Cells[dataGridView1.Columns["MANV"].Index].Value.ToString();

                string query = "EXEC SP_SEL_PUBLIC_ENCRYPT_LOP_BY_NHANVIEN '" + classes.EmployeeID + "'";
                SqlDataAdapter sda = new SqlDataAdapter(query, Program.con);
                DataTable dtbl = new DataTable();
                sda.Fill(dtbl);
                classes.dataGridView1.DataSource = dtbl;

                DataGridViewButtonColumn editButton = new DataGridViewButtonColumn();
                editButton.Name = "SINHVIEN";
                editButton.Text = "Show";
                editButton.UseColumnTextForButtonValue = true;
                if (classes.dataGridView1.Columns["SINHVIEN"] == null)
                {
                    classes.dataGridView1.Columns.Insert(classes.dataGridView1.ColumnCount, editButton);
                }

                classes.ShowDialog();
            }
        }
    }

    public class RSAOperation
    {
        static RSACryptoServiceProvider Generator;
        static UnicodeEncoding ByteConverter = new UnicodeEncoding();

        public static string publicKey;

        public RSAOperation()
        {
            if (!File.Exists("rsa_pub.txt") && !File.Exists("rsa.txt"))
            {
                Generator = new RSACryptoServiceProvider(512);

                var privKey = Generator.ExportParameters(true);
                var pubKey = Generator.ExportParameters(false);

                string pubKeyString;
                {
                    var sw = new System.IO.StringWriter();
                    var xs = new System.Xml.Serialization.XmlSerializer(typeof(RSAParameters));
                    xs.Serialize(sw, pubKey);
                    pubKeyString = sw.ToString();
                }

                string privKeyString;
                {
                    var sw = new System.IO.StringWriter();
                    var xs = new System.Xml.Serialization.XmlSerializer(typeof(RSAParameters));
                    xs.Serialize(sw, privKey);
                    privKeyString = sw.ToString();
                }

                using (StreamWriter sw = File.CreateText("rsa_pub.txt")) {
                    sw.WriteLine(pubKeyString);
                }

                using (StreamWriter sw = File.CreateText("rsa.txt"))
                {
                    sw.WriteLine(privKeyString);
                }
            }
            else
            {
                publicKey = Convert.ToBase64String(Encoding.UTF8.GetBytes(File.ReadAllText("rsa_pub.txt")));
            }
        }

        public string Encrypt(string plaintext)
        {
            try
            {
                byte[] dataToEncrypt = ByteConverter.GetBytes(plaintext);
                byte[] encryptedData;

                using (RSACryptoServiceProvider RSA = new RSACryptoServiceProvider())
                {
                    string pubKeyString = File.ReadAllText("rsa_pub.txt");
                    {
                        var sr = new System.IO.StringReader(pubKeyString);
                        var xs = new System.Xml.Serialization.XmlSerializer(typeof(RSAParameters));
                        var pubKey = (RSAParameters)xs.Deserialize(sr);
                        RSA.ImportParameters(pubKey);
                    }
                    encryptedData = RSA.Encrypt(dataToEncrypt, false);
                }
                return Convert.ToBase64String(encryptedData);
            }
            catch (CryptographicException e)
            {
                // Console.WriteLine("Encryption failed.");
                return null;
            }
        }

        public string Decrypt(string ciphertext)
        {
            try
            {
                byte[] encryptedData = Convert.FromBase64String(ciphertext);
                byte[] decryptedData;

                using (RSACryptoServiceProvider RSA = new RSACryptoServiceProvider())
                {
                    string privKeyString = File.ReadAllText("rsa.txt");
                    {
                        var sr = new System.IO.StringReader(privKeyString);
                        var xs = new System.Xml.Serialization.XmlSerializer(typeof(RSAParameters));
                        var privKey = (RSAParameters)xs.Deserialize(sr);
                        RSA.ImportParameters(privKey);
                    }
                    decryptedData = RSA.Decrypt(encryptedData, false);
                }
                return ByteConverter.GetString(decryptedData);
            }
            catch (CryptographicException e)
            {
                // Console.WriteLine("Encryption failed.");
                return null;
            }
        }
    }
}
