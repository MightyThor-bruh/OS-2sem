// Lab14_z2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//ящик

#include<tchar.h>
#include <windows.h>
#include <iostream>
using namespace std;

void opt1() {
	HANDLE hslot;
	TCHAR slotname[] = TEXT("\\\\.\\mailslot\\demoslot");
	hslot = CreateMailslot(slotname, 0, MAILSLOT_WAIT_FOREVER, NULL);

	if (hslot == INVALID_HANDLE_VALUE)
	{
		cout << "SLOT FAILED" << endl;
		cout << "PRESS KEY TO FINISH" << endl;
		cin.get();
	}

	cout << "Ожидание" << endl;

	char text2[20], text[20];
	DWORD dwBytesRead;

	while (ReadFile(hslot, text, sizeof(text), &dwBytesRead, (LPOVERLAPPED)NULL) && text[0] != '0' && text[1] != 's') {
		cout << "Данные : " << text << endl;
	}

	CloseHandle(hslot);
	_tsystem(TEXT("PAUSE"));
	_tsystem(TEXT("CLS"));
}

void opt2() {

	HANDLE hslot;
	TCHAR slotname[] = TEXT("\\\\.\\mailslot\\demoslot");
	hslot = CreateMailslot(slotname, 0, MAILSLOT_WAIT_FOREVER, NULL);

	if (hslot == INVALID_HANDLE_VALUE)
	{
		cout << "SLOT FAILED" << endl;
		cout << "PRESS KEY TO FINISH" << endl;
		cin.get();
	}

	cout << "Ожидание" << endl;

	char text2[20], text[20];
	DWORD dwBytesRead;
	DWORD dwBytesRead2;

	while ((text[0] != '0' && text[1] != 's') && (text2[0] != '0' && text2[1] != 's')) {
		ReadFile(hslot, text, sizeof(text), &dwBytesRead, (LPOVERLAPPED)NULL);
		cout << "Данные : " << text << endl;
		ReadFile(hslot, text2, sizeof(text), &dwBytesRead2, (LPOVERLAPPED)NULL);
		cout << "Данные : " << text2 << endl;
	}

	CloseHandle(hslot);
	_tsystem(TEXT("PAUSE"));
	_tsystem(TEXT("CLS"));
}

void opt3() {
	HANDLE hslot;
	TCHAR slotname[] = TEXT("\\\\.\\mailslot\\demoslot");
	hslot = CreateMailslot(slotname, 0, MAILSLOT_WAIT_FOREVER, NULL);

	if (hslot == INVALID_HANDLE_VALUE)
	{
		cout << "SLOT FAILED" << endl;
		cout << "PRESS KEY TO FINISH" << endl;
		cin.get();
	}

	cout << "Ожидание" << endl;

	char message[256];
	DWORD dwBytesRead;

	ReadFile(hslot, message, sizeof(message), &dwBytesRead, (LPOVERLAPPED)NULL);
	cout << "Message : " << message << endl;

	CloseHandle(hslot);
	_tsystem(TEXT("PAUSE"));
	_tsystem(TEXT("CLS"));
}

int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int out = 0;
	while (out != 4) {
		cout << "Выберите режим работы сервера:" << endl << "(1 - чтение нескольких сообщений от 1 клиента)" << endl << "(2 - чтение сообщений от двух клиентов)" << endl << "(3 - чтение строкового сообщения)" << endl << endl;
		cin >> out;
		switch (out) {
		case 1: opt1(); break;
		case 2: opt2(); break;
		case 3: opt3(); break;
		}
	}
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
