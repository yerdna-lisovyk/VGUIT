using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace lab4
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            button1.Enabled = false;
            double x1, y1, x2, y2, r2, x3, y3, r3, h3, x4, y4, r4, h4;
            x1 = Convert.ToDouble(textBox1.Text);
            y1 = Convert.ToDouble(textBox2.Text);
            x2 = Convert.ToDouble(textBox3.Text);
            y2 = Convert.ToDouble(textBox4.Text);
            r2 = Convert.ToDouble(textBox5.Text);
            x3 = Convert.ToDouble(textBox6.Text);
            y3 = Convert.ToDouble(textBox7.Text);
            r3 = Convert.ToDouble(textBox8.Text);
            h3 = Convert.ToDouble(textBox9.Text);
            x4 = Convert.ToDouble(textBox10.Text);
            y4 = Convert.ToDouble(textBox11.Text);
            r4 = Convert.ToDouble(textBox12.Text);
            h4 = Convert.ToDouble(textBox13.Text);
            Point tochka = new Point();
            tochka.pointX = x1;
            tochka.pointY = y1;
            textBox14.Text += "Точка" + Environment.NewLine;
            textBox14.Text += "x= " + tochka.pointX + "\t";
            textBox14.Text += "y= " + tochka.pointY +
           Environment.NewLine;
            textBox14.Text += Environment.NewLine +
           Environment.NewLine;
            textBox14.Text += "Круг" + Environment.NewLine;
            textBox14.Text += "Невозможно создать экземпляр абстрактного класса Circle " +Environment.NewLine;
            textBox14.Text += Environment.NewLine + Environment.NewLine;
            Cylinder roll = new Cylinder(x3, y3, r3);
            roll.Hei = h3;
            textBox14.Text += "Цилиндр" + Environment.NewLine;
            textBox14.Text += "x= " + roll.pointX + "\t";
            textBox14.Text += "x= " + roll.pointY + "\t";
            textBox14.Text += "r= " + roll.Rad + "\t";
            textBox14.Text += "h= " + roll.Hei + Environment.NewLine;
            textBox14.Text += "Площадь основания цилиндра = " + string.Format("{0:0.000}", roll.square()) + Environment.NewLine;
            textBox14.Text += "Объем цилиндра = " +
           string.Format("{0:0.000}", roll.volume()) + Environment.NewLine;
            textBox14.Text += "Площадь поверхности цилиндра = " + string.Format("{0:0.000}", roll.squareFull()) + Environment.NewLine;
            textBox14.Text += Environment.NewLine + Environment.NewLine;

            Cone bell = new Cone(x4, y4, r4);
            bell.Hei = h4;
            textBox14.Text += "Конус" + Environment.NewLine;
            textBox14.Text += "x= " + bell.pointX + "\t";
            textBox14.Text += "x= " + bell.pointY + "\t";
            textBox14.Text += "r= " + bell.Rad + "\t";
            textBox14.Text += "h= " + bell.Hei +
           Environment.NewLine;
            textBox14.Text += "Площадь основания конуса = "
           + string.Format("{0:0.000}", bell.square()) +
           Environment.NewLine;
            textBox14.Text += "Объем конуса = " +
           string.Format("{0:0.000}", bell.volume()) +
           Environment.NewLine;
            textBox14.Text += "Площадь поверхности конуса = " + string.Format("{0:0.000}", bell.squareFull()) +Environment.NewLine;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            textBox14.Clear();
            button1.Enabled = true;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}
