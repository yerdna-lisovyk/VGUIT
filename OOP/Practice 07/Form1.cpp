#include "Form1.h"

using namespace Project6;
using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
int main(array<System::String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Form1());
	return 0;
}


