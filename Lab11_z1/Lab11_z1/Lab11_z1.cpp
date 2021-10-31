﻿// Lab11_z1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "windows.h"
#include <tchar.h>

INT _tmain(INT argc, _TCHAR* argv[])
{
    STARTUPINFO cif;
    ZeroMemory(&cif, sizeof(STARTUPINFO));
    PROCESS_INFORMATION pi;


    WIN32_FIND_DATA FindFileData;
    HANDLE hFind = INVALID_HANDLE_VALUE;

    TCHAR directorySearch[] = TEXT("C:\\Windows\\SysWOW64\\*");
    TCHAR filesearch[] = TEXT("C:\\Windows\\SysWOW64\\mspaint.exe");
    // Find the first file in the directory.
    hFind = FindFirstFile(filesearch, &FindFileData);

    if (hFind == INVALID_HANDLE_VALUE)
    {
        _tprintf_s(TEXT("Invalid file handle. Error is %u.\n"), GetLastError());
    }
    else
    {
        _tprintf_s(TEXT("Found: %s\n"), FindFileData.cFileName);

        // List all the other files in the directory.
        while (FindNextFile(hFind, &FindFileData) != NULL)
        {
            _tprintf_s(TEXT("Found: %s\n"), FindFileData.cFileName);
        }
        FindClose(hFind);
    }

    if (!CreateProcess(NULL, filesearch, NULL, NULL, FALSE, NULL,
        NULL, NULL, &cif, &pi)) {
        _tprintf_s(TEXT("Error.\n"));
    }
    CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);


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
