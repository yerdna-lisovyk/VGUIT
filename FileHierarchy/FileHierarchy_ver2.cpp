// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com



#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <windows.h>

enum class TypeСomponents { LIST, BUTTON, LINE, LEGEND, NO_TYPE,PANEL };

enum class Query
{
    HIDE_SHOW,
    OUTPUT,
    OUTPUT_HIDENS,
    EXIT
};

std::istream& operator >> (std::istream& is, Query& q)
{
    int operation;
    std::cout << "1.Скрыт/показать обьект" << std::endl;
    std::cout << "2.Вывод" << std::endl;
    std::cout << "3.Вывод скрытых обьектов" << std::endl;
    std::cout << "4.Выход." << std::endl;
    std::cout << "Ваш выбор : "; is >> operation;
    switch (operation)
    {
    case 1: {
        q = Query::HIDE_SHOW;
        break;
    }
    case 2: {
        q = Query::OUTPUT;
        break; }
    case 3: {
        q = Query::OUTPUT_HIDENS;
        break;
    }
    case 4: {
        q = Query::EXIT;
        break;
    }
    }
    return is;
}
std::string ReturnName(TypeСomponents type)
{
    switch (type)
    {
    case TypeСomponents::LIST:
        return "Список";
    case TypeСomponents::BUTTON:
        return "Конпка";
    case TypeСomponents::LINE:
        return "Линия";
    case TypeСomponents::LEGEND:
        return "Надпись";
    }
}

class GraphicСomponents {
private:
    int id;
    std::string Name;
    bool visible;
    TypeСomponents Type;
public:
    GraphicСomponents() : id(0),Name(), visible(1), Type(TypeСomponents::NO_TYPE){}
    void Setid(const int& newId) {  id= newId; }
    void SetName(const std::string& newName) { Name = newName; }
    void SetType(const TypeСomponents& newType) { Type = newType; }
    const int GetId() { return id; }
    const bool GetVisible() { return visible; }
    const std::string GetName() { return Name; }
    const TypeСomponents GetType() { return Type; }
    void HideShow()
    {
        if (visible)
            visible = 0;
        else
            visible = 1;
    }
};

class Panel : public GraphicСomponents {
private:
    int id;
    bool visible;
    std::string Name;
    std::vector<GraphicСomponents> ListСomponents;
public:
    Panel() : id(0),Name(),visible(1),ListСomponents(NULL){}
    void Setid(const int& newId) { id = newId; }
    void SetName(const std::string& newName) { Name = newName; }
    const int GetId() { return id; }
    const bool GetVisible() { return visible; }
    const std::string GetName() { return Name; }
    std::vector<GraphicСomponents> GetListСomponents() { return ListСomponents; }
    void AddСomponents(int newId, TypeСomponents type)
    {
        GraphicСomponents tmp;
        tmp.Setid(newId);
        tmp.SetName(ReturnName(type));
        tmp.SetType(type);
        ListСomponents.push_back(tmp);
    }
    void HideShow()
    {
        if (visible)
            visible = 0;
        else
            visible = 1;
    }
};


class Window : public Panel, public GraphicСomponents {
private:
    std::string Name;
    bool visible;
    std::vector<GraphicСomponents> ListСomponents;
    std::vector<Panel> ListPanels;
public:
    Window(std::string newName) : Name(newName),visible(1), ListСomponents(NULL), ListPanels(NULL) {}
    void SetName(const std::string& newName) { Name = newName; }
    const bool GetVisible() { return visible; }
    void AddСomponents(int newId, TypeСomponents type)
    {
        GraphicСomponents tmp;
        tmp.Setid(newId);
        tmp.SetName(ReturnName(type));
        tmp.SetType(type);
        ListСomponents.push_back(tmp);
    }
    void AddPanel(std::string newName, int newId)
    {
        Panel tmp;
        tmp.Setid(newId);
        tmp.SetName(newName);
        ListPanels.push_back(tmp);
    }
    void HideShow()
    {
        if (visible)
            visible = 0;
        else
            visible = 1;
    }
    void CreateWindowClass()
    {
        AddСomponents(1, TypeСomponents::BUTTON);
        AddСomponents(2, TypeСomponents::BUTTON);
        AddСomponents(3, TypeСomponents::BUTTON);
        AddСomponents(1, TypeСomponents::LINE);
        AddСomponents(1, TypeСomponents::LIST);
        AddPanel("Панель", 1);
        ListPanels[0].AddСomponents(1, TypeСomponents::BUTTON);
        ListPanels[0].AddСomponents(1, TypeСomponents::LIST);
        ListPanels[0].AddСomponents(1, TypeСomponents::LINE);
    }
    void Output(bool showHiden)
    {
        if (!visible && !showHiden)
        {
            return;
        }
        std::cout<< Name << std::endl;
        for (int i = 0; i < ListСomponents.size(); i++)
        {
            if(ListСomponents[i].GetVisible()|| showHiden)
                std::cout <<"    "<< ListСomponents[i].GetName()<<" "<< ListСomponents[i].GetId()<< std::endl;
        }
        
        for (int i = 0; i < ListPanels.size(); i++)
        {
            if (ListPanels[i].GetVisible() || showHiden)
            {
                std::vector<GraphicСomponents> tmp = ListPanels[i].GetListСomponents();
                std::cout << "    " << ListPanels[i].GetName() << " " << ListPanels[i].GetId() << std::endl;
                for (int j = 0; j < tmp.size(); j++)
                {
                    if (tmp[j].GetVisible() || showHiden)
                        std::cout << "       " << tmp[j].GetName() << " " << tmp[j].GetId() << std::endl;
                }
            }
        }
    }
    void SerthObject(std::string nameObject)
    {
        if (nameObject == Name)
        {
            HideShow();
            return;
        }
        for (int i = 0; i < ListСomponents.size(); i++)
        {
            std::string fullName = ListСomponents[i].GetName()+" " + std::to_string(ListСomponents[i].GetId());
            if (fullName == nameObject)
            {
                ListСomponents[i].HideShow();
                return;
            }
        }
        for (int i = 0; i < ListPanels.size(); i++)
        {
            std::string fullName = ListPanels[i].GetName() + " " + std::to_string(ListPanels[i].GetId());
            if (fullName == nameObject)
            {
                ListPanels[i].HideShow();
                return;
            }
            std::vector<GraphicСomponents> tmp = ListPanels[i].GetListСomponents();
            for (int j = 0; j < tmp.size(); j++)
            {
                tmp[j].HideShow();
                return;
            }

        }
        std::cout << "------ Ошибка 1 : ничего не найденно ------"<<std::endl;
    }
};



int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Window t1("Окно");
    t1.CreateWindowClass();
    t1.Output(0);

    Query q;
    while (std::cin >> q)
    {
        switch (q)
        {
            case Query::HIDE_SHOW:{
                std::string nameObject;
                std::cout << "Что скрыть : ";
                std::cin.ignore();
                getline(std::cin, nameObject);
                t1.SerthObject(nameObject);
                break;
            }
            case Query::OUTPUT: {
                t1.Output(0);
                break;
            }
            case Query::OUTPUT_HIDENS: {
                t1.Output(1);
                break;
            }
            case Query::EXIT: {
                return 0;
            }
        }
    }
}

