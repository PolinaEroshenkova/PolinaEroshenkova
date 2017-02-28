#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include<stdio.h>
#include<exception>
using namespace std;

class FileNotOpenException :public exception
{
public:
	virtual const char* what() const throw()
	{
		return "Ошибка открытия файла";
	}
};
class EmptyFileException :public exception
{
public:
	virtual const char* what() const throw()
	{
		return "Файл пуст";
	}
};
class FileReadException :public exception
{
public:
	virtual const char* what() const throw()
	{
		return "Невозможно прочитать данные из файла";
	}
};
class InputException :public exception
{
public:
	virtual const char* what() const throw()
	{
		return "Вы ввели недопустимый символ!";
	}
};

class storage
{
protected:
	string name;
	int amount;
	int cost;
	int number;
public:
	storage();
	~storage();
	void SetName(string);
	void SetAmount(int);
	void SetCost(int);
	void SetNumber(int);
	string GetName();
	int GetAmount();
	int GetCost();
	int GetNumber();
};
class file:public storage
{
	string filename;
	fstream f;
	int N;
public:
	file(string);
	int OPEN();
	void DISPLAY(storage*,int);
	void ADD();
	void DEL(string, storage*,int);
	void EDIT(string, char, storage*,int);
	int READ(storage*);
	~file();
};

int check(string);
void check_nom(string);