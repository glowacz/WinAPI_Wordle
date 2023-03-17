#pragma once
#include "wordle.h"

void ChooseSol()
{
	uniform_int_distribution<> distr(0, DICT_SIZE - 1);
	int i;

	for (int win_no = 0; win_no < window_count; win_no++)
	{
		i = distr(eng);
		solution[win_no] = words[i];
	}
}

void Destroy_children()
{
	//DestroyWindow(hwnd_keyboard);
	for (int i = 0; i < MAX_WIN_COUNT; i++)
		DestroyWindow(hwnd[i]);
	DestroyWindow(hwnd_overlay[0]); DestroyWindow(hwnd_overlay[1]);
	i_tile = 0;
	j_tile = -1;
}

void AllLevels()
{
	for (int i = 0; i < MAX_WIN_COUNT; i++)
		window_green[i] = false;
	
	during_animation = false;

	Destroy_children();

	ChooseSol();

	SetTileCords();
	SetWhite();

	paint_keyboard = true;
	SetPaintAll();
	InvalidateRect(hwnd_keyboard, NULL, TRUE);
}

void Easy(HWND hWnd)
{
	window_count = 1; word_count = 6; level = 0;
	
	AllLevels();

	//hwnd[0] = CreateWindowW(boardClass, boardTitle, WS_OVERLAPPED | WS_CHILD, CW_USEDEFAULT, CW_USEDEFAULT, w_child, h_easy, hwnd_keyboard, nullptr, hInst, nullptr);
	hwnd[0] = CreateWindowW(boardClass, boardTitle, WS_OVERLAPPED, CW_USEDEFAULT, CW_USEDEFAULT, w_child, h_easy, hwnd_keyboard, nullptr, hInst, nullptr);

	/*HFONT hFont = CreateFont(60, 0, 0, 0, FW_HEAVY, FALSE, TRUE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, L"Arial");

	SendMessage(hwnd[0], WM_SETFONT, WPARAM(hFont), TRUE);*/

	ShowWindow(hwnd[0], show);
	//UpdateWindow(hwnd[0]);
	InvalidateRect(hwnd[0], NULL, TRUE);

	MoveWindow(hwnd[0], GetSystemMetrics(SM_CXSCREEN) / 2 - w_child / 2, GetSystemMetrics(SM_CYSCREEN) - h_easy - height - 120, w_child, h_easy, true);
	//MoveWindow(hwnd[0], 0, -600, w_child, h_easy, true);

	SetWindowLong(hWnd, GWL_EXSTYLE, GetWindowLong(hWnd, GWL_EXSTYLE) | WS_EX_LAYERED);
	SetLayeredWindowAttributes(hWnd, 0, (255 * 50) / 100, LWA_ALPHA);
}

void Medium(HWND hWnd)
{

	window_count = 2; word_count = 8; level = 1;

	AllLevels();

	for (int i = 0; i < window_count; i++)
	{
		hwnd[i] = CreateWindowW(boardClass, boardTitle, WS_OVERLAPPED, CW_USEDEFAULT, CW_USEDEFAULT, w_child, h_medium, hWnd, nullptr, hInst, nullptr);
		SetWindowLong(hWnd, GWL_EXSTYLE, GetWindowLong(hWnd, GWL_EXSTYLE) | WS_EX_LAYERED);
		SetLayeredWindowAttributes(hWnd, 0, (255 * 50) / 100, LWA_ALPHA);

		ShowWindow(hwnd[i], show);
		//UpdateWindow(hwnd[i]);
		InvalidateRect(hwnd[i], NULL, TRUE);

		if (i == 0)
			MoveWindow(hwnd[i], GetSystemMetrics(SM_CXSCREEN) / 2 - width / 2 - w_child, 600, w_child, h_medium, true);
		else if (i == 1)
			MoveWindow(hwnd[i], GetSystemMetrics(SM_CXSCREEN) / 2 + width / 2, 600, w_child, h_medium, true);
	}
}

void Hard(HWND hWnd)
{
	window_count = 4; word_count = 10; level = 2;

	AllLevels();

	for (int i = 0; i < window_count; i++)
	{
		hwnd[i] = CreateWindowW(boardClass, boardTitle, WS_OVERLAPPED, CW_USEDEFAULT, CW_USEDEFAULT, w_child, h_medium, hWnd, nullptr, hInst, nullptr);
		SetWindowLong(hWnd, GWL_EXSTYLE, GetWindowLong(hWnd, GWL_EXSTYLE) | WS_EX_LAYERED);
		SetLayeredWindowAttributes(hWnd, 0, (255 * 50) / 100, LWA_ALPHA);

		ShowWindow(hwnd[i], show);
		//UpdateWindow(hwnd[i]);
		InvalidateRect(hwnd[i], NULL, TRUE);

		if (i == 0)
			MoveWindow(hwnd[i], GetSystemMetrics(SM_CXSCREEN) / 2 - width / 2 - w_child, 0, w_child, h_hard, true);
		else if (i == 1)
			MoveWindow(hwnd[i], GetSystemMetrics(SM_CXSCREEN) / 2 + width / 2, 0, w_child, h_hard, true);
		else if (i == 2)
			MoveWindow(hwnd[i], GetSystemMetrics(SM_CXSCREEN) / 2 - width / 2 - w_child, 700, w_child, h_hard, true);
		else if (i == 3)
			MoveWindow(hwnd[i], GetSystemMetrics(SM_CXSCREEN) / 2 + width / 2, 700, w_child, h_hard, true);
	}
}