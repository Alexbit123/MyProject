#include "Menu.h"

using namespace std;

void menu(vector <sanatorium>& A, vector <client>& B)
{
	int k, fl = 1;
	cout << "������������! ��������� ��������� ��������� ������ �� ������." << endl;
	while (fl)
	{
		cout << "� ��� ������ ��������?\n 1-�������� � �����������\n 2-�������� � ���������\n 3-�������� �� � �����\n 0-��������� ���������\n";
		cin >> k;
		system("cls");
		switch (k)
		{
		case 0: fl = 0; break;
		case 1:
		{
			cout << "��� ��������� �������?\n 1-�������� ���������\n 2-������������� ���������\n 3-������� ���������\n 4-����� ���������\n 5-������� �� ����� ������ ���������\n 6-������� �� ����� �������� ���������\n";
			cin >> k;
			cin.ignore(255, '\n');
			switch (k)
			{
			case 1:
			{
				string san[4];
				sanatorium* A1 = new sanatorium;
				cout << "������� �������� ���������" << endl;
				getline(cin, san[0]);
				cout << "������� ����� ���������" << endl;
				getline(cin, san[1]);
				cout << "������� ��� ���������" << endl;
				getline(cin, san[2]);
				cout << "������� ���������� ���� � ���������" << endl;
				getline(cin, san[3]);
				A1->set(san[0], san[1], san[2], san[3]);
				A.push_back(*A1);
				cout << "��������� ��������!" << endl;
				break;
			}
			case 2:
			{
				string name_sanat;
				bool fl = 1;
				cout << "������� �������� ���������, ������� ������ �������������" << endl;
				getline(cin, name_sanat);
				for (int i = 0; i < A.size(); i++)
				{
					string san[4];
					if (A[i].search(name_sanat))
					{
						cout << "������� ����� ��� ���������" << endl;
						getline(cin, san[0]);
						cout << "������� ����� ����� ���������" << endl;
						getline(cin, san[1]);
						cout << "������� ����� ��� ���������" << endl;
						getline(cin, san[2]);
						cout << "������� ����� ���������� ���� � ���������" << endl;
						getline(cin, san[3]);
						for (int j = 0; j < B.size(); j++)
						{
							if (B[j].search_sanat() == A[i].search_sanat2())
							{
								A[i].del_client_in_sanat(B[j].search_sanat());
								B[j].edit_sanat(san[0]);
								A[i].add_client_in_sanat(B[j]);
							}
						}
						A[i].set(san[0], san[1], san[2], san[3]);
						cout << "��������� ��������������!" << endl;
						fl = 0;
					}
				}
				if (fl)
				{
					cout << "������ ��������� �� ����������!" << endl;
				}
				break;
			}
			case 3:
			{
				string name_sanat;
				bool fl = 1;
				cout << "������� �������� ���������, ������� ������ �������" << endl;
				getline(cin, name_sanat);
				for (int i = 0; i < A.size(); i++)
				{
					if (A[i].search(name_sanat))
					{
						for (int j = 0; j < B.size(); j++)
						{
							if (B[j].search_sanat() == A[i].search_sanat2())
							{
								B[j].del_edit_sanat();

							}
						}
						A[i].~sanatorium();
						A.erase(A.begin() + i);
						cout << "��������� ������!" << endl;
						fl = 0;
					}
				}
				if (fl)
				{
					cout << "������ ��������� �� ����������!" << endl;
				}
				break;
			}
			case 4:
			{
				string name_sanat;
				bool fl = 1;
				cout << "������� �������� ���������" << endl;
				getline(cin, name_sanat);
				for (int i = 0; i < A.size(); i++)
				{
					if (A[i].search(name_sanat))
					{
						cout << "������ ��������� ����������!" << endl;
						fl = 0;
					}
				}
				if (fl)
				{
					cout << "������ ��������� �� ����������!" << endl;
				}
				break;
			}
			case 5:
			{
				shapka_sanatorium();
				for (int i = 0; i < A.size(); i++)
				{
					A[i].print();
				}
				break;
			}
			case 6:
			{
				for (int i = 0; i < A.size(); i++)
				{
					A[i].print_client_in_sanatorium();
				}
				break;
			}
			default: cout << "������������ �����" << endl; break;
			}
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			cout << "��� ��������� �������?\n 1-�������� ����������\n 2-������������� ����������\n 3-������� ����������\n 4-����� ����������\n 5-������� �� ����� ������ �����������\n";
			cin >> k;
			cin.ignore(255, '\n');
			switch (k)
			{
			case 1:
			{
				string pos[6];
				client* B1 = new client;
				cout << "������� ��� ����������" << endl;
				cin >> pos[0];
				cout << "������� ������� ����������" << endl;
				cin >> pos[1];
				cout << "������� �������� ����������" << endl;
				cin >> pos[2];
				cout << "������� ������ �������� ��� ��������" << endl;
				cin >> pos[3];
				cout << "������� ����� �������� ��� ����, ������� � 8-��" << endl;
				cin >> pos[4];
				cin.ignore(255, '\n');
				cout << "������� �������� ���������, � �������� �������� ������" << endl;
				getline(cin, pos[5]);
				B1->set(pos[0], pos[1], pos[2], pos[3], pos[4], pos[5]);
				B.push_back(*B1);
				for (int i = 0; i < A.size(); i++)
				{
					if (A[i].search(B1->search_sanat()))
					{
						A[i].add_client_in_sanat(*B1);
					}
				}
				cout << "���������� ��������!" << endl;
				break;
			}
			case 2:
			{
				string pos[3];
				bool fl = 1;
				cout << "������� ���, ������� � �������� ����������, �������� ������ �������������" << endl;
				cout << "���: ";
				cin >> pos[0]; cout << endl;
				cout << "�������: ";
				cin >> pos[1]; cout << endl;
				cout << "��������: ";
				cin >> pos[2]; cout << endl;
				for (int i = 0; i < B.size(); i++)
				{
					string san[6];
					if (B[i].search(pos[0], pos[1], pos[2]))
					{
						for (int j = 0; j < A.size(); j++)
						{
							if (A[j].search(B[i].search_sanat()))
							{
								A[j].del_client_in_sanat(B[i].search_sanat());
							}
						}
						cout << "������� ����� ��� ����������" << endl;
						cin >> san[0];
						cout << "������� ����� ������� ����������" << endl;
						cin >> san[1];
						cout << "������� ����� ��������" << endl;
						cin >> san[2];
						cout << "������� ����� ������ �������� ��� ��������" << endl;
						cin >> san[3];
						cout << "������� ����� ����� �������� ��� ���� ������� � 8-��" << endl;
						cin >> san[4];
						cin.ignore(255, '\n');
						cout << "������� ����� �������� ���������, � �������� ����� �������� ������" << endl;
						getline(cin, san[5]);
						B[i].set(san[0], san[1], san[2], san[3], san[4], san[5]);
						for (int j = 0; j < A.size(); j++)
						{
							if (A[j].search(B[i].search_sanat()))
							{
								A[j].add_client_in_sanat(B[i]);
							}
						}
						cout << "���������� ��������������!" << endl;
						fl = 0;
					}
				}
				if (fl)
				{
					cout << "������ ���������� �� ����������!" << endl;
				}
				break;
			}
			case 3:
			{
				string pos[3];
				bool fl = 1;
				cout << "������� ���, ������� � �������� ����������, �������� ������ �������" << endl;
				cout << "���: ";
				cin >> pos[0]; cout << endl;
				cout << "�������: ";
				cin >> pos[1]; cout << endl;
				cout << "��������: ";
				cin >> pos[2]; cout << endl;
				for (int j = 0; j < B.size(); j++)
				{
					if (B[j].search(pos[0], pos[1], pos[2]))
					{
						for (int i = 0; i < A.size(); i++)
						{
							if (A[i].search(B[j].search_sanat()))
							{
								A[i].del_client_in_sanat(B[j].search_sanat());
							}
						}
						B[j].~client();
						B.erase(B.begin() + j);
						cout << "���������� ������!" << endl;
						fl = 0;
					}
				}
				if (fl)
				{
					cout << "������ ���������� �� ����������!" << endl;
				}
				break;
			}
			case 4:
			{
				string pos[3];
				bool fl = 1;
				cout << "������� ���, ������� � �������� ����������" << endl;
				cout << "���: ";
				cin >> pos[0];
				cout << "�������: ";
				cin >> pos[1];
				cout << "��������: ";
				cin >> pos[2];
				for (int i = 0; i < B.size(); i++)
				{
					if (B[i].search(pos[0], pos[1], pos[2]))
					{
						cout << "������ ���������� ����������!" << endl;
						fl = 0;
					}
				}
				if (fl)
				{
					cout << "������ ���������� �� ����������!" << endl;
				}
				break;
			}
			case 5:
			{
				shapka_client();
				for (int i = 0; i < B.size(); i++)
				{
					B[i].print();
				}
				break;
			}
			default: cout << "������������ �����" << endl; break;
			}
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			in_file(A, B);
			cout << "�� ������� �������� � �����" << endl;
			system("pause");
			system("cls");
			break;
		}
		default: cout << "������������ �����" << endl; system("pause"); system("cls"); break;
		}
	}
}