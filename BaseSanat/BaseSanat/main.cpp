#include "ClassClient.h"
#include "ClassSanatorium.h"
#include "OutFile.h"
#include "Menu.h"
#include <windows.h>
#include <vector>

void main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	vector <client> B;
	vector <sanatorium> A;


	out_file(A, B);

	menu(A, B);

}