#include "ClassClient.h"

client::client() = default;

client::client(string Name, string Surname, string Otchname, string Passport_Data, string Phone_Number, string Name_Sanatorium) :name_client(Name) , surname_client(Surname), otchname_client(Otchname), passport_data(Passport_Data), phone_number(Phone_Number), name_sanatorium(Name_Sanatorium) {};

void client::set(string Name, string Surname, string Otchname, string Passport_Data, string Phone_Number, string Name_Sanatorium)
{
	name_client = Name;
	surname_client = Surname;
	otchname_client = Otchname;
	passport_data = Passport_Data;
	phone_number = Phone_Number;
	name_sanatorium = Name_Sanatorium;
};

bool client::search(string Name, string Surname, string Otchname)
{
	if (name_client == Name && surname_client == Surname && otchname_client == Otchname)
	{
		return 1;
	}
	else return 0;
};

string client::search_sanat()
{
	return name_sanatorium;
}

void client::edit_sanat(string NewName)
{
	name_sanatorium = NewName;
}

void client::del_edit_sanat()
{
	name_sanatorium = "";
}

void client::print()
{
	printf("%-20s%-20s%-20s%-20s%-20s%-20s\n\n", surname_client.c_str(), name_client.c_str(), otchname_client.c_str(), passport_data.c_str(), phone_number.c_str(), name_sanatorium.c_str());
}

ostream& operator << (ostream& ost, client& san)
{
	return ost << san.surname_client << endl << san.name_client << endl << san.otchname_client << endl << san.passport_data << endl << san.phone_number << endl << san.name_sanatorium << endl;
}

client::~client() = default;