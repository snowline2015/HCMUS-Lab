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
    public partial class Student : Form
    {
        public string ClassID;

        public Student()
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
                textBox2.Enabled = true;    // Address
                textBox3.Enabled = true;    // Username
                textBox4.Enabled = true;    // Fullname
                textBox5.Enabled = true;    // Birthday
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

        // Add button
        private void button1_Click(object sender, EventArgs e)
        {
            enableTextBox(true);
        }

        // Write/Save button
        private void button3_Click(object sender, EventArgs e)
        {
            if (checkTextBox())
            {
                string query = "EXEC SP_INS_PUBLIC_ENCRYPT_SINHVIEN '" + textBox1.Text.Trim() +
                    "', '" + textBox4.Text.Trim() + "', '" + textBox5.Text.Trim() +
                    "', '" + textBox2.Text.Trim() + "', '" + ClassID + 
                    "', '" + textBox3.Text.Trim() + "', '" + Form1.Md5(textBox6.Text.Trim()) + "'";
                SqlCommand cmd = new SqlCommand(query, Program.con);
                cmd.ExecuteNonQuery();

                query = "EXEC SP_SEL_PUBLIC_ENCRYPT_SINHVIEN_BY_MALOP '" + ClassID + "'";
                SqlDataAdapter sda = new SqlDataAdapter(query, Program.con);
                DataTable dtbl = new DataTable();
                sda.Fill(dtbl);

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
            this.Hide();
            this.Close();
        }

        private void dataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            if (e.ColumnIndex == dataGridView1.Columns["BANGDIEM"].Index)
            {
                Grade grade = new Grade();
                DataGridViewRow current = dataGridView1.CurrentRow;
                grade.StudentID = current.Cells[dataGridView1.Columns["MASV"].Index].Value.ToString();

                string query = "EXEC SP_SEL_PUBLIC_ENCRYPT_BANGDIEM '" + grade.StudentID + "'";
                SqlDataAdapter sda = new SqlDataAdapter(query, Program.con);
                DataTable dtbl = new DataTable();
                sda.Fill(dtbl);

                for (int i = 0; i < dtbl.Rows.Count; i++)
                {
                    dtbl.Rows[i]["DIEMTHI"] = Program.rsa.Decrypt(dtbl.Rows[i]["DIEMTHI"].ToString());
                }

                grade.dataGridView1.DataSource = dtbl;

                grade.ShowDialog();
            }
        }
    }
}
