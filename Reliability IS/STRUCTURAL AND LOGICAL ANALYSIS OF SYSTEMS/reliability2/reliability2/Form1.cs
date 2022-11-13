using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace reliability2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            double[] P = new double[8] {0.93,0.98,0.94, 0.94, 0.92, 0.93, 0.98, 0.89 };

            double P_B1 = P[0]*P[1];    
            label1.Text = "P_B1 = " + P_B1.ToString();
            double P_B2 = 1 - (1 - P[4]) * (1 - P[5]);
            label2.Text = "P_B2 = " + P_B2.ToString();
            double P_B3 = P[3] *P_B2;
            label3.Text = "P_B3 = " + P_B3.ToString();
            double P_C1 = 1-(1-P_B1)*(1- P_B3);
            label4.Text = "P_C1 = " + P_C1.ToString();

            double P_C2 = 1 - (1 - P[2]) * (1 - P[6]) * (1 - P[7]);
            label5.Text = "P_C2 = " + P_C2.ToString();

            double P_A = P_C1 * P_C2;
            label6.Text = "P_A = " + P_A.ToString();


            double[] alfa = new double[8];

            for(int i = 0; i < 8; i++)
            {
                alfa[i] = -Math.Log(P[i]);
            }
            double alfa_B1 = alfa[0] + alfa[1];
            double alfa_B3 = (1 / ((1 / alfa[4]) + (1 / alfa[5]) - (1 / (alfa[4] + alfa[5])))) + alfa[3];
            double alfa_C1 = 1 / (1 / alfa_B1) + (1 / alfa_B3) - (1 / (alfa_B1 + alfa_B3));
            label7.Text = "alfa_C1 = " + alfa_C1.ToString();
            double alfa_C2 = 1 / ((1 / alfa[2]) + (1 / alfa[6]) + (1 / alfa[7]) - (1 / (alfa[2] + alfa[6] + alfa[7])));
            label8.Text = "alfa_C2 = " + alfa_C2.ToString();

            double alfa_B1_C2 = alfa_B1 + alfa_C2;

            double T_B1 = alfa[0] + alfa[1];
            double T_B3 = ((1 / alfa[4]) + (1 / alfa[5]) - (1 / (alfa[4] + alfa[5]))) + alfa[3];
            double T_C1 = (1 / alfa_B1) + (1 / alfa_B3) - (1 / (alfa_B1 + alfa_B3));
            double T_C2 = ((1 / alfa[2]) + (1 / alfa[6]) + (1 / alfa[7]) - (1 / (alfa[2] + alfa[6] + alfa[7])));

            
            double T_A = 1 / alfa_B1_C2;
            label10.Text = "T_A = " + T_A.ToString();
            double alfa_a = 1 / T_A;
            label11.Text = "alfa_a = " + alfa_a.ToString();



        }
    }
}
