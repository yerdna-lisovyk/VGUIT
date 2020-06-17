// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com


#include <iostream>
#include <Windows.h>
using namespace std;
struct BinTree {
    int value; //содержит значение
    BinTree* left;//адрес левого поддерева
    BinTree* right;//адрес правого поддерева
    BinTree():value(0),left(nullptr),right(nullptr){}
};
void newBinOpen(int val, BinTree*& Tree) {
    if (Tree == nullptr)
    {
        Tree = new BinTree; //Выделить память
        Tree->value = val;  //Поместить в выделенное место аргумент
        return;
    }
    if (val >Tree->value) newBinOpen(val, Tree->right);//Если аргумент больше чем текущий элемент, поместить его вправо
    else newBinOpen(val, Tree->left);//Иначе поместить его влево
}
void Print(BinTree* Tree, int l)
{
    
    if (Tree != nullptr)
    {
        Print(Tree->right, l + 1);
        for (int i = 1; i <= l; i++) cout << "   ";
        cout << Tree->value << endl;
        Print(Tree->left, l + 1);
    }
}
int main()
{
    setlocale(LC_ALL, "Rus");
    BinTree* Tree = nullptr;
    int a[] = { 10,5,35,1,20,99,4,17,31 };// изначальный массив
    for (int i = 0; i < sizeof(a) / sizeof(int); i++)
    {
        cout << a[i] << " ";
    }
    cout << " - начальный массив\nБинарное дерево:(c права на лево)" << endl;
    for(int i = 0; i < sizeof(a) / sizeof(int); i++)
    {
        newBinOpen(a[i], Tree);
    }
    Print(Tree, 0);
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    return 0;
}


