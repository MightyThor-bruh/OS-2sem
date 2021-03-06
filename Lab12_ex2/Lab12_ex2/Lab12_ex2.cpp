// Lab12_ex2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//выполняет простой отсчет, начиная с 6

#include <windows.h>
#include <tchar.h>

DWORD WINAPI myThread(LPVOID lpParameter)
{
	LPINT counterp = new INT();
	counterp = (LPINT)lpParameter;
	INT counter = *counterp;

	while (counter < 20)
	{
		Sleep(1000);
		counter++;
		_tprintf_s(TEXT("Counter = %d\n"), counter);
	}

	return EXIT_SUCCESS;
}

int _tmain(int argc, _TCHAR* argv[])
{
	INT z = 5;
	DWORD dwMyThreadID;
	HANDLE hMyHandle = CreateThread(NULL, 0, myThread, (LPVOID)&z, 0, &dwMyThreadID);
	if (hMyHandle == INVALID_HANDLE_VALUE || hMyHandle == NULL) {
		_tprintf_s(TEXT("Error while creating thread: %d\n"), GetLastError());
		return EXIT_FAILURE;
	}
	Sleep(5000);
	_tprintf_s(TEXT("Main Process sagt\n"));
	TerminateThread(hMyHandle, EXIT_SUCCESS);

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
