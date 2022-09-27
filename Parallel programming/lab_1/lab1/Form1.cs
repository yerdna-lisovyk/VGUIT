using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.DataVisualization.Charting;



namespace lab1
{
    public partial class Form1 : Form
    {
        int i = 0;
        int n, m;

        public Form1()
        {
            InitializeComponent();
        }

        private void chart2_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            label8.Text = "";
            if (numericUpDown4.Value <= numericUpDown5.Value)
            {
                label8.Text = "Макс значение не м.б. меньше мин значения!"; return; }
            button1.Enabled = false;
            int count, current = 0;
                count = (Convert.ToInt32(numericUpDown2.Value) -
               Convert.ToInt32(numericUpDown1.Value)) /
               Convert.ToInt32(numericUpDown3.Value) + 1;
                for (int n = Convert.ToInt32(numericUpDown1.Value); n <= Convert.ToInt32(numericUpDown2.Value); 
                n += Convert.ToInt32(numericUpDown3.Value))
                    {
                    int[] vptr = new int[n];
                    Random rand = new Random();
                    for (int j = 0; j < n; j++)
                    {
                       vptr[j] = rand.Next(Convert.ToInt32
                       (numericUpDown5.Value), Convert.ToInt32(numericUpDown4.
                       Value));
                    }
                    if (checkBox1.Checked)
                    {
                        dataGridView1.ColumnCount = n + 1;
                        dataGridView1.Rows.Add();
                        dataGridView1.Rows[i].Cells[0].Value = "Исходный массив";
                        for (int j = 0; j < n; j++)
                        {
                            dataGridView1.Rows[i].Cells[j +
                       1].Value = vptr[j];
                        }
                        i++;
                    }
                    sort(vptr, n);
                    current += 1;
                    progressBar1.Value = 100 * current / count;
                    }
        }
        private void sort(int[] p, int n)
        {
            int k = 0, sr = 0, obm = 0, m = 0;
            for (int j = 0; j < n; j++)
            {
                if (p[j] == 0) k++;
                else p[j - k] = p[j];
            }
            n -= k;
            sr += n;
            if (n == 0) { label8.Text = "В массиве одни нули"; return; }
            for (m = 0; m < n - 1; m++)
                for (int j = m + 1; j < n; j++)
                {
                    if (p[m] > 0 && p[j] > 0 && p[m] < p[j])
                    { swap(ref p[m], ref p[j]); obm++; }
                    if (p[m] < 0 && p[j] < 0 && p[m] > p[j])
                    { swap(ref p[m], ref p[j]); obm++; }
                    sr += 6;
                }
            if (checkBox1.Checked)
            {
                dataGridView1.AutoResizeColumns();
                dataGridView1.Rows.Add();
                dataGridView1.Rows[i].Cells[0].Value = "Получен массив";
                for (int j = 0; j < n; j++)
                {
                    dataGridView1.Rows[i].Cells[j + 1].Value =
               p[j];
                }
                i++;
            }
            if (Convert.ToInt32(numericUpDown1.Value) == Convert.ToInt32(numericUpDown2.Value))
            {
               label8.Text = "Количество сравнений=" +
               Convert.ToString(sr) + " Количество обменов=" +
               Convert.ToString(obm);
            }
            if (checkBox2.Checked)
            {
                chart1.Series[0].Points.AddXY(n, sr);
                chart2.Series[0].Points.AddXY(n, obm);
            }
        }

        void swap(ref int x, ref int y)
        { int z = x; x = y; y = z; }

        private void button2_Click(object sender, EventArgs e)
        {
            chart1.Series[0].Points.Clear();
            chart2.Series[0].Points.Clear();
            dataGridView1.Rows.Clear();
            dataGridView1.Columns.Clear();
            i = 0;
            button1.Enabled = true;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            dataGridView2.Rows.Clear();
            dataGridView2.Columns.Clear();
            dataGridView3.Rows.Clear();
            dataGridView3.Columns.Clear();
            button3.Enabled = true;
            label12.Text = "";
        }
        private int[,] DelRow(int[,] array, int row)
        {
            int[,] result = new int[array.GetLength(0) - 1, array.GetLength(1)];
            int x = 0;
            for (int i = 0; i < array.GetLength(0); i++)
            {
                if (i == row)
                {
                    row = -1;
                    continue;
                }

                for (int j = 0; j < array.GetLength(1); j++)
                {
                    result[x, j] = array[i, j];
                }
                x++;
            }
            return result;
        }
        

        private void button6_Click(object sender, EventArgs e)
        {
            if (numericUpDown10.Value <= numericUpDown7.Value)
            {
                label16.Text = "Макс значение не м.б. меньше мин значения!"; return;
            }
            int min = Convert.ToInt32(numericUpDown7.Value);
            int max = Convert.ToInt32(numericUpDown10.Value);
            int p;
            int[,] ptr;
            p = Convert.ToInt32(numericUpDown11.Value);
            ptr = new int[p, p];
            Random rand = new Random();
            dataGridView4.AutoResizeColumns();
            dataGridView4.ColumnCount = p;
            for (int i = 0; i < p; i++)
            {
                dataGridView4.Rows.Add();
                for (int j = 0; j < p; j++)
                {
                    ptr[i, j] = rand.Next(min,max);
                    dataGridView4.Rows[i].Cells[j].Value = ptr[i, j];
                }
            }
            bool f = false;
            while (f==false)
            {
                bool b = false;
                for (int i = 0; i < ptr.GetLength(0); i++)
                {

                    for (int j = p - 1; j > i; j--)
                    {
                        if (ptr[i, j] == 0)
                        {

                            ptr = DelRow(ptr, i);
                            i = 0;
                            b = true;
                            break;
                        }
                    }
                    if (b == true)
                        break;
                }
                if (b == false)
                    f = true;
            }
            dataGridView5.ColumnCount = p;
            for (int i = 0; i < ptr.GetLength(0); i++)
            {
                dataGridView5.Rows.Add();
                for (int j = 0; j < ptr.GetLength(1); j++)
                {
                    dataGridView5.Rows[i].Cells[j].Value = ptr[i, j];
                }
            }
            if (ptr.GetLength(0) > 2)
            {
                for (int j = 0; j < ptr.GetLength(1); j++)
                {
                    ptr[2, j] = ptr[0, j] - ptr[1, j];
                }
            }
            dataGridView6.ColumnCount = p;
            for (int i = 0; i < ptr.GetLength(0); i++)
            {
                dataGridView6.Rows.Add();
                for (int j = 0; j < ptr.GetLength(1); j++)
                {
                    dataGridView6.Rows[i].Cells[j].Value = ptr[i, j];
                }
            }

        }

        private void button5_Click(object sender, EventArgs e)
        {

            dataGridView4.Rows.Clear();
            dataGridView4.Columns.Clear();
            dataGridView5.Rows.Clear();
            dataGridView5.Columns.Clear();
            dataGridView6.Rows.Clear();
            dataGridView6.Columns.Clear();
            label16.Text = "";
        }

        private void button3_Click(object sender, EventArgs e)
        {

            int i, j, k, q;
            button3.Enabled = false;

            if (numericUpDown8.Value < numericUpDown9.Value)
            {
                label12.Text = "Макс значение не м.б. меньше мин значения!"; return;
            }

            n = Convert.ToInt32(numericUpDown6.Value);
            m = Convert.ToInt32(numericUpDown6.Value);
            int[,] ptr;
            ptr = new int[m, n];
            Random rand = new Random();
            dataGridView2.AutoResizeColumns();
            dataGridView2.ColumnCount = n;
            for (i = 0; i < n; i++)
            {
                dataGridView2.Rows.Add();
                for (j = 0; j < m; j++)
                {
                    ptr[i, j] =
                   rand.Next(Convert.ToInt32(numericUpDown9.Value),
                   Convert.ToInt32(numericUpDown8.Value));
                    dataGridView2.Rows[i].Cells[j].Value =
                   ptr[i, j];
                }
            }

            q = 0;
            k = 0;
            if (ptr[n - 1, m - 1] < 0) 
                k++;
            for (q = 0; q < n - 1; q++)

            {
                if (ptr[q, m - 1] < 0)
                {
                    k++;
                    for (i = q; i < n - 1; i++)
                    {
                        for (j = 0; j < m; j++) 
                                ptr[i, j] = ptr[i + 1, j];

                    }
                    q--;
                }
                if (k + q + 1 == n) { break; }
            }
            if (k == n)
            { label12.Text = "В матрице удалены все строки"; return; }
            if (k == 0) 
            { label12.Text = "В матрице нет удаленных строк"; return; }

            label12.Text = "В матрице удалено " + k + " строк(и)";

            for (j = 0; j < m; j++)
            {
                ptr[n - k, j] = 0;
                for (i = 0; i < n - k; i++)
                {
                    ptr[n - k, j] += ptr[i, j];
                }
            }

            dataGridView3.AutoResizeColumns();
            dataGridView3.ColumnCount = n;
            for (i = 0; i <= n - k; i++)
            {
                dataGridView3.Rows.Add();
                for (j = 0; j < m; j++)
                {
                    dataGridView3.Rows[i].Cells[j].Value = ptr[i, j];
                }
            }
        }
    }
}

