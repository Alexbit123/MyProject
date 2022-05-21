#include "InFile.h"

void in_file(vector <sanatorium> A, vector <client> B)
{
	ofstream out("Санатории новое.txt");

	if (!out.is_open())
	{
		cout << "Файл Санатории не открылся\n";
		exit(1);
	}

	for (int i = 0; i < A.size(); i++)
	{
		out << A[i];
	}

	out.close();

	ofstream outt("Клиенты новое.txt");

	if (!outt.is_open())
	{
		cout << "Файл клиенты новое не открылся\n";
		exit(1);
	}

	for (int i = 0; i < B.size(); i++)
	{
		outt << B[i];
	}

	outt.close();

}