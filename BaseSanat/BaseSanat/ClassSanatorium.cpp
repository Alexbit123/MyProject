#include "ClassSanatorium.h"

sanatorium::sanatorium() = default;

sanatorium::sanatorium(string name_sanat, string address_sanat, string code_sanat, string col_places_all) : name_sanat(name_sanat), address_sanat(address_sanat), code_sanat(code_sanat), col_places_all(col_places_all), col_client(a.size()) {};

void sanatorium::set(string name_sanat, string address_sanat, string code_sanat, string col_places_all)
{
	this->name_sanat = name_sanat;
	this->address_sanat = address_sanat;
	this->code_sanat = code_sanat;
	this->col_places_all = col_places_all;
	col_client = a.size();
};

void sanatorium::add_client_in_sanat(client& x)
{
	a.push_back(x);
	col_client = a.size();
};

void sanatorium::del_client_in_sanat(string x)
{
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i].search_sanat() == x)
		{
			a.erase(a.begin() + i);
		}
	}
	col_client = a.size();
};

bool sanatorium::search(string name_sanat)
{
	if (this->name_sanat == name_sanat)
	{
		return 1;
	}
	else return 0;
};

string sanatorium::search_sanat2()
{
	return name_sanat;
};

void sanatorium::print()
{
	printf("%-25s%-25s%-25s%-25s%-25d\n", name_sanat.c_str(), address_sanat.c_str(), code_sanat.c_str(), col_places_all.c_str(), col_client);
}

void sanatorium::print_client_in_sanatorium()
{
	cout << name_sanat << endl;
	shapka_client();
	for (int i = 0; i < a.size(); i++)
	{
		a[i].print();
	}
}

ostream& operator << (ostream& ost, sanatorium& san)
{
	return ost << san.name_sanat << endl << san.address_sanat << endl << san.code_sanat << endl << san.col_places_all << endl << san.col_client << endl;
}

sanatorium::~sanatorium() = default;