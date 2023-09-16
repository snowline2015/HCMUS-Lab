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
            string query = string.Empty;

            if (checkTextBox())
            {
                query = "EXEC SP_INS_ENCRYPT_NHANVIEN '"+ textBox1.Text.Trim() +
                    "', '" + textBox4.Text.Trim() + "', '" + textBox2.Text.Trim() + 
                    "', '" + AESOperation.EncryptString(textBox5.Text.Trim()) + 
                    "', '" + textBox3.Text.Trim() + "', '" + Form1.Sha1(textBox6.Text.Trim()) + "'";
                SqlCommand cmd = new SqlCommand(query, Program.con);
                cmd.ExecuteNonQuery();

                query = "EXEC SP_SEL_ENCRYPT_NHANVIEN";
                SqlDataAdapter sda = new SqlDataAdapter(query, Program.con);
                DataTable dtbl = new DataTable();
                sda.Fill(dtbl);

                for (int i = 0; i < dtbl.Rows.Count; i++)
                {
                    dtbl.Rows[i]["LUONG"] = AESOperation.DecryptString(dtbl.Rows[i]["LUONG"].ToString());
                }

                dataGridView1.DataSource = dtbl;

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
    }

    public class AESOperation
    {
        public static string key = "19127102%00%00%00%00%00%00%00%00";

        public static string EncryptString(string plainText)
        {
            byte[] iv = new byte[16];
            byte[] array;

            using (Aes aes = Aes.Create())
            {
                aes.Key = Encoding.UTF8.GetBytes(key);
                aes.IV = iv;

                ICryptoTransform encryptor = aes.CreateEncryptor(aes.Key, aes.IV);

                using (MemoryStream memoryStream = new MemoryStream())
                {
                    using (CryptoStream cryptoStream = new CryptoStream((Stream)memoryStream, encryptor, CryptoStreamMode.Write))
                    {
                        using (StreamWriter streamWriter = new StreamWriter((Stream)cryptoStream))
                        {
                            streamWriter.Write(plainText);
                        }

                        array = memoryStream.ToArray();
                    }
                }
            }

            return Convert.ToBase64String(array);
        }

        public static string DecryptString(string cipherText)
        {
            byte[] iv = new byte[16];
            byte[] buffer = Convert.FromBase64String(cipherText);

            using (Aes aes = Aes.Create())
            {
                aes.Key = Encoding.UTF8.GetBytes(key);
                aes.IV = iv;
                ICryptoTransform decryptor = aes.CreateDecryptor(aes.Key, aes.IV);

                using (MemoryStream memoryStream = new MemoryStream(buffer))
                {
                    using (CryptoStream cryptoStream = new CryptoStream((Stream)memoryStream, decryptor, CryptoStreamMode.Read))
                    {
                        using (StreamReader streamReader = new StreamReader((Stream)cryptoStream))
                        {
                            return streamReader.ReadToEnd();
                        }
                    }
                }
            }
        }
    }

    
}
