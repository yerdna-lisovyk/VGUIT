using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab_3Dz
{
    struct Facultet
    {
        public string _title;
        public string _FIO;
        public string _telephone;
        public string _adress; 

        public Facultet(string t, string f, string p,string a)//конструктор
        {
            _title = t;
            _FIO = f;
            _telephone = p;
            _adress = a;
        }
    }
    public partial class Form1 : Form
    {
        Facultet[] facultets = new Facultet[10];
        int cout = 0;
        public Form1()
        {
            InitializeComponent();
        }

        private void groupBox2_Enter(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            facultets[cout]._title = textBox1.Text;
            facultets[cout]._FIO = textBox2.Text;
            facultets[cout]._telephone = maskedTextBox1.Text;
            facultets[cout]._adress = textBox3.Text;
            dataGridView1.Rows.Add(facultets[cout]._title, facultets[cout]._FIO,
                facultets[cout]._telephone, facultets[cout]._adress);
            cout++;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            dataGridView1.RowHeadersVisible = false;
            dataGridView1.ColumnCount = 4;
            dataGridView1.Columns[0].HeaderText = "Название факультета";
            dataGridView1.Columns[1].HeaderText = "ФИО декана";
            dataGridView1.Columns[2].HeaderText = "Телефон";
            dataGridView1.Columns[3].HeaderText = "Адрес";
            dataGridView2.RowHeadersVisible = false;
            dataGridView2.ColumnCount = 4;
            dataGridView2.Columns[0].HeaderText = "Название факультета";
            dataGridView2.Columns[1].HeaderText = "ФИО декана";
            dataGridView2.Columns[2].HeaderText = "Телефон";
            dataGridView2.Columns[3].HeaderText = "Адрес";
        }

        private void button2_Click(object sender, EventArgs e)
        {
            dataGridView2.Rows.Clear();
            string select = textBox4.Text;
            foreach(Facultet wSel in facultets)
            {
                if (wSel._title == select)
                {
                    dataGridView2.Rows.Add(wSel._title,wSel._FIO,wSel._telephone,wSel._adress);
                }
            }
        }
    }
}
