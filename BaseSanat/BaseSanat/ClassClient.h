#pragma once
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class client
{
private:
	string name_client;
	string surname_client;
	string otchname_client;
	string passport_data;
	string phone_number;
	string name_sanatorium;
public:
	client();
	client(string Name, string Surname, string Otchname, string Passport_Data, string Phone_Number, string Name_Sanatorium);

	void set(string Name, string Surname, string Otchname, string Passport_Data, string Phone_Number, string Name_Sanatorium);

	bool search(string Name, string Surname, string Otchname);

	string search_sanat();

	void edit_sanat(string NewName);

	void del_edit_sanat();

	void print();

	friend ostream& operator << (ostream& ost, client& san);

	~client();
};
