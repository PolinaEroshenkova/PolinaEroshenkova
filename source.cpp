#include "header.h"

file::file(string filn)
{
	filename = filn;
	fstream f(filename);
	if (!f) throw FileNotOpenException();
}
file::~file()
{
	f.close();
}
int file::OPEN()
{
	f.open(filename, ios::app);
	f.close();
	return 1;
}
void file::DISPLAY(storage *store,int i)
{
	system("cls");
	for (int j = 0; j < i; j++)
	{
		cout << "������ �" << j+1 << endl;
		cout << "������������ �������: " << store[j].GetName() << endl;
		cout << "����� ����������: " << store[j].GetAmount() << endl;
		cout << "��������� �� �����: " << store[j].GetCost() << endl;
		cout << "����������������� �����: " << store[j].GetNumber() << endl << endl;
	}
}
int check(string temp)
{
	int k = 0;
	unsigned int j;
	for (j = 0; j < temp.length(); j++)
	{
		if ((temp[j] >= 32 && temp[j] <= 47) || (temp[j] >= 58)) return 0;
		else k++;
	}
	if (k == j) { return 1; }
	else return -1;
}
void file::ADD()
{
	string name;
	string amount;
	string cost;
	string number;
	cout << "������� ������������ �������: ";
	cin.sync();
	getline(cin, name);
	try{
		cout << "������� ���������� �������: ";
		cin.sync();
		getline(cin, amount);
		check_nom(amount);
	}
	catch (InputException e)
	{
		cout << e.what() << endl;
		return;
	}
	try{
		cout << "������� ��������� ������ �������: ";
		cin.sync();
		getline(cin, cost);
		check_nom(cost);
	}
	catch (InputException e)
	{
		cout << e.what() << endl;
		return;
	}
	try{
		cout << "������� ����������������� ����� �������: ";
		cin.sync();
		getline(cin, number);
		check_nom(number);
	}
	catch (InputException e)
	{
		cout << e.what() << endl;
		return;
	}
	f.open(filename, ios::app);
	f << name << " " << amount << " " << cost << " " << number << endl;
	f.flush();
	f.clear();
	f.close();
	cout << "��������� �������" << endl;
}
void file::DEL(string temp, storage *store,int i)
{
	int j = i;
	int k = -1;
	for (i = 0; i < j; i++)
	{
		if (store[i].GetNumber() == atoi(temp.c_str()))
		{
			k = i;
		}
	}
	if (k != -1)
	{
		f.open(filename, ios::out);
		for (i = 0; i < k; i++)
			f << store[i].GetName() << " " << store[i].GetAmount() << " " << store[i].GetCost() << " " << store[i].GetNumber() << endl;
		for (i = k + 1; i < j;i++)
			f << store[i].GetName() << " " << store[i].GetAmount() << " " << store[i].GetCost() << " " << store[i].GetNumber() << endl;
		f.close();
		cout << "��������� �������" << endl;
	}
	else cout << "������� �� ������" << endl;
}
void file::EDIT(string nom, char choice, storage *store,int i)
{
	int j = i;
	string tmp;
	int k = 0;
	cout << "������� ����� ����: ";
	if (choice == '1')
	{
		cin.sync();
		getline(cin, tmp);
	}
	else 
	{ 
		try{
			cin.sync();
			getline(cin, tmp);
			check_nom(tmp);
		}
		catch (...)
		{
			cout << "������������ ����" << endl;
			return;
		}
	}

	for (i = 0; i < j;i++)
		if (store[i].GetNumber() == atoi(nom.c_str()))
		{
		k++;
		switch (choice)
		{
		case '1':
			store[i].SetName(tmp);
			break;
		case '2':
			store[i].SetAmount(atoi(tmp.c_str()));
			break;
		case '3':
			store[i].SetCost(atoi(tmp.c_str()));
			break;
		case '4':
			store[i].SetNumber(atoi(tmp.c_str()));
			break;
		default: return;
		}
	}
	try{
		if (k != i) throw 1;
	}
	catch (int)
	{
		cout << "������ ����������� ����� �� ����������" << endl;
		return;
	}
	f.open(filename, ios::out);
	for (i = 0; i < j; i++)
		f << store[i].GetName() << " " << store[i].GetAmount() << " " << store[i].GetCost() << " " << store[i].GetNumber() << endl;
	f.close();
	cout << "��������� �������" << endl;
}
int file::READ(storage *store)
{
	int i = 0;
	int size=0;
	f.open(filename, ios_base::in);
	f.seekg(0,ios_base::end);
	size = f.tellg();
	try{
		if (size!=0)
		{
			if (!f.fail())
			{
				int tmp;
				string temp;
				f.seekg(0, ios_base::beg);
				while (f.eof()==0)
				{
					f >> temp;
					if (f.eof()==0)
					{
						store[i].SetName(temp);
						f >> tmp;
						store[i].SetAmount(tmp);
						f >> tmp;
						store[i].SetCost(tmp);
						f >> tmp;
						store[i].SetNumber(tmp);
						i++;
					}
				}
			}
			else throw FileReadException();
		}
		else throw EmptyFileException();
	}
	catch (FileReadException e)
	{
		cout << e.what() << endl;
		f.clear();
		f.close();
		return -1;
	}
	catch (EmptyFileException e)
	{
		cout << e.what() << endl;
		f.clear();
		f.close();
		return 0;
	}
	f.clear();
	f.close();
	return i;
}

storage::storage()
{
	name = "";
	cost = 0;
	number = 0;
	amount = 0;
}
storage::~storage(){}
void storage::SetName(string temp)
{
	name = temp;
}
void storage::SetAmount(int temp)
{
	amount = temp;
}
void storage::SetCost(int temp)
{
	cost = temp;
}
void storage::SetNumber(int temp)
{
	number = temp;
}
string storage::GetName()
{
	return name;
}
int storage::GetAmount()
{
	return amount;
}
int storage::GetCost()
{
	return cost;
}
int storage::GetNumber()
{
	return number;
}

void check_nom(string temp)
{
	int k = 0;
	int i = 0;
	if (temp.length() == 0) throw InputException();
	for (i = 0; i < temp.length(); i++)
	{
		if (temp[i] >= 48 && temp[i] <= 57)
		{
			k++;
		}
	}
	if (i != k) throw InputException();
}
