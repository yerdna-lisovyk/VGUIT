

#include <iostream>
using namespace std;
const int size_m = 5;
class op {

    struct pred {
        int id_dred;
        pred* next;
        pred() : next(NULL) {}
    };
    pred* head1;
    struct people {
        string fio;
        int kof;
        pred* id_pred[size_m];
        people* next;
        people() {
            next = NULL;
            kof = NULL;
            for (int i = 0; i < size_m; i++)
                id_pred[i] = NULL;
        }
    };
    people* head;
public:
    op() {
        head = NULL;
        head1 = NULL;
    }
    void open(int arr)
    {
        pred* tmp = new pred;
        tmp->id_dred = arr;
        tmp->next = head1;
        head1 = tmp;
       	tmp = nullptr;
    }
    void open(string arr,int a[],int k)
    {
        people* tmp = new people;
        tmp->fio = arr;
        if (head1 != NULL)
        {
            pred* p = head1;
            int m = 0;
            do {
                for (int i = 0; i < k; i++)
                {
                    if (p->id_dred == a[i])
                    {
                        tmp->id_pred[m++] = p;
                    }
                }
                p = p->next;
            } while (p != NULL);
            tmp->kof = 100 - (m * (100 / size_m));
        }
        tmp->next = head;
        head = tmp;
       
    }
    void pion()
    {
        people* p1 = head;
        people* p2 = head->next;
        people* tmp = new people;
        while (p1->next)
        {
            while (p2)
            {
                if (p1->kof > p2->kof)
                {
                    tmp->kof = p1->kof;
                    tmp->fio = p1->fio;
                    p1->kof = p2->kof;
                    p1->fio = p2->fio;
                    p2->kof = tmp->kof;
                    p2->fio = tmp->fio;
                }
                p2 = p2->next;
            }
            p1=p1->next;
            p2 = p1->next;
        }
       
    }
    void output()
    {
        people* tmp = head;
        do {
            cout << tmp->fio << " Вероятность шпиона : " << tmp->kof << endl;
            tmp = tmp->next;
        } while (tmp != NULL);
    }
};
int main()
{
    setlocale(LC_ALL, "Rus");
    op t1;
    t1.open(1);
    t1.open(2);
    t1.open(3);
    t1.open(4);
    t1.open(5);
    int a[3] = {1,2,3};
    t1.open("io", a, 3);
    int b[5] = { 1,2,3,4,5 };
    t1.open("po", b, 5);
    int c[5] = { 1,2,3,4,5 };
    t1.open("so", c, 0);
    t1.pion();
    t1.output();
}

