#include "Menu.h"

using namespace std;

void menu(vector <sanatorium>& A, vector <client>& B)
{
	int k, fl = 1;
	cout << "Здравствуйте! Программа загрузила начальные данные из файлов." << endl;
	while (fl)
	{
		cout << "С чем будете работать?\n 1-работать с санаториями\n 2-работать с клиентами\n 3-записать всё в файлы\n 0-завершить программу\n";
		cin >> k;
		system("cls");
		switch (k)
		{
		case 0: fl = 0; break;
		case 1:
		{
			cout << "Что требуется сделать?\n 1-добавить санаторий\n 2-редактировать санаторий\n 3-удалить санаторий\n 4-найти санаторий\n 5-вывести на экран данные санаторий\n 6-вывести на экран клиентов санаторий\n";
			cin >> k;
			cin.ignore(255, '\n');
			switch (k)
			{
			case 1:
			{
				string san[4];
				sanatorium* A1 = new sanatorium;
				cout << "Введите название санатория" << endl;
				getline(cin, san[0]);
				cout << "Введите адрес санатория" << endl;
				getline(cin, san[1]);
				cout << "Введите код санатория" << endl;
				getline(cin, san[2]);
				cout << "Введите количество мест в санатории" << endl;
				getline(cin, san[3]);
				A1->set(san[0], san[1], san[2], san[3]);
				A.push_back(*A1);
				cout << "Санаторий добавлен!" << endl;
				break;
			}
			case 2:
			{
				string name_sanat;
				bool fl = 1;
				cout << "Введите название санатория, который хотите редактировать" << endl;
				getline(cin, name_sanat);
				for (int i = 0; i < A.size(); i++)
				{
					string san[4];
					if (A[i].search(name_sanat))
					{
						cout << "Введите новое имя санатория" << endl;
						getline(cin, san[0]);
						cout << "Введите новый адрес санатория" << endl;
						getline(cin, san[1]);
						cout << "Введите новый код санатория" << endl;
						getline(cin, san[2]);
						cout << "Введите новое количество мест в санатории" << endl;
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
						cout << "Санаторий отредактирован!" << endl;
						fl = 0;
					}
				}
				if (fl)
				{
					cout << "Данный санаторий не существует!" << endl;
				}
				break;
			}
			case 3:
			{
				string name_sanat;
				bool fl = 1;
				cout << "Введите название санатория, который хотите удалить" << endl;
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
						cout << "Санаторий удален!" << endl;
						fl = 0;
					}
				}
				if (fl)
				{
					cout << "Данный санаторий не существует!" << endl;
				}
				break;
			}
			case 4:
			{
				string name_sanat;
				bool fl = 1;
				cout << "Введите название санатория" << endl;
				getline(cin, name_sanat);
				for (int i = 0; i < A.size(); i++)
				{
					if (A[i].search(name_sanat))
					{
						cout << "Данный санаторий существует!" << endl;
						fl = 0;
					}
				}
				if (fl)
				{
					cout << "Данный санаторий не существует!" << endl;
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
			default: cout << "Некорректный выбор" << endl; break;
			}
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			cout << "Что требуется сделать?\n 1-добавить посетителя\n 2-редактировать посетителя\n 3-удалить посетителя\n 4-найти посетителя\n 5-вывести на экран данные посетителей\n";
			cin >> k;
			cin.ignore(255, '\n');
			switch (k)
			{
			case 1:
			{
				string pos[6];
				client* B1 = new client;
				cout << "Введите имя посетителя" << endl;
				cin >> pos[0];
				cout << "Введите фамилию посетителя" << endl;
				cin >> pos[1];
				cout << "Введите отчество посетителя" << endl;
				cin >> pos[2];
				cout << "Введите данные паспорта без пробелов" << endl;
				cin >> pos[3];
				cout << "Введите номер телефона без тире, начиная с 8-ки" << endl;
				cin >> pos[4];
				cin.ignore(255, '\n');
				cout << "Введите название санатория, к которому закреплён клиент" << endl;
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
				cout << "Посетитель добавлен!" << endl;
				break;
			}
			case 2:
			{
				string pos[3];
				bool fl = 1;
				cout << "Введите имя, фамилию и отчество посетителя, которого будете редактировать" << endl;
				cout << "Имя: ";
				cin >> pos[0]; cout << endl;
				cout << "Фамилия: ";
				cin >> pos[1]; cout << endl;
				cout << "Отчество: ";
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
						cout << "Введите новое имя посетителя" << endl;
						cin >> san[0];
						cout << "Введите новую фамилию посетителя" << endl;
						cin >> san[1];
						cout << "Введите новое отчество" << endl;
						cin >> san[2];
						cout << "Введите новые данные паспорта без пробелов" << endl;
						cin >> san[3];
						cout << "Введите новый номер телефона без тире начиная с 8-ки" << endl;
						cin >> san[4];
						cin.ignore(255, '\n');
						cout << "Введите новое название санатория, к которому будет закреплён клиент" << endl;
						getline(cin, san[5]);
						B[i].set(san[0], san[1], san[2], san[3], san[4], san[5]);
						for (int j = 0; j < A.size(); j++)
						{
							if (A[j].search(B[i].search_sanat()))
							{
								A[j].add_client_in_sanat(B[i]);
							}
						}
						cout << "Посетитель отредактирован!" << endl;
						fl = 0;
					}
				}
				if (fl)
				{
					cout << "Данный посетитель не существует!" << endl;
				}
				break;
			}
			case 3:
			{
				string pos[3];
				bool fl = 1;
				cout << "Введите имя, фамилию и отчество посетителя, которого хотите удалить" << endl;
				cout << "Имя: ";
				cin >> pos[0]; cout << endl;
				cout << "Фамилия: ";
				cin >> pos[1]; cout << endl;
				cout << "Отчество: ";
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
						cout << "Посетитель удален!" << endl;
						fl = 0;
					}
				}
				if (fl)
				{
					cout << "Данный посетитель не существует!" << endl;
				}
				break;
			}
			case 4:
			{
				string pos[3];
				bool fl = 1;
				cout << "Введите имя, фамилию и отчество посетителя" << endl;
				cout << "Имя: ";
				cin >> pos[0];
				cout << "Фамилия: ";
				cin >> pos[1];
				cout << "Отчество: ";
				cin >> pos[2];
				for (int i = 0; i < B.size(); i++)
				{
					if (B[i].search(pos[0], pos[1], pos[2]))
					{
						cout << "Данный посетитель существует!" << endl;
						fl = 0;
					}
				}
				if (fl)
				{
					cout << "Данный посетитель не существует!" << endl;
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
			default: cout << "Некорректный выбор" << endl; break;
			}
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			in_file(A, B);
			cout << "Всё успешно записано в файлы" << endl;
			system("pause");
			system("cls");
			break;
		}
		default: cout << "Некорректный выбор" << endl; system("pause"); system("cls"); break;
		}
	}
}