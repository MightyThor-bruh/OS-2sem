// Lab15_z1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <windows.h>
#include <iostream>
#include <tchar.h>

using namespace std;

SIZE_T
maxSize = 8192,
arrSize = 512,
initSize = arrSize;
HANDLE hHeap;
INT Size;
LPINT arr;

INT addToEnd() {
	arrSize += sizeof(INT);
	arr = (LPINT)HeapReAlloc(hHeap, NULL, arr, arrSize);


	if (!arr) {
		_tprintf_s(TEXT("Failed to reallocate heap: %d\n"), GetLastError());
		return EXIT_FAILURE;
	}
	else
		_tprintf_s(TEXT("Heap reallocated!\n"));
	Size = arrSize / sizeof(INT);
	cout << Size << endl;
	INT rn;
	cout << "Введите добавляемый элемент: ";
	cin >> rn;
	arr[Size - 1] = rn;
	_tprintf_s(TEXT("New array:\n"));
	for (INT i = 0; i < Size; i++) {
		cout << arr[i] << "\t";
	}
	cout << endl;
}

INT addWithShift() {
	INT place;
	cout << "Введите место нового элемента(от 0 до " << --Size << "): ";
	cin >> place;

	arrSize += sizeof(INT);
	arr = (LPINT)HeapReAlloc(hHeap, NULL, arr, arrSize);



	if (!arr) {
		_tprintf_s(TEXT("Failed to reallocate heap: %d\n"), GetLastError());
		return EXIT_FAILURE;
	}
	else
		_tprintf_s(TEXT("Heap reallocated!\n"));
	Size = arrSize / sizeof(INT);

	for (int i = Size - 2; i >= place; i--) {
		arr[i + 1] = arr[i];
	}

	cout << Size << endl;
	INT rn = 999;
	arr[place] = rn;
	_tprintf_s(TEXT("New array:\n"));
	for (INT i = 0; i < Size; i++) {
		cout << arr[i] << "\t";
	}
	cout << endl;
}

INT remFromEnd() {
	arrSize -= sizeof(INT);
	arr = (LPINT)HeapReAlloc(hHeap, NULL, arr, arrSize);


	if (!arr) {
		_tprintf_s(TEXT("Failed to reallocate heap: %d\n"), GetLastError());
		return EXIT_FAILURE;
	}
	else
		_tprintf_s(TEXT("Heap reallocated!\n"));
	Size = arrSize / sizeof(INT);
	cout << Size << endl;
	_tprintf_s(TEXT("New array:\n"));
	for (INT i = 0; i < Size; i++) {
		cout << arr[i] << "\t";
	}
	cout << endl;
}

INT remWithShift() {
	INT place;
	cout << "Введите удаляемый элемент (от 0 до " << --Size << "): ";
	cin >> place;

	if (!arr) {
		_tprintf_s(TEXT("Failed to reallocate heap: %d\n"), GetLastError());
		return EXIT_FAILURE;
	}
	else
		_tprintf_s(TEXT("Heap reallocated!\n"));



	for (int i = place + 1; i < Size; i++) {
		arr[i - 1] = arr[i];
	}

	arrSize -= sizeof(INT);
	arr = (LPINT)HeapReAlloc(hHeap, NULL, arr, arrSize);
	Size = arrSize / sizeof(INT);

	_tprintf_s(TEXT("New array:\n"));
	for (INT i = 0; i < Size; i++) {
		cout << arr[i] << "\t";
	}
	cout << endl;
}

INT _tmain(INT argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "ru");
	Size = arrSize / sizeof(INT);
	hHeap = HeapCreate(HEAP_NO_SERIALIZE, initSize, maxSize);
	if (!hHeap) {
		_tprintf_s(TEXT("Failed to create heap: %d\n"), GetLastError());
		return EXIT_FAILURE;
	}
	else
		_tprintf_s(TEXT("Heap created!\n"));

	arr = (LPINT)HeapAlloc(hHeap, NULL, arrSize);
	if (!arr) {
		_tprintf_s(TEXT("Failed to allocate heap: %d\n"), GetLastError());
		return EXIT_FAILURE;
	}
	else
		_tprintf_s(TEXT("Heap allocated!\n"));

	_tprintf_s(TEXT("Array:\n"));
	for (INT i = 0; i < Size; i++) {
		arr[i] = i;
		cout << arr[i] << "\t";
	}
	cout << endl;

	INT opt = 0;
	while (opt != 5) {
		cout << "Выберите нужное действие: " << endl << "1 - добавление элемента справа"
			<< endl << "2 - удаление элемента справа" << endl << "3 - добавление в опр. место со сдвигом" << endl <<
			"4 - удаление опр. элемента со сдвигом" << endl << "5 - ВЫХОД" << endl;
		cin >> opt;
		switch (opt) {
		case 1: _tsystem(TEXT("CLS")); addToEnd(); break;
		case 2: _tsystem(TEXT("CLS")); remFromEnd(); break;
		case 3: _tsystem(TEXT("CLS")); addWithShift(); break;
		case 4: _tsystem(TEXT("CLS")); remWithShift(); break;
		}
	}

	if (HeapDestroy(hHeap)) {
		_tprintf_s(TEXT("Heap destroyed!\n"));
	}
	else {
		_tprintf_s(TEXT("Erro while destroying heap: %i\n"), GetLastError());
	}

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
