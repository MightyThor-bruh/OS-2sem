// Lab11_ex4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <windows.h>
#include <tchar.h>

INT _tmain(INT argc, _TCHAR* argv[])
{
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

    HANDLE hProcess = GetCurrentProcess(); //получаем pID консольного приложен.

    if (NULL != hProcess)
    {
        Sleep(200);
        BOOL result = TerminateProcess(hProcess, EXIT_SUCCESS);

        CloseHandle(hProcess);
    }
    else
    {
        _tprintf_s(TEXT("Error when terminating.\n"));
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
