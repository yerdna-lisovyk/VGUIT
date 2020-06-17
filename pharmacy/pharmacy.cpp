

#include <iostream>
using namespace std;
class medicine {
    string name;
    int prise;
    int number_tablets;
public:
    medicine(string a, int b, int c)// конструктор класса medicine
    {
        name = a;
        prise = b;
        number_tablets = c;
    }
    string get_name()//Возвращение названия
    {
        return name;
    }
    int get_prise()//Возвращение цены
    {
        return prise;
    }
    int get_number_tablets()//Возвращение колличества таблеток
    {
        return number_tablets;
    }
};
class purshase : public medicine // производный class
{
    int number_packages;
    int sum;
public :
    purshase(string a,int b,int c,int k) : medicine(a,b,c)// конструктор класса purshase вызывает конструктор класса medicine
    {
        number_packages = k;//Количество покупки
        sum = b * k;//Cумма покупки
    }
    int get_number_packages()//Возвращение количества покупки
    {
        return number_packages;
    }
    int get_sum()// возвращение суммы
    {
        return sum;
    }
};
class Check : public purshase // производный class
{
public:
    Check(string a, int b, int c, int k) :purshase(a, b, c, k)// конструктор класса Check вызывает конструктор класса purshase
    {
        cout << "Препарат:  "<<endl << purshase::get_name();// вызов методов базового класса которые он наследует или которые являются его собственными 
        cout << ", 1 уп, " << purshase::get_number_tablets();
        cout << ", " << purshase::get_prise() << "руб" << endl;
        cout << endl;
        cout << "Всего купленно: " << purshase::get_number_packages() <<" шт."<< endl;
        cout << "На сумму : " << purshase::get_sum() << " шт." << endl;
    }

};
int main()
{
    setlocale(LC_ALL, "Rus");
    Check F("Нурофен", 100, 20, 3);//Создание производного класса
    return 0;
}
