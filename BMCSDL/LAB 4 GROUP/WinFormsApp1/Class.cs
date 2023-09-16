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
    public partial class Class : Form
    {
        public string EmployeeID;

        public Class()
        {
            InitializeComponent();
            enableTextBox(false);
        }

        private bool checkTextBox()
        {
            if (!string.IsNullOrWhiteSpace(textBox1.Text) && !string.IsNullOrWhiteSpace(textBox2.Text))
            {
                return true;
            }
            else return false;
        }

        private void enableTextBox(bool enable)
        {
            if (enable)
            {
                textBox1.Enabled = true;    // Class ID
                textBox2.Enabled = true;    // Class name
            }
            else
            {
                textBox1.Text = string.Empty;
                textBox2.Text = string.Empty;
                textBox1.Enabled = false;
                textBox2.Enabled = false;
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
                string query = "EXEC SP_INS_PUBLIC_ENCRYPT_LOP '" + textBox1.Text.Trim() +
                    "', '" + textBox2.Text.Trim() + "', '" + EmployeeID + "'";
                SqlCommand cmd = new SqlCommand(query, Program.con);
                cmd.ExecuteNonQuery();

                query = "EXEC SP_SEL_PUBLIC_ENCRYPT_LOP_BY_NHANVIEN '" + EmployeeID + "'";
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
            if (e.ColumnIndex == dataGridView1.Columns["SINHVIEN"].Index)
            {
                Student st = new Student();
                DataGridViewRow current = dataGridView1.CurrentRow;
                st.ClassID = current.Cells[dataGridView1.Columns["MALOP"].Index].Value.ToString();

                string query = "EXEC SP_SEL_PUBLIC_ENCRYPT_SINHVIEN_BY_MALOP '" + st.ClassID + "'";
                SqlDataAdapter sda = new SqlDataAdapter(query, Program.con);
                DataTable dtbl = new DataTable();
                sda.Fill(dtbl);
                st.dataGridView1.DataSource = dtbl;

                DataGridViewButtonColumn editGradeButton = new DataGridViewButtonColumn();
                editGradeButton.Name = "BANGDIEM";
                editGradeButton.Text = "Show";
                editGradeButton.UseColumnTextForButtonValue = true;
                if (st.dataGridView1.Columns["STUDENTS"] == null)
                {
                    st.dataGridView1.Columns.Insert(st.dataGridView1.ColumnCount, editGradeButton);
                }

                st.ShowDialog();
            }
        }
    }
}
