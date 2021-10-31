// Lab11_ex6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "windows.h"
#include <tlhelp32.h>
#include <tchar.h>

#define STRLEN(x) (sizeof(x)/sizeof(TCHAR) - 1)

bool AreEqual(const TCHAR* a, const TCHAR* b)
{
	while (*a == *b)
	{
		if (*a == _TEXT('\0'))
			return true;
		a++;
		b++;
	}
	return false;
}

bool IsProcessRun(const TCHAR* procName)
{
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	PROCESSENTRY32 pe;
	pe.dwSize = sizeof(PROCESSENTRY32);
	Process32First(hSnapshot, &pe);

	if (AreEqual(pe.szExeFile, procName))
	{
		return true;
	}

	while (Process32Next(hSnapshot, &pe))
	{
		if (AreEqual(pe.szExeFile, procName))
		{
			return true;
		}
	}
	return false;
}

INT _tmain(INT argc, _TCHAR* argv[])
{

	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE);

	if (IsProcessRun(TEXT("mspaint.exe")))
		_tprintf_s(TEXT("Running.\n"));
	else
		_tprintf_s(TEXT("Not running.\n"));

	_tsystem(TEXT("pause"));
	return EXIT_SUCCESS;
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
