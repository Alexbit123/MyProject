#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include "ClassClient.h"
#include "ShapkaClient.h"

using namespace std;

class sanatorium
{
private:
	string name_sanat;
	string address_sanat;
	string code_sanat;
	string col_places_all;
	int col_client;
	vector <client> a;
public:
	sanatorium();
	sanatorium(string name_sanat, string address_sanat, string code_sanat, string col_places_all);

	void set(string name_sanat, string address_sanat, string code_sanat, string col_places_all);

	void add_client_in_sanat(client& x);

	void del_client_in_sanat(string x);

	bool search(string name_sanat);

	string search_sanat2();

	void print();

	void print_client_in_sanatorium();

	friend ostream& operator << (ostream& ost, sanatorium& san);

	~sanatorium();
};