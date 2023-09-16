using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;
using System.Security.Cryptography;

namespace WinFormsApp1
{
    public partial class Form1 : Form
    {
        public string LoginEmployeeID;

        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        public static string Md5(string input, bool isLowercase = false)
        {
            using (var md5 = MD5.Create())
            {
                var byteHash = md5.ComputeHash(Encoding.UTF8.GetBytes(input));
                var hash = BitConverter.ToString(byteHash).Replace("-", "");
                return (isLowercase) ? hash.ToLower() : hash;
            }
        }

        public static string Sha1(string input, bool isLowercase = false)
        {
            using (var sha1 = SHA1.Create())
            {
                var byteHash = sha1.ComputeHash(Encoding.UTF8.GetBytes(input));
                var hash = BitConverter.ToString(byteHash).Replace("-", "");
                return (isLowercase) ? hash.ToLower() : hash;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string query = "EXEC SP_SEL_PUBLIC_ENCRYPT_NHANVIEN '" + textBox1.Text.Trim() + "', '" + Sha1(textBox2.Text.Trim()) + "'";
            SqlDataAdapter sda = new SqlDataAdapter(query, Program.con);
            DataTable dtbl = new DataTable();
            sda.Fill(dtbl);
            if (dtbl.Rows.Count == 1)
            {
                MessageBox.Show("Login Sucessfully !");

                LoginEmployeeID = textBox1.Text.Trim();

                ListConsole lc = new ListConsole();
                query = "EXEC SP_SEL_PUBLIC_ENCRYPT_ALL_NHANVIEN";
                sda.SelectCommand.CommandText = query;

                dtbl.Clear();
                int count = dtbl.Columns.Count;
                for (int i = 0; i < count; i++)
                {
                    dtbl.Columns.RemoveAt(0);
                }
                sda.Fill(dtbl);

                for (int i = 0; i < dtbl.Rows.Count; i++)
                {
                    dtbl.Rows[i]["LUONG"] = Program.rsa.Decrypt(dtbl.Rows[i]["LUONG"].ToString());
                }

                lc.dataGridView1.DataSource = dtbl;

                DataGridViewButtonColumn editButton = new DataGridViewButtonColumn();
                editButton.Name = "LOP";
                editButton.Text = "Show";
                editButton.UseColumnTextForButtonValue = true;
                if (lc.dataGridView1.Columns["LOP"] == null)
                {
                    lc.dataGridView1.Columns.Insert(lc.dataGridView1.ColumnCount, editButton);
                }

                this.Hide();
                lc.ShowDialog();
                this.Close();
            }
            else
            {
                MessageBox.Show("Username or Password is incorrect !");
                Program.con.Close();
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}
