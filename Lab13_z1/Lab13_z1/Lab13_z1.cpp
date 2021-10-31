// Lab13_z1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <windows.h>
#include <iostream>
#include "string.h"

CRITICAL_SECTION cs;	//Создает новый критический раздел.
TCHAR stdPath[50] = TEXT("D:\\Стандартные папки\\Рабочий стол\\lab13.txt");

HANDLE hOut;
DWORD dwBytes;
FILE* fp;
HANDLE hIn;

DWORD WINAPI myThread(void* lpPar)
{
	TCHAR* b = new TCHAR();
	b = (TCHAR*)lpPar;	

	EnterCriticalSection(&cs);		//указание на объект критической секции

	hOut = CreateFile(stdPath, GENERIC_WRITE, 0, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hOut == INVALID_HANDLE_VALUE)
	{
		printf("ERROR WRITING FILE");
		return 2;
	}
	else

	{
		WriteFile(hOut, b, 256, &dwBytes, NULL); 
		printf("Thread  1 Written\n");
		Sleep(5000);
		CloseHandle(hOut);
	}

	LeaveCriticalSection(&cs);    //освобождение секции
	return 0;

}


DWORD WINAPI myThread2(void* lpPar)
{
	TCHAR* b = new TCHAR();
	b = (TCHAR*)lpPar;

	TCHAR Bu[255];

	EnterCriticalSection(&cs);

	hIn = CreateFile(stdPath, GENERIC_READ, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hIn == INVALID_HANDLE_VALUE)
	{
		printf("ERROR WRITING FILE");
		return 2;
	}
	else
	{
		ReadFile(hIn, Bu, 256, &dwBytes, NULL);

		printf("Thread  2 Read\n");
		std::wcout << "Read: " << Bu << '\n';
		CloseHandle(hIn);

	}
	LeaveCriticalSection(&cs);
	return 0;

}

int main(int argc, TCHAR* argv[])
{


	int z = 0;

	DWORD myThreadID;
	DWORD myThreadID2;

	TCHAR Buff[256] = TEXT("bruh");
	TCHAR Buff2[256];

	InitializeCriticalSection(&cs);

	HANDLE myHandle = CreateThread(0, 0, myThread, (void*)Buff, CREATE_SUSPENDED, &myThreadID);
	HANDLE myHandle2 = CreateThread(0, 0, myThread2, (void*)Buff2, CREATE_SUSPENDED, &myThreadID2);


	BOOL b = SetThreadPriorityBoost(myHandle, false); //отключает или включает способность системы временно повышать приоритет потока

	if (b)
	{
		SetThreadPriority(myHandle, THREAD_PRIORITY_HIGHEST);

	}

	ResumeThread(myHandle);
	Sleep(10);
	ResumeThread(myHandle2);
	WaitForSingleObject(myHandle, 10000);	//ждет когда myHandle перейдет в сигнальное состояние
	WaitForSingleObject(myHandle2, 10000);
	printf("\n The end");

	TerminateThread(myHandle, 0); //завершает работу потока.
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
