// Lab12_z2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <windows.h>
#include "string.h"
#include <iostream>
using namespace std;

DWORD WINAPI myThread_1(LPVOID lpParameter)
{
	unsigned int numb1 = 0;
	while (numb1 < 20)
	{
		Sleep(1000);
		numb1++;
		cout << "A: " << numb1 << endl;
	}
	return 0;
}

DWORD WINAPI myThread_2(LPVOID lpParameter)
{
	unsigned int numb2 = 65;
	while (numb2 > 0)
	{
		Sleep(1000);
		numb2--;
		cout << "B: " << numb2 << endl;
	}
	return 0;
}

int main()
{

	unsigned int myCounter = 0;
	DWORD myThreadID;
	HANDLE myHandle1 = CreateThread(0, 0, myThread_1, &myCounter, 0, &myThreadID);
	HANDLE myHandle2 = CreateThread(0, 0, myThread_2, &myCounter, 0, &myThreadID);
	Sleep(20000);
	printf("\nFinish");
	TerminateThread(myHandle1, 0);
	TerminateThread(myHandle2, 0);
	getchar();

	return 0;
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
