// Lab15_ex2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <windows.h>
#include <iostream>
#include <tchar.h>

INT _tmain(INT argc, _TCHAR* argv[])
{
	SIZE_T
		initSize = 4096,
		maxSize = 4096,
		arrSize = 2048;
	HANDLE hHeap;
	hHeap = HeapCreate(HEAP_NO_SERIALIZE, initSize, maxSize);
	if (!hHeap) {
		_tprintf_s(TEXT("Failed to create heap: %d\n"), GetLastError());
		return EXIT_FAILURE;
	}
	else
		_tprintf_s(TEXT("Heap created!\n"));

	LPINT arr = (LPINT)HeapAlloc(hHeap, NULL, arrSize);
	if (!arr) {
		_tprintf_s(TEXT("Failed to allocate heap: %d\n"), GetLastError());
		return EXIT_FAILURE;
	}
	else
		_tprintf_s(TEXT("Heap allocated!\n"));

	_tprintf_s(TEXT("Array:\n"));
	for (INT i = 0; i < arrSize / sizeof(INT); i++) {
		arr[i] = i;
		_tprintf_s(TEXT("%i "), i);
	}
	_tprintf_s(TEXT("\nMemory allocated for array with 512 INT elements!\n"));
	_tsystem(TEXT("pause"));
	HeapDestroy(hHeap);
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
