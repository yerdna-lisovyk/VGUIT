// Jabka.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
enum class Direction // перечисление направлений
{
    right,
    bottom,
    left,
    top
};
using namespace std;
bool vivod(bool **B,int n,int m, const pair<int,int> Cord) // функция проверки клеток вокруг лягушки
{
    if ((Cord.first + 1 >= n || B[Cord.first + 1][Cord.second] != true) &&
        (Cord.second + 1 >= m || B[Cord.first][Cord.second + 1] != true) &&
        (Cord.second - 1 < 0 || B[Cord.first][Cord.second - 1] != true) &&
        (Cord.first - 1 < 0 || B[Cord.first - 1][Cord.second] != true))
    {
        return true;
    }
    return false;
}
int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(0));
    int n, m;
    cout << "Введите количество строк в массиве : ";
    cin >> n;
    cout << "Введите количество столбцов в массиве : ";
    cin >> m;
    int** A = new int* [n];// создает массив пути лягушки
    bool** B = new bool* [n];// создает массив c бабочками
    for (int i = 0; i < n; i++)
    {
        A[i] = new int[m];
    }
    for (int i = 0; i < n; i++)
    {
        B[i] = new bool[m];
    }

    for (int i = 0; i < n; i++)// обнуление матрицы с бабочками
    {
        for (int j = 0; j < m; j++)
        {
            B[i][j] = 0;
        }
        
    }
    for (int i = 0; i < n; i++)// обнуление матрицы с бабочками
    {
        for (int j = 0; j < m; j++)
        {
            A[i][j] = 0;
        }

    }

    for (int i = 0; i <= n; i++)//Раставление бабочек
    {
        int tmpi = (rand() % n + 1)-1;
        int tmpj = (rand() % n+1)-1;
        if (B[tmpi][tmpj] == true&&(tmpi==0&&tmpj==0))
        {
            i--;
        }
        else
        {
           B[tmpi][tmpj] = true;
        }
    }
    cout << endl;
    cout << "Растановка бабочек" << endl;
    for (int i = 0; i < n; i++)//вывод матрицы с бабочками
    {
        for (int j = 0; j < m; j++)
        {
            cout.width(3);
            cout << B[i][j];
        }
        cout << endl;
    }
    pair<int, int> Cord = { 0,0 };// пара преставляющая кординаты лягушки 
    A[Cord.first][Cord.second] = 1;
    Direction direction = Direction::right;// направление лягушки
    int way = 2;
    while ((vivod(B, n, m, Cord) ==false))//если бабочек нет вокрук то прекращаем движение
    {
        switch (direction) //действия при разных направлениях лягушки
        {
            case Direction::right: {
                if (Cord.second + 1 >= m || B[Cord.first][Cord.second+1]!=true)//есди впереди ничего нет то меняем направление
                {
                    direction = Direction::bottom;
                }
                else
                {
                    Cord.second += 1;// движение вперед если впереди есть бабочка
                    B[Cord.first][Cord.second] = false; //бабочку съели
                    A[Cord.first][Cord.second] = way;// отметка в маршруте
                    way++;// следующий номер маршрута 
                }
                break;
            }

            case Direction::bottom: {
                if (Cord.first+ 1 >= n || B[Cord.first+1][Cord.second] != true)
                {
                    direction = Direction::left;
                }
                else
                {
                    Cord.first += 1;
                    B[Cord.first][Cord.second] = false;
                    A[Cord.first][Cord.second] = way;
                    way++;
                }
                break;
            }

            case Direction::left: {
                if (Cord.second - 1 < 0 || B[Cord.first][Cord.second - 1] != true)
                {
                    direction = Direction::top;
                }
                else
                {
                    Cord.second -= 1;
                    B[Cord.first][Cord.second] = false;
                    A[Cord.first][Cord.second] = way;
                    way++;
                }
                break;
            }

            case Direction::top: {
                if (Cord.first - 1 < 0  || B[Cord.first - 1][Cord.second] != true)
                {
                    direction = Direction::right;
                }
                else
                {
                    Cord.first -= 1;
                    B[Cord.first][Cord.second] = false;
                    A[Cord.first][Cord.second] = way;
                    way++;
                }
                break;
            }

        }
        
    }
    cout << endl;
    cout << "Движение лягушки" << endl;
    for (int i = 0; i < n; i++)//вывод матрицы с бабочками
    {
        for (int j = 0; j < m; j++)
        {
            cout.width(3);
            cout << A[i][j];
        }
        cout << endl;
    }
    return 0;
}


