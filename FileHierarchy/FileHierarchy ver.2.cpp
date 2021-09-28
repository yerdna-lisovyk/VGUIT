// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com



#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <windows.h>

enum class Type—omponents { LIST, BUTTON, LINE, LEGEND, NO_TYPE,PANEL };

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
    std::cout << "1.—Í˚Ú/ÔÓÍ‡Á‡Ú¸ Ó·¸ÂÍÚ" << std::endl;
    std::cout << "2.¬˚‚Ó‰" << std::endl;
    std::cout << "3.¬˚‚Ó‰ ÒÍ˚Ú˚ı Ó·¸ÂÍÚÓ‚" << std::endl;
    std::cout << "4.¬˚ıÓ‰." << std::endl;
    std::cout << "¬‡¯ ‚˚·Ó : "; is >> operation;
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
std::string ReturnName(Type—omponents type)
{
    switch (type)
    {
    case Type—omponents::LIST:
        return "—ÔËÒÓÍ";
    case Type—omponents::BUTTON:
        return " ÓÌÔÍ‡";
    case Type—omponents::LINE:
        return "ÀËÌËˇ";
    case Type—omponents::LEGEND:
        return "Õ‡‰ÔËÒ¸";
    }
}

class Graphic—omponents {
private:
    int id;
    std::string Name;
    bool visible;
    Type—omponents Type;
public:
    Graphic—omponents() : id(0),Name(), visible(1), Type(Type—omponents::NO_TYPE){}
    void Setid(const int& newId) {  id= newId; }
    void SetName(const std::string& newName) { Name = newName; }
    void SetType(const Type—omponents& newType) { Type = newType; }
    const int GetId() { return id; }
    const bool GetVisible() { return visible; }
    const std::string GetName() { return Name; }
    const Type—omponents GetType() { return Type; }
    void HideShow()
    {
        if (visible)
            visible = 0;
        else
            visible = 1;
    }
};

class Panel : public Graphic—omponents {
private:
    int id;
    bool visible;
    std::string Name;
    std::vector<Graphic—omponents> List—omponents;
public:
    Panel() : id(0),Name(),visible(1),List—omponents(NULL){}
    void Setid(const int& newId) { id = newId; }
    void SetName(const std::string& newName) { Name = newName; }
    const int GetId() { return id; }
    const bool GetVisible() { return visible; }
    const std::string GetName() { return Name; }
    std::vector<Graphic—omponents> GetList—omponents() { return List—omponents; }
    void Add—omponents(int newId, Type—omponents type)
    {
        Graphic—omponents tmp;
        tmp.Setid(newId);
        tmp.SetName(ReturnName(type));
        tmp.SetType(type);
        List—omponents.push_back(tmp);
    }
    void HideShow()
    {
        if (visible)
            visible = 0;
        else
            visible = 1;
    }
};


class Window : public Panel, public Graphic—omponents {
private:
    std::string Name;
    bool visible;
    std::vector<Graphic—omponents> List—omponents;
    std::vector<Panel> ListPanels;
public:
    Window(std::string newName) : Name(newName),visible(1), List—omponents(NULL), ListPanels(NULL) {}
    void SetName(const std::string& newName) { Name = newName; }
    const bool GetVisible() { return visible; }
    void Add—omponents(int newId, Type—omponents type)
    {
        Graphic—omponents tmp;
        tmp.Setid(newId);
        tmp.SetName(ReturnName(type));
        tmp.SetType(type);
        List—omponents.push_back(tmp);
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
        Add—omponents(1, Type—omponents::BUTTON);
        Add—omponents(2, Type—omponents::BUTTON);
        Add—omponents(3, Type—omponents::BUTTON);
        Add—omponents(1, Type—omponents::LINE);
        Add—omponents(1, Type—omponents::LIST);
        AddPanel("œ‡ÌÂÎ¸", 1);
        ListPanels[0].Add—omponents(1, Type—omponents::BUTTON);
        ListPanels[0].Add—omponents(1, Type—omponents::LIST);
        ListPanels[0].Add—omponents(1, Type—omponents::LINE);
    }
    void Output(bool showHiden)
    {
        if (!visible && !showHiden)
        {
            return;
        }
        std::cout<< Name << std::endl;
        for (int i = 0; i < List—omponents.size(); i++)
        {
            if(List—omponents[i].GetVisible()|| showHiden)
                std::cout <<"    "<< List—omponents[i].GetName()<<" "<< List—omponents[i].GetId()<< std::endl;
        }
        
        for (int i = 0; i < ListPanels.size(); i++)
        {
            if (ListPanels[i].GetVisible() || showHiden)
            {
                std::vector<Graphic—omponents> tmp = ListPanels[i].GetList—omponents();
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
        for (int i = 0; i < List—omponents.size(); i++)
        {
            std::string fullName = List—omponents[i].GetName()+" " + std::to_string(List—omponents[i].GetId());
            if (fullName == nameObject)
            {
                List—omponents[i].HideShow();
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
            std::vector<Graphic—omponents> tmp = ListPanels[i].GetList—omponents();
            for (int j = 0; j < tmp.size(); j++)
            {
                tmp[j].HideShow();
                return;
            }

        }
        std::cout << "------ Œ¯Ë·Í‡ 1 : ÌË˜Â„Ó ÌÂ Ì‡È‰ÂÌÌÓ ------"<<std::endl;
    }
};



int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Window t1("ŒÍÌÓ");
    t1.CreateWindowClass();
    t1.Output(0);

    Query q;
    while (std::cin >> q)
    {
        switch (q)
        {
            case Query::HIDE_SHOW:{
                std::string nameObject;
                std::cout << "◊ÚÓ ÒÍ˚Ú¸ : ";
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

