
#include <iostream>
#include <string> 
#include <ctime>
using namespace std;

template <typename T>
void ListOutput(T* head)
{
	if (head == nullptr)
		return;
	T* tmp = head;
	do {
		cout << "--- " << tmp->name << endl;
		tmp = tmp->next;
	} while (tmp);
}

template <typename T>
void ListCreate(T*& head, string newName)
{
	T* tmp = new T(newName);
	tmp->next = head;
	head = tmp;
}

class GraphicСomponents
{
private:
	struct Legend {
		string name;
		bool Hidden;
		Legend* next;
		Legend(string newName) : name(newName), Hidden(false), next(nullptr) {}
	};
	struct List {
		string name;
		bool Hidden;
		List* next;
		List(string newName) : name(newName), Hidden(false), next(nullptr) {}
	};
	struct Button {
		string name;
		bool Hidden;
		Button* next;
		Button(string newName) : name(newName), Hidden(false), next(nullptr) {}
	};
	struct Line {
		string name;
		bool Hidden;
		Line* next;
		Line(string newName) : name(newName), Hidden(false), next(nullptr) {}
	};
	struct Panel {
		string name;
		bool Hidden;
		Line* headLine;
		Button* headButton;
		List* headList;
		Legend* headLegend;
		Panel* next;
		Panel(string newName) :name(newName), Hidden(false), next(nullptr),
			headLine(nullptr), headButton(nullptr), headList(nullptr), headLegend(nullptr) {}
	};
	struct Window {
		string name;
		bool Hidden;
		Panel* headPenel;
		Line* headLine;
		Button* headButton;
		List* headList;
		Legend* headLegend;
		Window() :name(""), Hidden(false), headLine(nullptr), headButton(nullptr), headList(nullptr), headLegend(nullptr), headPenel(nullptr) {}
	};

	Window** Matrix;
	int size;
public:
	GraphicСomponents(int SizeOfMatrix) :size(SizeOfMatrix)
	{
		Matrix = new Window * [SizeOfMatrix];
		for (int i = 0; i < SizeOfMatrix; i++)
		{
			Matrix[i] = new Window[SizeOfMatrix];
		}

	}
	void Create()
	{
		for (int i = 0; i < size; i++)
		{
			Matrix[i]->name = "Окно "+ to_string(i+1);
			for (int j = 0; j < rand() % 4 + 1; j++)
			{
				ListCreate(Matrix[i]->headButton, "Конопка "+to_string(j+1));
			}
			for (int j = 0; j < rand() % 4 + 1; j++)
			{
				ListCreate(Matrix[i]->headLegend, "Текст " + to_string(j+1));
			}
			for (int j = 0; j < rand() % 4 + 1; j++)
			{
				ListCreate(Matrix[i]->headLine, "Линия " + to_string(j+1));
			}
			for (int j = 0; j < rand() % 4 + 1; j++)
			{
				ListCreate(Matrix[i]->headList, "Список " + to_string(j+1));
			}
			for (int j = 0; j < rand() % 4 + 1; j++)
			{
				ListCreate(Matrix[i]->headPenel, "Панель " + to_string(j+1));
				for (int j = 0; j < rand() % 4 + 1; j++)
				{
					ListCreate(Matrix[i]->headPenel->headButton, "Конопка " + to_string(j + 1));
				}
				for (int j = 0; j < rand() % 4 + 1; j++)
				{
					ListCreate(Matrix[i]->headPenel->headLegend, "Текст " + to_string(j + 1));
				}
				for (int j = 0; j < rand() % 4 + 1; j++)
				{
					ListCreate(Matrix[i]->headPenel->headLine, "Линия " + to_string(j + 1));
				}
				for (int j = 0; j < rand() % 4 + 1; j++)
				{
					ListCreate(Matrix[i]->headPenel->headList, "Список " + to_string(j + 1));
				}
			}
		}

	}
	void Output()
	{
		if (Matrix[0] == nullptr)
			return;
		for (int i = 0; i < size; i++)
		{
			if (!Matrix[i]->Hidden)
			{
				cout << "------| " << Matrix[i]->name << endl;
				OutputPanel(Matrix[i]->headPenel);
				ListOutput(Matrix[i]->headButton);
				ListOutput(Matrix[i]->headLine);
				ListOutput(Matrix[i]->headList);
				ListOutput(Matrix[i]->headLegend);
			}
			
		}
	}
	void OutputPanel(Panel* headPanel)
	{
		if (headPanel == nullptr)
			return;
		Panel* tmp = headPanel;
		do {
			cout << "----| " << tmp->name << endl;
			ListOutput(headPanel->headButton);
			ListOutput(headPanel->headLine);
			ListOutput(headPanel->headList);
			ListOutput(headPanel->headLegend);
			tmp = tmp->next;
			cout << "------| " << endl;
		} while (tmp);
		
	}
	~GraphicСomponents()
	{
		for (int i = 0; i < size; i++)
		{
			delete[](Matrix[i]);
		}
		delete[](Matrix);
	}



};

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	GraphicСomponents t(1);
	t.Create();
	t.Output();
	return 0;
}


