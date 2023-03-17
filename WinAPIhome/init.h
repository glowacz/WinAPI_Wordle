#pragma once

#include "wordle.h"

ATOM RegisterClassKeyboard(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON));
	wcex.hCursor = nullptr;
	wcex.hbrBackground = CreateSolidBrush(RGB(255, 255, 255));
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_TUTORIAL);

	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON));

	return RegisterClassExW(&wcex);
}

ATOM RegisterClassBoard(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = nullptr;
	wcex.hCursor = nullptr;
	wcex.hbrBackground = CreateSolidBrush(RGB(255, 255, 255));
	wcex.lpszMenuName = nullptr;

	wcex.lpszClassName = boardClass;
	wcex.hIconSm = nullptr;

	return RegisterClassExW(&wcex);
}

ATOM RegisterClassOverlay(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	//wcex.lpfnWndProc = nullptr;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON));
	wcex.hCursor = nullptr;
	wcex.hbrBackground = CreateSolidBrush(RGB(0, 255, 0));
	//wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_TUTORIAL);
	wcex.lpszMenuName = nullptr;

	wcex.lpszClassName = ClassOv;
	wcex.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON));
	//wcex.hIconSm = nullptr;

	return RegisterClassExW(&wcex);
}

BOOL InitInstance()
{
    SetPaintAll();

	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
		GetSystemMetrics(SM_CXSCREEN) / 2 - width / 2, GetSystemMetrics(SM_CYSCREEN) - height - 100, width, height, nullptr, nullptr, hInst, nullptr);

	hwnd_keyboard = hWnd;

	//paint_keyboard = true;
	
	// Show this window
	ShowWindow(hwnd_keyboard, show);
	InvalidateRect(hwnd_keyboard, NULL, TRUE);
	UpdateWindow(hwnd_keyboard);

    // Read from .ini file
    ifstream init; init.open("Wordle.ini");
    init >> window_count;

    switch (window_count)
    {
    case 1:
        Easy(hwnd_keyboard);
        break;
    case 2:
        Medium(hwnd_keyboard);
        break;
    case 4:
        Hard(hwnd_keyboard);
        break;
    default:
        Easy(hwnd_keyboard);
    }

    init.close();

	return TRUE;
}