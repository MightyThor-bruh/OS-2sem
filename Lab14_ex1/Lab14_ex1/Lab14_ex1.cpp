// Lab14_ex1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <windows.h>
#include <tchar.h>
#include <clocale>

INT _tmain(INT argc, _TCHAR* argv[])
{
	INT n;
	_tsystem(TEXT("mode con cols=60 lines=10"));
	_tsystem(TEXT("title String"));
	_tsetlocale(LC_ALL, TEXT("RUS"));
	_tsystem(TEXT("cls"));
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, 11);

	_tprintf_s(TEXT("Введите размер массива\n"));
	_tscanf_s(TEXT("%i"), &n);//ввод размера массива

	LPINT massiv = (LPINT)malloc(n * sizeof(INT)); //выделение динам.памяти

	if (!massiv)                              //проверка факта выделения памяти
	{
		_tprintf_s(TEXT("Недостаточно памяти\n"));
		_tsystem(TEXT("pause"));
		CloseHandle(hStdOut);
		return EXIT_FAILURE;
	}

	_tprintf_s(TEXT("Введите (целочисленный) массив, нажимая ENTER после каждого элемента\n"));
	for (INT i = 0; i < n; i++)
		_tscanf_s(TEXT("%i"), &(massiv[i])); //ввод массива

	_tprintf_s(TEXT("Massiv:\n"));
	for (INT i = 0; i < n; i++)
		_tprintf_s(TEXT(" %d"), massiv[i]); //вывод массива

	_tprintf_s(TEXT("\nДо свидания!\n\n"));
	_tsystem(TEXT("pause"));
	free(massiv); //освобождение памяти
	CloseHandle(hStdOut);
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
