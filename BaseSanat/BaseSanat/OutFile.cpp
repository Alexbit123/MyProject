#include "OutFile.h"

using namespace std;

void out_file(vector <sanatorium>& A, vector <client>& B)
{
	string line[6];
	ifstream in("Санатории.txt"); // открываем файл для чтения
	if (!in.is_open())
	{
		cout << "Файл Санатории не открылся\n";
		exit(1);
	}
	while (!in.eof())
	{
		getline(in, line[0]);
		if (line[0] == "")
		{
			break;
		}
		getline(in, line[1]);
		getline(in, line[2]);
		getline(in, line[3]);
		A.push_back(sanatorium(line[0], line[1], line[2], line[3]));
	}
	in.close();

	ifstream inn("Клиенты.txt"); // открываем файл для чтения
	if (!inn.is_open())
	{
		cout << "Файл Клиенты не открылся\n";
		exit(1);
	}
	while (!inn.eof())
	{
		getline(inn, line[0]);
		if (line[0] == "")
		{
			break;
		}
		getline(inn, line[1]);
		getline(inn, line[2]);
		getline(inn, line[3]);
		getline(inn, line[4]);
		getline(inn, line[5]);
		B.push_back(client(line[1], line[0], line[2], line[3], line[4], line[5]));
	}
	inn.close();

	for (int j = 0; j < B.size(); j++)
	{
		for (int i = 0; i < A.size(); i++)
		{
			if (A[i].search(B[j].search_sanat()))
			{
				A[i].add_client_in_sanat(B[j]);
			}
		}
	}


}