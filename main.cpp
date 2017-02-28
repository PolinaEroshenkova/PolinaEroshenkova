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
					cout << "1.Добавить данные в файл" << endl;
					cout << "2.Просмотр данных из файла" << endl;
					cout << "3.Удалить запись" << endl;
					cout << "4.Редактировать данные" << endl;
					cout << "5.Выход" << endl;
					cout << "Ваш выбор: ";
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
							cout << "Введите идентификационный номер для удаления: ";
							cin.sync();
							getline(cin, nom);
							//check_nom(nom);
						}
						catch (...)
						{
							cout << "Некорректный ввод" << endl;
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
							cout << "Введите идентификационный номер для редактирования: ";
							cin.sync();
							cin >> temp;
							//check_nom(temp);
							cin.sync();
						}
						catch (...)
						{
							cout << "Некорректный ввод" << endl;
							system("pause");
							system("cls");
							break;
						}
						cout << "Редактировать: " << endl;
						cout << "1.Название" << endl;
						cout << "2.Количество" << endl;
						cout << "3.Стоимость" << endl;
						cout << "4.Номер" << endl;
						cout << "5.Выход в главное меню" << endl;
						cout << "Ваш выбор: ";
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
						else cout << "Ошибка ввода" << endl;
						system("pause");
						system("cls");
						break;
					case '5':
						delete store;
						return;
					default:
						system("cls");
						cout << "Неверный выбор!" << endl;
						system("pause");
						system("cls");
					}
				}
			}
			else
			{
				cout << "Ошибка открытия файла" << endl;
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
		cout << "Возникло исключение " << exept.what() << endl;
		return;
	}
}

