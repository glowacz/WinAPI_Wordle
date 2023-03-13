#pragma once

#include "wordle.h"
#include <wingdi.h>

void OverlayGreen(HWND hWnd, int win_no) // hWnd is handle to window to be overlayed by a green semitransparent window
{
	RECT rect;
	GetWindowRect(hWnd, &rect);

	ofstream out; out.open("out.txt"); out <<rect.left<<"\n" << rect.top << "\n" << rect.right << "\n" << rect.bottom << "\n"; out.close();

	//PAINTSTRUCT ps;
	//HDC hdc = BeginPaint(hWnd, &ps);

	//HBITMAP bitmap = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP2));
	//HDC memDC = CreateCompatibleDC(hdc);
	//HBITMAP oldBitmap = (HBITMAP)SelectObject(memDC, bitmap);
	//
	//BLENDFUNCTION bf;
	//bf.BlendOp = AC_SRC_OVER;
	//bf.BlendFlags = 0;
	//bf.AlphaFormat = AC_SRC_ALPHA;
	//bf.SourceConstantAlpha = 255;

	////AlphaBlend(hdc, 0, 0, rect.right - rect.left, rect.bottom - rect.top, memDC, 0, 0, rect.right - rect.left, rect.bottom - rect.top, bf);
	//BitBlt(hdc, 0, 0, rect.right - rect.left, rect.bottom - rect.top, memDC, 0, 0, SRCCOPY);
	////StretchBlt(hdc, 200, 100, -200, 100, memDC, 0, 0, 48, 48, SRCCOPY);
	//SelectObject(memDC, oldBitmap);
	//DeleteObject(bitmap);
	//DeleteDC(memDC);



	//// Create an array of TRIVERTEX structures that describe 
	//// positional and color values for each vertex. For a rectangle, 
	//// only two vertices need to be defined: upper-left and lower-right. 
	//TRIVERTEX vertex[2];
	//vertex[0].x = 0;
	//vertex[0].y = 0;
	//vertex[0].Red = 0x0000;
	//vertex[0].Green = 0x8000;
	//vertex[0].Blue = 0x8000;
	//vertex[0].Alpha = 0x0000;

	//vertex[1].x = 300;
	//vertex[1].y = 80;
	//vertex[1].Red = 0x0000;
	//vertex[1].Green = 0xd000;
	//vertex[1].Blue = 0xd000;
	//vertex[1].Alpha = 0x0000;

	//// Create a GRADIENT_RECT structure that 
	//// references the TRIVERTEX vertices. 
	//GRADIENT_RECT gRect;
	//gRect.UpperLeft = 0;
	//gRect.LowerRight = 1;

	//// Draw a shaded rectangle. 
	//GradientFill(hdc, vertex, 2, &gRect, 1, GRADIENT_FILL_RECT_H);

	//HPEN pen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	//HPEN oldPen = (HPEN)SelectObject(hdc, pen);
	//HBRUSH brush = CreateSolidBrush(Color(0, 255, 0, 50));
	//HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

	////Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
	//Rectangle(hdc, 0, 0, rect.right - rect.left, rect.bottom - rect.top);
	////Rectangle(hdc, 10, 10, 100, 100);

	//SelectObject(hdc, oldPen);
	//DeleteObject(pen);
	//SelectObject(hdc, oldBrush);
	//DeleteObject(brush);

	//RECT rect;
	//GetWindowRect(hWnd, &rect);

	//SetBkMode(hdc, TRANSPARENT);

	//EndPaint(hWnd, &ps);

	//HBRUSH m_field_brush = CreateSolidBrush(RGB(121, 184, 81));

	//hwnd_overlay[0] = CreateWindowW(ClassOv, TitleOv, WS_CHILD | WS_VISIBLE | SS_CENTER, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, hWnd, nullptr, hInst, nullptr);
	
	hwnd_overlay[0] = CreateWindowW(ClassOv, TitleOv, WS_POPUP, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, hWnd, nullptr, hInst, nullptr);
	//hwnd_overlay[0] = CreateWindowW(ClassOv, TitleOv, WS_POPUP, 0, 0, 100, 100, hWnd, nullptr, hInst, nullptr);
	//hwnd_overlay[0] = CreateWindowW(ClassOv, TitleOv, WS_OVERLAPPED, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, hWnd, nullptr, hInst, nullptr);
	//hwnd_overlay[0] = CreateWindowW(ClassOv, TitleOv, WS_OVERLAPPED | CW_USEDEFAULT | CW_USEDEFAULT, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, hWnd, nullptr, hInst, nullptr);
	//hwnd_overlay[0] = CreateWindowW(ClassOv, TitleOv, WS_OVERLAPPED, rect.left + 20, rect.top + 20, rect.right - rect.left - 20, rect.bottom - rect.top - 20, hWnd, nullptr, hInst, nullptr);
	
	//hwnd[0] = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPED, CW_USEDEFAULT, CW_USEDEFAULT, w_child, h_easy, hWnd, nullptr, hInst, nullptr);
	//SetWindowLong(hWnd, GWL_EXSTYLE, GetWindowLong(hWnd, GWL_EXSTYLE) | WS_EX_LAYERED);
	
	SetWindowLong(hwnd_overlay[0], GWL_EXSTYLE, GetWindowLong(hWnd, GWL_EXSTYLE) | WS_EX_LAYERED);
	//SetLayeredWindowAttributes(hWnd, 0, (255 * 50) / 100, LWA_ALPHA);
	SetLayeredWindowAttributes(hwnd_overlay[0], 0, (255 * 50) / 100, LWA_ALPHA);

	ShowWindow(hwnd_overlay[0], show);
	UpdateWindow(hwnd_overlay[0]);

	/*RECT rect;
	GetWindowRect(hWnd, &rect);

	MoveWindow(hwnd_overlay[0], rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, true);*/
}