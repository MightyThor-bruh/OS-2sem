// Lab12_ex3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <windows.h>
#include <tchar.h>

DWORD WINAPI myThread2(LPVOID lpParameter)
{
	LPHANDLE h = new HANDLE();
	h = (LPHANDLE)lpParameter;
	HANDLE hh = *h;

	_tprintf_s(TEXT("Thread 2 tries to suspend thread1\n"));
	SuspendThread(hh);

	_tprintf_s(TEXT("Thread1 is suspended for 3 seconds\n"));
	Sleep(3000);

	ResumeThread(hh);
	_tprintf_s(TEXT("Thread is resumed\n"));

	return EXIT_SUCCESS;
}

DWORD WINAPI myThread(LPVOID lpParameter)
{
	LPINT counterp = new INT();
	counterp = (LPINT)lpParameter;
	INT counter = *counterp;

	while (counter < 30)
	{
		Sleep(500);
		counter++;

		_tprintf_s(TEXT("Counter = %d\n"), counter);
	}

	return EXIT_SUCCESS;
}

INT _tmain(INT argc, _TCHAR* argv[])
{
	INT z = 5;
	DWORD dwMyThreadID;
	HANDLE hMyHandle = CreateThread(NULL, 0, myThread, (LPVOID)&z, 0, &dwMyThreadID);
	Sleep(5000);
	DWORD dwMyThreadID2;
	HANDLE hMyHandle2 = CreateThread(NULL, 0, myThread2, (LPVOID)&hMyHandle, 0, &dwMyThreadID2);

	Sleep(15000);
	_tprintf_s(TEXT("Main Process sagt\n"));
	TerminateThread(hMyHandle2, 0);
	TerminateThread(hMyHandle, 0);

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
