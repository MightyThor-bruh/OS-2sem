// Lab11_z2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <windows.h>
#include <iostream>
#include <tlhelp32.h>
#include <tchar.h>
#include <wchar.h>

using namespace std;

//прототипы функций, проверяющих запуск файла

bool IsProcessRun(const TCHAR* procName);
bool AreEqual(const TCHAR* a, const TCHAR* b);

void main() {

	//Поиск файла
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;
	LPCTSTR directorySearch = L"C:\\Windows\\SysWOW64";
	LPCTSTR fileSearch = L"C:\\Windows\\SysWOW64\\mspa*.exe";
	hFind = FindFirstFile(fileSearch, &FindFileData);
	if (hFind == INVALID_HANDLE_VALUE) {

		cout << "Error: " << GetLastError() << endl;
		return;
	}

	else {

		_tprintf_s(TEXT("Found: %s\n"), FindFileData.cFileName);
	}

	//Запишем в переменную procName путь к файлу и полное имя файла

	TCHAR procName[MAX_PATH] = TEXT(""); 

	//Копирует строку src, включая завершающий нулевой символ, в строку назначения dest.*/

	wcscpy_s(procName, directorySearch); 
	wcscat_s(procName, FindFileData.cFileName);
	FindClose(hFind);

	//Запуск

	STARTUPINFO cif;
	ZeroMemory(&cif, sizeof(STARTUPINFO));
	PROCESS_INFORMATION pi;
	TCHAR buf[] = TEXT("mspaint.exe");
	if (!CreateProcess(NULL, buf, NULL, NULL, FALSE, NULL,
		NULL, NULL, &cif, &pi)) {
		_tprintf_s(TEXT("Not running.\n"));
	}
	_tprintf_s(TEXT("Running.\n"));
	CloseHandle(pi.hThread);
	CloseHandle(pi.hProcess);

	//Запустился ли файл


	_tsystem(TEXT("pause"));

}

//обработка всех запущенных в системе программ и отправка их в функцию AreEqual

bool IsProcessRun(const TCHAR* procName) {

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

//функция получает поочередно все запущенные процессы и сравнивает их с тем, который нужно было запустить

//если необходимый к запуску процесс найден функция возвращает TRUE

bool AreEqual(const TCHAR* a, const TCHAR* b) {

	while (*a == *b)
	{

		if (*a == _TEXT('\0'))

			return true;

		a++;
		b++;
	}
	return false;
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
