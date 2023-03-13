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
	for (int i = 0; i < window_count; i++)
		DestroyWindow(hwnd[i]);
	DestroyWindow(hwnd_overlay[0]); DestroyWindow(hwnd_overlay[1]);
	i_tile = 0;
	j_tile = -1;
}

void Easy(HWND hWnd)
{
	Destroy_children();

	window_count = 1; word_count = 6; level = 0;

	ChooseSol();

	SetWhite();

	hwnd[0] = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPED, CW_USEDEFAULT, CW_USEDEFAULT, w_child, h_easy, hWnd, nullptr, hInst, nullptr);

	/*HFONT hFont = CreateFont(60, 0, 0, 0, FW_HEAVY, FALSE, TRUE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, L"Arial");

	SendMessage(hwnd[0], WM_SETFONT, WPARAM(hFont), TRUE);*/

	SetWindowLong(hWnd, GWL_EXSTYLE, GetWindowLong(hWnd, GWL_EXSTYLE) | WS_EX_LAYERED);
	SetLayeredWindowAttributes(hWnd, 0, (255 * 50) / 100, LWA_ALPHA);

	ShowWindow(hwnd[0], show);
	UpdateWindow(hwnd[0]);

	MoveWindow(hwnd[0], GetSystemMetrics(SM_CXSCREEN) / 2 - w_child / 2, 900 - h_easy - 30, w_child, h_easy, true);
}

void Medium(HWND hWnd)
{
	Destroy_children();

	window_count = 2; word_count = 8; level = 1;

	ChooseSol();

	SetWhite();

	for (int i = 0; i < window_count; i++)
	{
		hwnd[i] = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPED, CW_USEDEFAULT, CW_USEDEFAULT, w_child, h_medium, hWnd, nullptr, hInst, nullptr);
		SetWindowLong(hWnd, GWL_EXSTYLE, GetWindowLong(hWnd, GWL_EXSTYLE) | WS_EX_LAYERED);
		SetLayeredWindowAttributes(hWnd, 0, (255 * 50) / 100, LWA_ALPHA);

		ShowWindow(hwnd[i], show);
		UpdateWindow(hwnd[i]);

		if (i == 0)
			MoveWindow(hwnd[i], GetSystemMetrics(SM_CXSCREEN) / 2 - width / 2 - w_child, 600, w_child, h_medium, true);
		else if (i == 1)
			MoveWindow(hwnd[i], GetSystemMetrics(SM_CXSCREEN) / 2 + width / 2, 600, w_child, h_medium, true);
	}
}

void Hard(HWND hWnd)
{
	Destroy_children();

	window_count = 4; word_count = 10; level = 2;

	ChooseSol();

	SetWhite();

	for (int i = 0; i < window_count; i++)
	{
		hwnd[i] = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPED, CW_USEDEFAULT, CW_USEDEFAULT, w_child, h_medium, hWnd, nullptr, hInst, nullptr);
		SetWindowLong(hWnd, GWL_EXSTYLE, GetWindowLong(hWnd, GWL_EXSTYLE) | WS_EX_LAYERED);
		SetLayeredWindowAttributes(hWnd, 0, (255 * 50) / 100, LWA_ALPHA);

		ShowWindow(hwnd[i], show);
		UpdateWindow(hwnd[i]);

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

void SetWhite()
{
	for (int win_no = 0; win_no < window_count; win_no++)
	{
		for (int i = 0; i < MAX_WORD_COUNT; i++)
			for (int j = 0; j < WORD_LEN; j++)
				white[i][j][win_no] = true;
		for (int i = 0; i < MAX_WORD_COUNT; i++)
			for (int j = 0; j < WORD_LEN; j++)
				grey[i][j][win_no] = false;
		for (int i = 0; i < MAX_WORD_COUNT; i++)
			for (int j = 0; j < WORD_LEN; j++)
				yellow[i][j][win_no] = false;
		for (int i = 0; i < MAX_WORD_COUNT; i++)
			for (int j = 0; j < WORD_LEN; j++)
				green[i][j][win_no] = false;

		for (int i = 0; i < KEY_COUNT; i++)
			key_white[i][win_no] = true;
		for (int i = 0; i < KEY_COUNT; i++)
			key_grey[i][win_no] = false;
		for (int i = 0; i < KEY_COUNT; i++)
			key_yellow[i][win_no] = false;
		for (int i = 0; i < KEY_COUNT; i++)
			key_green[i][win_no] = false;
	}

	for (int i = 0; i < MAX_WORD_COUNT; i++)
		for (int j = 0; j < WORD_LEN; j++)
			letters[i][j][0] = '\0';

	i_tile = 0;
	j_tile = -1;
}