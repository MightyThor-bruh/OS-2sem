// Lab12_z1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <windows.h>
#include <tchar.h> 

DWORD Number; //глобальная переменная

DWORD WINAPI Reader(LPVOID lpparameter) //читатель 
{
	_tprintf_s(TEXT("Counter= %d\n"), Number); //выводим на консоль глобальную переменную
	return 0;
}

DWORD WINAPI Writer(LPVOID lpParameter) { //писатель
	unsigned int counter = 0;
	DWORD dwMyThreadID1;

	while (counter != 10) {
		Number = counter; //глобальной присваиваем значение
		HANDLE hMyHandle2 = CreateThread(NULL, 0, Reader, 0, 0, &dwMyThreadID1);
		Sleep(300); // timeout
		TerminateThread(hMyHandle2, 0); //очищаем поток
		counter++;
	}

	return EXIT_SUCCESS;
}

INT _tmain(INT argc, _TCHAR* argv[]) {
	DWORD dwMyThreadID;
	HANDLE hMyHandle = CreateThread(NULL, 0, Writer, 0, 0, &dwMyThreadID);
	Sleep(5000);
	_tprintf_s(TEXT("Main Process end\n"));
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
