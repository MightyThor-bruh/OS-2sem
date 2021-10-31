// Client2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include<tchar.h>
#include <windows.h>
#include <iostream>
using namespace std;

void opt1() {
	HANDLE hslot;

	TCHAR slotname[] = TEXT("\\\\.\\mailslot\\demoslot");
	hslot = CreateFile(slotname, GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);


	if (hslot == INVALID_HANDLE_VALUE)
	{
		cout << "SLOT WRITING FAILED" << endl;
		cout << "PRESS KEY TO FINISH" << endl;
		cin.get();
	}
	char emp[16];
	cout << "Второй клиент " << endl;
	gets_s(emp);
	char text[16];
	DWORD dwBytesWrite;
	while (text[0] != '0' && text[1] != 's') {
		gets_s(text);
		WriteFile(hslot, text, sizeof(text), &dwBytesWrite, NULL);
		cout << "Данные: " << text << endl;
	}

	CloseHandle(hslot);

	_tsystem(TEXT("PAUSE"));
	_tsystem(TEXT("CLS"));
}

int main(int argc, _TCHAR* argv[]) {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int out = 0;
	while (out != 4) {
		cout << "Выберите режим работы 2 клиента:" << endl << "(1 - отправка сообщений от 2 клиента)" << endl << endl;
		cin >> out;
		switch (out) {
		case 1: opt1(); break;
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
