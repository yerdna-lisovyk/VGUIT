#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;
class book {
    int id_book;
    string initials;
    string book_name;
    int id_genre;
    int kol;
    int out;
    book* next;
public:
    bool open(book * &head, book* &end)
    {
     ifstream file("Lib.txt");
        if (!file)
        {
            cout << "File not found\n";
            return 1;
        }
        book* tmp = new book;
        file >> tmp->id_book;
        file >> tmp->initials;
        file >> tmp->book_name;
        file >> tmp->id_genre;
        file >> tmp->kol;
        file >> tmp->out;
        tmp->next = head;
        if (head == NULL)
        {
            end = tmp;
            head = tmp;
        }
        else
        {
            head = tmp;
        }
    }
    void close(book* head, book* end)
    {
        std::ofstream out;
        out.open("Lib.txt");
        book* p = head;
        do {
            out << p->id_book << " ";
            out << p->initials << " ";
            out << p->book_name << " ";
            out << p->id_genre << " ";
            out << p->kol << " ";
            out << p->out << " ";
            p = p->next;
        } while (p != end->next);
        
    }
    void output(book* head, book* end)
    {
        book* p = head;
        do {
            cout << "№УДК: " << p->id_book << endl;
            cout << "Автор: " << p->initials << endl;
            cout << "Название: " << p->book_name << endl;
            cout << "Жанр: " << func(p->id_genre) << endl;
            cout << "Осталось книг: " << p->kol << endl;
            cout << "Выданно книг: " << p->out << endl;
            cout << endl;
            p = p->next;
        } while (p != end->next);
        cout << endl;
    }
    string func(int a)
    {
        switch (a)
        {
            case 1: {return "Фантастика"; break; }
            case 2: {return "Драмма"; break; }
            case 3: {return "Биография"; break; }
        }
    }
    void output_book(book* head, book* end)
    {
        cout << "Названия: "<<endl;
        book* p = head;
        do {
            cout << p->book_name << endl;
            p = p->next;
        } while (p != end->next);
        cout<< endl;
    }
    void issued(book* head, book* end)
    {
        cout << "Выданно больше половины" << endl;
        book* p = head;
        do {
            if (p->out > ((p->kol + p->out) / 2))
            {
                    cout << "Автор: " << p->initials << endl;
                    cout << "Название: " << p->book_name << endl;
                    cout << "Жанр: " << func(p->id_genre) << endl;
                    cout << "Осталось книг: " << p->kol << endl;
                    cout << endl;
            }
            p = p->next;
        } while (p != end->next);
    }

};
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    book* head = NULL, *end = NULL;
    book t1;
    if (t1.open(head,end) == 1)
    {
        return 1;
    }
    int a=0;
    while (a != 4)
    {
        cout << "1.Формирование данных обо всех книгах в библиотеке в виде списка"<<endl;
        cout << "2.Печать списка кник" << endl;
        cout << "3.Вывод списка книг, у которых в настоящий момент выдано больше половины существующих экземпляров." << endl;
        cout << "4.Выход." << endl;
        cout << "Ваш выбор : "; cin >> a;
        system("cls");
        switch (a)
        {
        case 1: {
            
            t1.output(head, end); break;
            }
        case 2: {
     
            t1.output_book(head, end); break;
        }
        case 3: {
            t1.issued(head, end); break;
        }
        }
    }

    t1.close(head, end);
    delete head;
    delete end;
    return 0;
}


