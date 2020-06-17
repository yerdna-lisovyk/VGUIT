
#include <iostream>

#include "windows.h"
#include <iostream>
using namespace std;


double w[] = { 1,2,3,4,5,6,7,8,9,10,0.5,0.5 };

bool podbor(double wes, int candidate)
{
	if (wes == 0) return true;		//решение найдено
	if (wes < 0 || candidate == sizeof(w) / sizeof(double)) // решение НЕ найдено: или ранец ПЕРЕполнен    //или все варианты испробованы.
		return false;
	if (podbor(wes - w[candidate], candidate + 1))
	{
		cout << w[candidate] << endl;
		return true;
	}
	else 				//решение без candidate
	{
		return podbor(wes, candidate + 1);
	}
}



int main()
{
	setlocale(0, "Rus"); 				
	if (!podbor(20, 0))
	cout << " решения нет \n ";		
	return 0;
}
