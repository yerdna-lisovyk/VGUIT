// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com



#include <iostream>
#include <vector>

enum class Type—omponents { LIST, BUTTON, LINE, LEGEND, NO_TYPE };


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
    Type—omponents Type;
public:
    Graphic—omponents() : id(0),Name(), Type(Type—omponents::NO_TYPE){}
    void Setid(const int& newId) {  id= newId; }
    void SetName(const std::string& newName) { Name = newName; }
    void SetType(const Type—omponents& newType) { Type = newType; }
    const int GetId() { return id; }
    const std::string GetName() { return Name; }
    const Type—omponents GetType() { return Type; }
};

class Panel : public Graphic—omponents {
private:
    int id;
    std::string Name;
    std::vector<Graphic—omponents> List—omponents;
public:
    Panel() : id(0),Name(),List—omponents(NULL){}
    void Setid(const int& newId) { id = newId; }
    void SetName(const std::string& newName) { Name = newName; }
    const int GetId() { return id; }
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
};


class Window : public Panel, public Graphic—omponents {
private:
    std::string Name;
    std::vector<Graphic—omponents> List—omponents;
    std::vector<Panel> ListPanels;
public:
    Window(std::string newName) : Name(newName), List—omponents(NULL), ListPanels(NULL) {}
    void SetName(const std::string& newName) { Name = newName; }
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
    void CreateWindow()
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
    void Output()
    {
        std::cout<< Name << std::endl;
        for (int i = 0; i < List—omponents.size(); i++)
        {
            std::cout <<"    "<< List—omponents[i].GetName()<<" "<< List—omponents[i].GetId()<< std::endl;
        }
        
        for (int i = 0; i < ListPanels.size(); i++)
        {
            std::vector<Graphic—omponents> tmp = ListPanels[i].GetList—omponents();
            std::cout <<"    "<< ListPanels[i].GetName() << " " << ListPanels[i].GetId() << std::endl;
            for (int i = 0; i < tmp.size(); i++)
            {
                std::cout << "       " << tmp[i].GetName() << " " << tmp[i].GetId() << std::endl;
            }
        }
    }
};

int main()
{
    setlocale(LC_ALL, "Rus");
    Window t1("ŒÍÌÓ");
    t1.CreateWindow();
    t1.Output();
    return 0;
}

