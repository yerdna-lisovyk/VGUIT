// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com



#include <iostream>
#include <vector>

enum class TypeСomponents { LIST, BUTTON, LINE, LEGEND, NO_TYPE };


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
    TypeСomponents Type;
public:
    GraphicСomponents() : id(0),Name(), Type(TypeСomponents::NO_TYPE){}
    void Setid(const int& newId) {  id= newId; }
    void SetName(const std::string& newName) { Name = newName; }
    void SetType(const TypeСomponents& newType) { Type = newType; }
    const int GetId() { return id; }
    const std::string GetName() { return Name; }
    const TypeСomponents GetType() { return Type; }
};

class Panel : public GraphicСomponents {
private:
    int id;
    std::string Name;
    std::vector<GraphicСomponents> ListСomponents;
public:
    Panel() : id(0),Name(),ListСomponents(NULL){}
    void Setid(const int& newId) { id = newId; }
    void SetName(const std::string& newName) { Name = newName; }
    const int GetId() { return id; }
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
};


class Window : public Panel, public GraphicСomponents {
private:
    std::string Name;
    std::vector<GraphicСomponents> ListСomponents;
    std::vector<Panel> ListPanels;
public:
    Window(std::string newName) : Name(newName), ListСomponents(NULL), ListPanels(NULL) {}
    void SetName(const std::string& newName) { Name = newName; }
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
    void CreateWindow()
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
    void Output()
    {
        std::cout<< Name << std::endl;
        for (int i = 0; i < ListСomponents.size(); i++)
        {
            std::cout <<"    "<< ListСomponents[i].GetName()<<" "<< ListСomponents[i].GetId()<< std::endl;
        }
        
        for (int i = 0; i < ListPanels.size(); i++)
        {
            std::vector<GraphicСomponents> tmp = ListPanels[i].GetListСomponents();
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
    Window t1("Окно");
    t1.CreateWindow();
    t1.Output();
    return 0;
}

