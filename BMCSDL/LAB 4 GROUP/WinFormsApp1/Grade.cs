using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WinFormsApp1
{
    public partial class Grade : Form
    {
        public string StudentID;

        public Grade()
        {
            InitializeComponent();
            enableTextBox(false);
        }

        private void dataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private bool checkTextBox()
        {
            if (!string.IsNullOrWhiteSpace(textBox1.Text) && !string.IsNullOrWhiteSpace(textBox4.Text))
            {
                return true;
            }
            else return false;
        }

        private void enableTextBox(bool enable)
        {
            if (enable)
            {
                textBox1.Enabled = true;    // Course ID
                textBox4.Enabled = true;    // Grade
            }
            else
            {
                textBox1.Text = string.Empty;
                textBox4.Text = string.Empty;
                textBox1.Enabled = false;
                textBox4.Enabled = false;
            }
        }

        // Add button
        private void button1_Click(object sender, EventArgs e)
        {
            enableTextBox(true);
        }

        // Delete button
        private void button5_Click(object sender, EventArgs e)
        {
            
        }

        // Edit button
        private void button4_Click(object sender, EventArgs e)
        {
            
        }

        // Write/Save button
        private void button3_Click(object sender, EventArgs e)
        {
            if (checkTextBox())
            {
                string query = "EXEC SP_INS_PUBLIC_ENCRYPT_BANGDIEM '" + StudentID +
                    "', '" + textBox1.Text.Trim() + "', '" + Program.rsa.Encrypt(textBox4.Text.Trim()) + "'";
                SqlCommand cmd = new SqlCommand(query, Program.con);
                cmd.ExecuteNonQuery();

                query = "EXEC SP_SEL_PUBLIC_ENCRYPT_BANGDIEM '" + StudentID + "'";
                SqlDataAdapter sda = new SqlDataAdapter(query, Program.con);
                DataTable dtbl = new DataTable();
                sda.Fill(dtbl);

                dataGridView1.DataSource = dtbl;

                for (int i = 0; i < dtbl.Rows.Count; i++)
                {
                    dtbl.Rows[i]["DIEMTHI"] = Program.rsa.Decrypt(dtbl.Rows[i]["DIEMTHI"].ToString());
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
            this.Hide();
            this.Close();
        }
    }
}
