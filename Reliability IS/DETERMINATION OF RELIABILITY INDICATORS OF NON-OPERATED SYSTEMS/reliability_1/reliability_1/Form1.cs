using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace reliability_1
{
    public partial class Form1 : Form
    {
        private double _exp1 = 0.01;
        private double _G1 = 7, _G2 = 55;
        private double _W1 = 3, _W2 = 990;
        private double _R = 15 * Math.Pow(10, -8);
        private double _exp2 = 0.035;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //exp
            double start_exp1_m_q = 1 / _exp1;
            double start_exp2_m_q = 1 / _exp2;
            //G
            double start_g_m = (_G1 + _G2);
            double start_g_q = (_G2 - _G1) / (2 * Math.Sqrt(3));
            //W
            double start_w_m = _W2 * SpecialFunction.gamma(1+1/_W1);
            double start_w_q = _W2 * Math.Sqrt(SpecialFunction.gamma(1+2/_W2)-Math.Pow(SpecialFunction.gamma(1+1/_W2),2));
            //R
            double start_r_m = Math.Sqrt(Math.PI / (4 * _R));
            double start_r_q = Math.Sqrt((4 - Math.PI) / (4 * _R));


            double[] Alfa_exp1= new double[31];
            //exp1
            for (int t = 0; t <= 3000; t += 100)
            {
                double f_t_exp1 = _exp1 * Math.Exp(-_exp1 * t);
                chart1.Series[0].Points.AddXY(t, f_t_exp1);
                chart1.Series[0].Name = "f_t_exp1";
                double p_t_exp1 = Math.Exp(-_exp1 * t);
                chart2.Series[0].Points.AddXY(t, p_t_exp1);
                chart2.Series[0].Name = "p_t_exp1";
                Alfa_exp1[t / 100] = f_t_exp1 / p_t_exp1;
            }
            //exp2
            double[] Alfa_exp2 = new double[31];
            for (int t = 0; t <= 3000; t += 100)
            {
                double f_t_exp2 = _exp2 * Math.Exp(-_exp2 * t);
                chart3.Series[0].Points.AddXY(t, f_t_exp2);
                chart3.Series[0].Name = "f_t_exp2";
                double p_t_exp2 = Math.Exp(-_exp2 * t);
                chart4.Series[0].Points.AddXY(t, p_t_exp2);
                chart4.Series[0].Name = "p_t_exp2";
                Alfa_exp2[t / 100] = f_t_exp2 / p_t_exp2;
            }
            //G
            double[] Alfa_G = new double[31];
            for (int t = 0; t <= 3000; t += 100)
            {
                double f_t_G = Math.Pow(t, _G1 - 1) / (Math.Pow(_G2, _G1)*SpecialFunction.gamma(_G1)) *Math.Exp(-t/_G2);
                chart5.Series[0].Points.AddXY(t, f_t_G);
                chart5.Series[0].Name = "f_t_G";
                double p_t_G = 1-SpecialFunction.igam(_G1,t/_G2);
                chart6.Series[0].Points.AddXY(t, p_t_G);
                chart6.Series[0].Name = "p_t_G";
                Alfa_exp1[t / 100] = f_t_G / p_t_G;
            }
            //W
            double[] Alfa_W = new double[31];
            for (int t = 0; t <= 3000; t += 100)
            {
                double f_t_W = (_W1*Math.Pow(t,_W1-1))/Math.Pow(_W2,_W1) *Math.Exp(-Math.Pow(t/_W2,_W1));
                chart7.Series[0].Points.AddXY(t, f_t_W);
                chart7.Series[0].Name = "f_t_W";
                double p_t_G = Math.Exp(-Math.Pow(t / _W2, _W1));
                chart8.Series[0].Points.AddXY(t, p_t_G);
                chart8.Series[0].Name = "p_t_G";
                Alfa_W[t / 100] = f_t_W / p_t_G;
            }
            //R
            double[] Alfa_R = new double[31];
            for(int t = 0; t <= 3000;t+=100)
            {
                double f_t_R = 2 * _R * t * Math.Exp(-_R * t * t);
                chart9.Series[0].Points.AddXY(t, f_t_R);
                chart9.Series[0].Name = "f_t_R";
                double p_t_R = Math.Exp(-_R * t * t);
                chart10.Series[0].Points.AddXY(t, p_t_R);
                chart10.Series[0].Name = "p_t_R";
                Alfa_R[t / 100] = f_t_R / p_t_R;
            }
            double[] Alfa_sum = new double[31];
            for (int i = 0; i < 31; i ++)
            {
                Alfa_sum[i] = 0;
                Alfa_sum[i] = Alfa_exp1[i] + Alfa_exp2[i] + Alfa_G[i] + Alfa_R[i] + Alfa_W[i];
                chart11.Series[0].Points.AddXY(i*100, Alfa_sum[i]);
                chart11.Series[0].Name = "Alfa_sum";
            }
        }


    }
}
