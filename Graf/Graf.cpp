// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <iostream>
#include <Windows.h>

using namespace std;
class Graf {
    struct Ribs {
        int top; //Вершина смежного ребра
        Ribs* next;//адрес cледующеющей вершин ребра
        Ribs(int p) : next(nullptr) {
            top = p;
 
        }
    };
    struct Top {
        int top; //вершина
        Top* next;//адрес cледующей вершины
        Ribs* adjacency;// список ребер
        Top() :top(0), next(nullptr),adjacency(nullptr) {}
    };
    Top* head;
public:
    Graf() : head(nullptr){}
    void record(const int a[])
    {
        for (int j = 0; j < 2; j++)
        {
            Top* tmp = head;
            while (tmp)
            {
                if (tmp->top == a[j])
                {

                    Ribs* tmp1;//запись ребер
                    if(j==0)// если первое число значит приписываем связь со вторым или на оборот
                        tmp1 = new Ribs(a[j+1]);
                    else
                        tmp1 = new Ribs(a[j -1]);
                    tmp1->next = tmp->adjacency;
                    tmp->adjacency = tmp1;
                    clean(tmp1);
                    break;

                }
                tmp = tmp->next;
            }
            clean(tmp);
        }
    }

    void creatTop(int a)//создание всех вершин
    {
     Top* tmp = head;
     while (tmp)
     {

         if (tmp->top == a)
         {
             return;// если вершина существует то пропускаем её
         }
         tmp = tmp->next;
     }
     clean(tmp);
     Top* tmp1 = new Top;
     tmp1->top = a;
     tmp1->next = head;
     head = tmp1;
     clean(tmp1);
     
    }
    void output()//вывод 
    {
        Top* tmp = head;
        while (tmp)
        {
            cout << "Вершина " << tmp->top<<" Смежна с : ";
            Ribs* tmp1 = tmp->adjacency;
            int k = 0;
            while(tmp1)
            {
                cout << tmp1->top<<" ; ";
                tmp1 = tmp1->next;
                k++;// подсчет степени 
            }
            cout << "Степень : " << k;
            tmp = tmp->next;
            cout << endl;
        }
        clean(tmp);
    }
    template <class T>
    void clean(T& tmp)// удаление временных переменных из памяти
    {
        tmp = nullptr;
        delete tmp;
    }
};

int main()
{
    setlocale(LC_ALL, "Rus");
    const int n = 7;
    const int m[n][2] = { { 1, 2}, // матрица GRAF
                           { 1, 3 },
                            { 2, 3},
                            { 3, 4},
                            { 4, 1},
                            { 5, 1},
                            { 4, 2}
    };

    Graf t1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
        {
            t1.creatTop(m[i][j]);
        }
    
   for(int i = 0;i<n;i++)
           {
               t1.record(m[i]);
           }
   t1.output();
   return 0;
}


