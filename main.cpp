#include "header.h"

void main()
{
	int i = 0;
	int ch;
	setlocale(LC_ALL, "RUS");
	system("chcp 1251");
	string nom;
	string temp;
	try{
		storage *store = new storage[100];

		try{
			file my("file.txt");
			char choice, choice1;
			if (my.OPEN() != 0)
			{
				while (1)
				{
					cout << "1.�������� ������ � ����" << endl;
					cout << "2.�������� ������ �� �����" << endl;
					cout << "3.������� ������" << endl;
					cout << "4.������������� ������" << endl;
					cout << "5.�����" << endl;
					cout << "��� �����: ";
					choice = _getch();
					cout << endl;
					switch (choice)
					{
					case '1':
						my.ADD();
						system("pause");
						system("cls");
						break;
					case '2':
						my.DISPLAY(store, my.READ(store));
						system("pause");
						system("cls");
						break;
					case '3':
						try{
							cout << "������� ����������������� ����� ��� ��������: ";
							cin.sync();
							getline(cin, nom);
							//check_nom(nom);
						}
						catch (...)
						{
							cout << "������������ ����" << endl;
							system("pause");
							system("cls");
							break;
						};
						my.DEL(nom, store, my.READ(store));
						system("pause");
						system("cls");
						break;
					case '4':
						try{
							cout << "������� ����������������� ����� ��� ��������������: ";
							cin.sync();
							cin >> temp;
							//check_nom(temp);
							cin.sync();
						}
						catch (...)
						{
							cout << "������������ ����" << endl;
							system("pause");
							system("cls");
							break;
						}
						cout << "�������������: " << endl;
						cout << "1.��������" << endl;
						cout << "2.����������" << endl;
						cout << "3.���������" << endl;
						cout << "4.�����" << endl;
						cout << "5.����� � ������� ����" << endl;
						cout << "��� �����: ";
						choice1 = _getch();
						system("cls");
						cin.sync();
						if (choice1 == '1', '2', '3', '4')
						{
							ch = my.READ(store);
							if (ch != 0 && ch != -1)
							{
								my.EDIT(temp, choice1, store, ch);
							}
						}
						else cout << "������ �����" << endl;
						system("pause");
						system("cls");
						break;
					case '5':
						delete store;
						return;
					default:
						system("cls");
						cout << "�������� �����!" << endl;
						system("pause");
						system("cls");
					}
				}
			}
			else
			{
				cout << "������ �������� �����" << endl;
				system("pause");
				return;
			}
		}
		catch (FileNotOpenException e)
		{
			cout << e.what() << endl;
		};
	}
	catch (bad_alloc exept)
	{
		cout << "�������� ���������� " << exept.what() << endl;
		return;
	}
}

