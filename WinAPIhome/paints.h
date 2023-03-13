#pragma once

#include "framework.h"
#include "wordle.h"

void PaintKeyboard(HWND hWnd)
{
	RECT rect;
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hWnd, &ps);

	// WHITE

	HPEN pen = CreatePen(PS_SOLID, 2, RGB(220, 220, 220));
	HPEN oldPen = (HPEN)SelectObject(hdc, pen);
	HBRUSH brush = CreateSolidBrush(RGB(251, 252, 255));
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

	for (int i = 0; i < KEY_COUNT; i++)
	{
		//if(key_white[i][0])
			Rectangle(hdc, keys[i][0][0].left, keys[i][0][0].top, keys[i][0][0].right, keys[i][0][0].bottom);
		/*if (window_count == 1)
			Rectangle(hdc, keys[i].left, keys[i].top, keys[i].right, keys[i].bottom);
		else if (window_count == 2)
		{
			Rectangle(hdc, keys[i].left, keys[i].top, (keys[i].left + keys[i].right)/2, keys[i].bottom);
			Rectangle(hdc, (keys[i].left + keys[i].right) / 2, keys[i].top, keys[i].right, keys[i].bottom);
		}
		else if (window_count == 4)
		{
			Rectangle(hdc, keys[i].left, keys[i].top, (keys[i].left + keys[i].right) / 2, (keys[i].top + keys[i].bottom)/2);
			Rectangle(hdc, (keys[i].left + keys[i].right) / 2, keys[i].top, keys[i].right, (keys[i].top + keys[i].bottom) / 2);
			Rectangle(hdc, keys[i].left, (keys[i].top + keys[i].bottom) / 2, (keys[i].left + keys[i].right) / 2, keys[i].bottom);
			Rectangle(hdc, (keys[i].left + keys[i].right) / 2, (keys[i].top + keys[i].bottom) / 2, keys[i].right, keys[i].bottom);
		}*/
	}

	DeleteObject(pen);
	DeleteObject(brush);

	// GREY

	pen = CreatePen(PS_SOLID, 2, RGB(164, 174, 196));
	oldPen = (HPEN)SelectObject(hdc, pen);
	brush = CreateSolidBrush(RGB(164, 174, 196));
	oldBrush = (HBRUSH)SelectObject(hdc, brush);

	for (int j = 0; j < window_count; j++)
	{
		for (int i = 0; i < KEY_COUNT; i++)
		{
			if (key_grey[i][j])
				Rectangle(hdc, keys[i][level][j].left, keys[i][level][j].top, keys[i][level][j].right, keys[i][level][j].bottom);
		}
	}

	DeleteObject(pen);
	DeleteObject(brush);

	// YELLOW

	pen = CreatePen(PS_SOLID, 2, RGB(243, 194, 55));
	oldPen = (HPEN)SelectObject(hdc, pen);
	brush = CreateSolidBrush(RGB(243, 194, 55));
	oldBrush = (HBRUSH)SelectObject(hdc, brush);

	for (int j = 0; j < window_count; j++)
	{
		for (int i = 0; i < KEY_COUNT; i++)
		{
			if (key_yellow[i][j])
				Rectangle(hdc, keys[i][level][j].left, keys[i][level][j].top, keys[i][level][j].right, keys[i][level][j].bottom);
			/*if (window_count == 1)
				Rectangle(hdc, keys[i].left, keys[i].top, keys[i].right, keys[i].bottom);
			else if (window_count == 2)
			{
				Rectangle(hdc, keys[i].left, keys[i].top, (keys[i].left + keys[i].right) / 2, keys[i].bottom);
				Rectangle(hdc, (keys[i].left + keys[i].right) / 2, keys[i].top, keys[i].right, keys[i].bottom);
			}
			else if (window_count == 4)
			{
				Rectangle(hdc, keys[i].left, keys[i].top, (keys[i].left + keys[i].right) / 2, (keys[i].top + keys[i].bottom) / 2);
				Rectangle(hdc, (keys[i].left + keys[i].right) / 2, keys[i].top, keys[i].right, (keys[i].top + keys[i].bottom) / 2);
				Rectangle(hdc, keys[i].left, (keys[i].top + keys[i].bottom) / 2, (keys[i].left + keys[i].right) / 2, keys[i].bottom);
				Rectangle(hdc, (keys[i].left + keys[i].right) / 2, (keys[i].top + keys[i].bottom) / 2, keys[i].right, keys[i].bottom);
			}*/
		}
	}

	pen = CreatePen(PS_SOLID, 2, RGB(121, 184, 81));
	oldPen = (HPEN)SelectObject(hdc, pen);
	brush = CreateSolidBrush(RGB(121, 184, 81));
	oldBrush = (HBRUSH)SelectObject(hdc, brush);

	for (int j = 0; j < window_count; j++)
	{
		for (int i = 0; i < KEY_COUNT; i++)
		{
			if (key_green[i][j])
				Rectangle(hdc, keys[i][level][j].left, keys[i][level][j].top, keys[i][level][j].right, keys[i][level][j].bottom);
		}
	}

	SelectObject(hdc, oldPen);
	DeleteObject(pen);
	SelectObject(hdc, oldBrush);
	DeleteObject(brush);

	SetBkMode(hdc, TRANSPARENT);

	for (int i = 0; i < KEY_COUNT; i++)
		DrawText(hdc, key_letters[i], -1, &keys[i][0][0], DT_CENTER | DT_VCENTER | DT_NOCLIP | DT_SINGLELINE);

	EndPaint(hWnd, &ps);
}

void PaintChild(HWND hWnd, int win_no)
{
	//HFONT hFont = CreateFont(60, 0, 0, 0, FW_HEAVY, FALSE, TRUE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, L"Arial");

	//SendMessage(hwnd[0], WM_SETFONT, WPARAM(hFont), TRUE);
	RECT rect;
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hWnd, &ps);

	HPEN pen = CreatePen(PS_SOLID, 2, RGB(220, 220, 220));
	HPEN oldPen = (HPEN)SelectObject(hdc, pen);
	HBRUSH brush = CreateSolidBrush(RGB(251, 252, 255));
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

	for (int i = 0; i < word_count; i++)
		for (int j = 0; j < WORD_LEN; j++)
			if (white[i][j][win_no])
				RoundRect(hdc, (j + 1) * tile_margin + j * tile_size, (i + 1) * tile_margin + i * tile_size,
					(j + 1) * tile_margin + (j + 1) * tile_size, (i + 1) * tile_margin + (i + 1) * tile_size, tile_margin, tile_margin);

	DeleteObject(pen);
	DeleteObject(brush);

	pen = CreatePen(PS_SOLID, 2, RGB(164, 174, 196));
	oldPen = (HPEN)SelectObject(hdc, pen);
	brush = CreateSolidBrush(RGB(164, 174, 196));
	oldBrush = (HBRUSH)SelectObject(hdc, brush);

	for (int i = 0; i < word_count; i++)
		for (int j = 0; j < WORD_LEN; j++)
			if (grey[i][j][win_no])
				RoundRect(hdc, (j + 1) * tile_margin + j * tile_size, (i + 1) * tile_margin + i * tile_size,
					(j + 1) * tile_margin + (j + 1) * tile_size, (i + 1) * tile_margin + (i + 1) * tile_size, tile_margin, tile_margin);

	DeleteObject(pen);
	DeleteObject(brush);

	pen = CreatePen(PS_SOLID, 2, RGB(243, 194, 55));
	oldPen = (HPEN)SelectObject(hdc, pen);
	brush = CreateSolidBrush(RGB(243, 194, 55));
	oldBrush = (HBRUSH)SelectObject(hdc, brush);

	for (int i = 0; i < word_count; i++)
		for (int j = 0; j < WORD_LEN; j++)
			if (yellow[i][j][win_no])
				RoundRect(hdc, (j + 1) * tile_margin + j * tile_size, (i + 1) * tile_margin + i * tile_size,
					(j + 1) * tile_margin + (j + 1) * tile_size, (i + 1) * tile_margin + (i + 1) * tile_size, tile_margin, tile_margin);

	//SelectObject(hdc, oldPen);
	DeleteObject(pen);
	//SelectObject(hdc, oldBrush);
	DeleteObject(brush);

	pen = CreatePen(PS_SOLID, 2, RGB(121, 184, 81));
	oldPen = (HPEN)SelectObject(hdc, pen);
	brush = CreateSolidBrush(RGB(121, 184, 81));
	oldBrush = (HBRUSH)SelectObject(hdc, brush);

	for (int i = 0; i < word_count; i++)
		for (int j = 0; j < WORD_LEN; j++)
			if (green[i][j][win_no])
				RoundRect(hdc, (j + 1) * tile_margin + j * tile_size, (i + 1) * tile_margin + i * tile_size,
					(j + 1) * tile_margin + (j + 1) * tile_size, (i + 1) * tile_margin + (i + 1) * tile_size, tile_margin, tile_margin);

	SelectObject(hdc, oldPen);
	DeleteObject(pen);
	SelectObject(hdc, oldBrush);
	DeleteObject(brush);

	//GetClientRect(hWnd, &rect);
	//SetTextColor(hdc, RGB(0xFF, 0x00, 0x00));

	SetBkMode(hdc, TRANSPARENT);

	RECT rc;
	rc.left = 20;
	rc.top = 20;
	rc.right = 200;
	rc.bottom = 200;
	TCHAR sol[20];
	//solution = "romper";
	for (int i = 0; i < solution[win_no].size(); i++)
		sol[i] = solution[win_no][i];
	sol[solution[win_no].size()] = '\0';
	DrawText(hdc, sol, -1, &rc, DT_CENTER | DT_VCENTER | DT_NOCLIP | DT_SINGLELINE);

	//if (window_green[win_no]) {
	//	EndPaint(hWnd, &ps);
	//	return;
	//}
	

	for (int i = 0; i < 6; i++)
		for (int j = 0; j < WORD_LEN; j++)
			DrawText(hdc, letters[i][j], -1, &tiles[i][j], DT_CENTER | DT_VCENTER | DT_NOCLIP | DT_SINGLELINE);


	//brush = CreateSolidBrush(Color(0, 255, 0, 155));
	//oldBrush = (HBRUSH)SelectObject(hdc, brush);

	//HBITMAP bitmap = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP1));
	//HDC memDC = CreateCompatibleDC(hdc);
	//BITMAP oldBitmap = (HBITMAP)SelectObject(memDC, bitmap);
	//BitBlt(hdc, 0, 0, 48, 48, memDC, 0, 0, SRCCOPY);
	//StretchBlt(hdc, 200, 100, -200, 100, memDC, 0, 0, 48, 48, SRCCOPY);
	//SelectObject(memDC, oldBitmap);
	//DeleteObject(bitmap);
	//DeleteDC(memDC);


	EndPaint(hWnd, &ps);
}