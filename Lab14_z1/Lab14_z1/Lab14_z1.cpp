// Lab14_z1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include<iostream>
#include<windows.h>
#include<string.h>
using namespace std;

HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);

void task1()
{
	system("mode con cols=70 lines=30");
	system("cls");
	SetConsoleTextAttribute(H, 11);
	int size;
	char** arr;
	cout << "Введите размер массва : ";
	cin >> size;

	arr = (char**)malloc(size * sizeof(char*));

	if (!arr)
	{
		cout << "Ошибка";
		return;
	}

	for (int i = 0; i < size; i++)
	{
		arr[i] = (char*)malloc(50 * sizeof(char));
		cin >> arr[i];
	}
	cout << endl;

	cout << "Вывод элементов массва : ";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	free(arr);
	system("pause");
}

struct book
{
	char title[10];
};

void task2()
{
	system("cls");
	system("mode con cols=70 lines=30");
	SetConsoleTextAttribute(H, 11);
	int size;
	book* arr;

	cout << "Введите размер :";
	cin >> size;

	arr = (book*)malloc(size * sizeof(book));

	if (!arr)
	{
		cout << "Ошибка";
		return;
	}

	cout << "Ввод элементов : ";
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i].title;
	}

	cout << endl;
	cout << "Вывод элементов : ";
	for (int i = 0; i < size; i++)
	{
		cout << " " << arr[i].title << endl;
	}
	free(arr);
	system("pause");
}

void task3()
{
	system("cls");
	SetConsoleTextAttribute(H, 11);
	int str = 1;
	int cl = 1;
	book** arr;
	cout << "Введите кол-во строк  :";
	cin >> str;
	cout << "Введите кол-во столбцов  :";
	cin >> cl;

	arr = (book**)malloc(str * sizeof(book*));

	if (!arr)
	{
		cout << "Ошибка";
		return;
	}

	cout << "Ввод элементов : ";
	for (int i = 0; i < str; i++)
	{
		*(arr + i) = (book*)malloc(cl * sizeof(book));
		for (int j = 0; j < cl; j++)
		{
			cin >> arr[i][j].title;
		}
	}

	cout << endl;
	cout << "Вывод элементов : " << endl;
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < cl; j++)
		{
			cout << arr[i][j].title << '\t';
		}
		cout << endl;
	}
	free(arr);
	system("pause");
}

void main()
{
	setlocale(LC_ALL, "ru");
	task1();
	//task2();
	//task3();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
