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

namespace reliability3
{
    public partial class Form1 : Form
    {
        const int N = 1000, t = 100, delta_t = 10;
        int[] n = new int[10] { 78,101,14,26,138,65,8,15,73,86};

        private void chart2_Click(object sender, EventArgs e)
        {

        }

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            double sum=0;
            for (int i = 0; i < 10; i++)
            {
                sum += n[i]; 
            }
            double[] P = new double[10];
            for(int i = 0; i < 10; i++)
            {
                P[i] = n[i] / sum;
                chart1.Series[0].Points.AddXY(i+1, P[i]);
                chart1.Series[0].Name = "P";
            }
            double[] Q = new double[10];
            Q[0] = P[0];
            for( int i = 1; i < 10; i++)
            {
                Q[i] = P[i] + Q[i-1];
                chart2.Series[0].Points.AddXY(i + 1, Q[i]);
                chart2.Series[0].Name = "Q";
            }
            double[] P_t = new double[10];
            for (int i = 0; i < 10; i++)
            {
                P_t[i] = 1 - Q[i];
                chart3.Series[0].Points.AddXY(i + 1, P_t[i]);
                chart3.Series[0].Name = "P_t";
            }
            double[] f_t = new double[10];
            for (int i = 0; i < 10; i++)
            {
                f_t[i] = P_t[i] / delta_t;
                chart4.Series[0].Points.AddXY(i + 1, f_t[i]);
                chart4.Series[0].Name = "f_t";
            }
            double[] Lamda_t = new double[10];
            for(int i = 0; i < 10; i++)
            {
                Lamda_t[i] = n[i] / ((sum - n[i]) * delta_t);
                chart5.Series[0].Points.AddXY(i + 1, Lamda_t[i]);
                chart5.Series[0].Name = "Lamda_t";
            }
            double T0 = 0;
            for (int i = 0; i < 10; i++)
            {
                T0 += (i + 1) * delta_t * P_t[i];
            }
            label1.Text = T0.ToString();
            double D = 0;
            for (int i = 0; i < 10; i++)
            {
                D += Math.Pow(((i + 1) * delta_t * -T0), 2) * P_t[i];
            }
            label2.Text = D.ToString();
        }
    }
}
