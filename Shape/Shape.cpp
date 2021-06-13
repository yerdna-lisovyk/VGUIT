#include <iostream>
#include <math.h>
#define M_PI 3.14159265358979323846

using namespace std;

class shape {
    int x1, y1,x2,y2;
public:
    shape(int x1_, int y1_,int x2_, int y2_) : x1(x1_), y1(y1_),x2(x2_),y2(y2_)
    {}
    virtual void show()
    {
        cout << "kord: (" << x1 << ", " << y1 << " "<< x2 << ", " << y2 << ")";
    }
    virtual int area() = 0;
    virtual int perimeter() = 0;
};
class circle : public shape {
    int r;
public:
    circle(int x1_, int y1_, int x2_, int y2_) : shape(x1_, y1_,x2_,y2_)
    {
        r= sqrt(pow((x2_ - x1_), 2) + pow((y2_ - y1_), 2));
    }
    void show() {
        cout << "circle! ";
        shape::show();
        cout << " r: " << r;
    }
    int area() {
        return M_PI*pow(r,2);
    }
    int perimeter() {
        return 2*M_PI * r;
    }

};
class square : public shape {
    int side;
public:
    square(int x1_, int y1_, int x2_, int y2_) : shape(x1_, y1_, x2_, y2_)
    {
        side = sqrt(pow((x2_ - x1_), 2) + pow((y2_ - y1_), 2));
    }
    void show() {
        cout << "square! ";
        shape::show();
        cout << " side: " << side;
    }
    int area() {
        return side * side;
    }
    int perimeter() {
        return 4 * side;
    }

};
int main() {

    int x1, y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    square first(x1, y1, x2, y2);
    circle second(x1, y1, x2, y2);
    shape* data[] = { &first,&second };
    for(int i=0;i<2;i++)
    {
        data[i]->show();
        cout << " ares:" << data[i]->area() << " perimeter:" << data[i]->perimeter() << endl;
    }
    return 0;
}