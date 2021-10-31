// Lab13_ex6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <windows.h>
#include <tchar.h>

struct threadParam {
	PTCHAR string;
	INT size;
};

CRITICAL_SECTION cs;

DWORD WINAPI myThread(LPVOID lpParameter)
{
	EnterCriticalSection(&cs);
	HANDLE hOut = CreateFile(TEXT("D:\\Стандартные папки\\Рабочий стол\\myfile.txt"), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hOut == INVALID_HANDLE_VALUE || hOut == NULL) {
		_tprintf_s(TEXT("Error while creating file: %d\n"), GetLastError());
		return EXIT_FAILURE;
	}
	else {
		DWORD dwBytes;
		threadParam* b = (threadParam*)lpParameter;
		if (!WriteFile(hOut, b->string, b->size, &dwBytes, NULL)) {
			_tprintf_s(TEXT("Error while writing in file: %d\n"), GetLastError());
			CloseHandle(hOut);
			LeaveCriticalSection(&cs);
			return EXIT_FAILURE;
		}
		else {
			_tprintf_s(TEXT("Writing file done successfully 1!\n"));
			CloseHandle(hOut);
		}

	}
	LeaveCriticalSection(&cs);
	return EXIT_SUCCESS;
}

DWORD WINAPI myThread2(LPVOID lpParameter)
{
	EnterCriticalSection(&cs);
	HANDLE hOut = CreateFile(TEXT("D:\\Стандартные папки\\Рабочий стол\\myfile.txt"), GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hOut == INVALID_HANDLE_VALUE || hOut == NULL) {
		_tprintf_s(TEXT("Error while creating file: %d\n"), GetLastError());
		return EXIT_FAILURE;
	}
	else {
		DWORD dwBytes;
		threadParam* b = (threadParam*)lpParameter;
		if (!WriteFile(hOut, b->string, b->size, &dwBytes, NULL)) {
			_tprintf_s(TEXT("Error while writing in file: %d\n"), GetLastError());
			CloseHandle(hOut);
			LeaveCriticalSection(&cs);
			return EXIT_FAILURE;
		}
		else {
			_tprintf_s(TEXT("Writing file done successfully 2!\n"));
			CloseHandle(hOut);
		}

	}
	LeaveCriticalSection(&cs);
	return EXIT_SUCCESS;
}

INT _tmain(INT argc, _TCHAR* argv[])
{
	DWORD
		dwMyThreadID,
		dwMyThread2ID;
	TCHAR
		Buffer[] = TEXT("Hello!"),
		Buffer2[] = TEXT("Students!");
	threadParam
		parameter,
		parameter2;

	parameter.string = Buffer;
	parameter.size = sizeof(Buffer);

	parameter2.string = Buffer2;
	parameter2.size = sizeof(Buffer2);

	InitializeCriticalSection(&cs);
	HANDLE hMyHandle = CreateThread(NULL, 0, myThread, (LPVOID)(&parameter), CREATE_SUSPENDED, &dwMyThreadID);
	if (hMyHandle == INVALID_HANDLE_VALUE || hMyHandle == NULL) {
		_tprintf_s(TEXT("Error while creating thread: %d\n"), GetLastError());
		_tsystem(TEXT("pause"));
		return EXIT_FAILURE;
	}

	HANDLE hMyHandle2 = CreateThread(NULL, 0, myThread2, (LPVOID)(&parameter2), CREATE_SUSPENDED, &dwMyThread2ID);
	if (hMyHandle2 == INVALID_HANDLE_VALUE || hMyHandle2 == NULL) {
		_tprintf_s(TEXT("Error while creating thread: %d\n"), GetLastError());
		CloseHandle(hMyHandle);
		_tsystem(TEXT("pause"));
		return EXIT_FAILURE;
	}
	if (SetThreadPriorityBoost(hMyHandle, FALSE)) {
		SetThreadPriority(hMyHandle, THREAD_PRIORITY_HIGHEST);
	}

	ResumeThread(hMyHandle);
	ResumeThread(hMyHandle2);
	WaitForSingleObject(hMyHandle2, 10000);

	_tprintf_s(TEXT("Main Process sagt Das ist Alles\n"));
	CloseHandle(hMyHandle);
	CloseHandle(hMyHandle2);
	DeleteCriticalSection(&cs);
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
