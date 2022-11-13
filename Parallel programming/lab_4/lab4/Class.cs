using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab4
{
    class Point
    {
        protected double x, y;
        public double pointX
        {
            get { return x; }
            set { x = value; }
        }
        public double pointY
        {
            get { return y; }
            set { y = value; }
        }
    }
    abstract class Circle : Point
    {
        public Circle(double X, double Y)
        { x = X; y = Y; }
        protected double radius;
        public double Rad
        {
            get { return radius; }
            set { radius = value; }
        }
        public abstract double volume();
        public abstract double squareFull();
        public double square()
        {
            return Math.PI * radius * radius;
        }
    }

    class Cylinder : Circle
    {
        public Cylinder(double X, double Y, double R)
        : base(X, Y)
        {
            radius = R;
        }
        double height;
        public double Hei
        {
            get { return height; }
            set { height = value; }
        }
        public override double volume()
        {
            return square() * height;
        }
        public override double squareFull()
        {
            return square() + 2 * Math.PI * radius * height;
        }
    }

    class Cone : Circle
    {
        public Cone(double X, double Y, double R)
        : base(X, Y)
        {
            radius = R;
        }
        double height;
        public double Hei
        {
            get { return height; }
            set { height = value; }
        }
        double squareSide()
        {
            return Math.PI * radius *
           Math.Sqrt(Math.Pow(radius, 2) + Math.Pow(height, 2));
        }
        public override double volume()
        {
            return square() * height * (1.0 / 3);
        }
        public override double squareFull()
        {
            return square() + squareSide();
        }
    }
}
