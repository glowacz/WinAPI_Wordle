#pragma once
#include "wordle.h"
#include "paints.h"
#include "init.h"
#include "my_init.h"
#include "levels.h"
#include "keys.h"
#include "overlays.h"

using namespace std;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	show = nCmdShow;
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	LoadStringW(hInstance, IDC_TUTORIAL, szWindowClass, MAX_LOADSTRING);
	
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);

	std::wstring title(L"WORDLE - KEYBOARD\0");
	title.copy(szTitle, title.size());

	std::wstring className(L"tutorial\0");
	className.copy(szWindowClass, className.size());

	title = L"\0";
	title.copy(TitleOv, title.size());

	className = L"Overlay\0";
	className.copy(ClassOv, className.size());

	SetTileCords();
	SetKeyCords();

	ReadTxt();

	MyRegisterClass(hInstance);
	RegisterClassOverlay(hInstance);

	if (!InitInstance(hInstance, nCmdShow))
		return FALSE;

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TUTORIAL));

	MSG msg;

	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return static_cast<int>(msg.wParam);
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static auto startTime = chrono::high_resolution_clock::now();
	const int bufSize = 256;
	TCHAR buf[bufSize];

	switch (message)
	{
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		switch (wmId)
		{
		case IDM_EASY:
			Easy(hWnd);
			InvalidateRect(hwnd_main, NULL, TRUE);
			break;
		case IDM_MEDIUM:
			Medium(hWnd);
			InvalidateRect(hwnd_main, NULL, TRUE);
			break;
		case IDM_HARD:
			Hard(hWnd);
			InvalidateRect(hwnd_main, NULL, TRUE);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;

	case WM_SIZING: // idiotic funtionality ... (blocks resizing)
	{
		RECT* rc = (RECT*)lParam;
		if (wParam == WMSZ_BOTTOM || wParam == WMSZ_BOTTOMLEFT || wParam == WMSZ_BOTTOMRIGHT || wParam == WMSZ_TOP || wParam == WMSZ_TOPLEFT || wParam == WMSZ_TOPRIGHT) {
			rc->right = rc->left + rc->bottom - rc->top;
		}
		else {
			rc->bottom = rc->top + rc->right - rc->left;
		}
	}
	break;

	//case WM_NCHITTEST:
	//{
	//	//if( DefWindowProc(hWnd, message, wParam, lParam) == HTCLIENT)
	//	////if (lParam == HTCLIENT)
	//	//{
	//	//	return HTCAPTION;
	//	//}
	//	//else
	//	//{
	//	//	ofstream out; out.open("out.txt"); out << lParam; out.close();
	//	//}
	//		
	//}
	//break;

	case WM_CREATE:
	{
		startTime = chrono::high_resolution_clock::now();
		SetTimer(hWnd, 7, 1, NULL); // Creating first timer
	}
	break;

	case WM_TIMER:
	{
		auto curTime = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::milliseconds>(curTime - startTime);
		auto elapsed = duration.count();
		auto sec = elapsed / 1000;

		TCHAR s[256];
		_stprintf_s(s, 256, _T(" Elapsed time : %d,%d"), (int)sec, (int)elapsed % 1000);
		SetWindowText(hWnd, s);
		SetTimer(hWnd, 7, 1, NULL); // Creating another timer
	}
	break;

	case WM_PAINT:
	{
		PaintKeyboard(hwnd_main);
		for (int i = 0; i < window_count; i++)
		{
			//if(!window_green[i])
			PaintChild(hwnd[i], i);
			//if (window_green[i])
			//{
			//	OverlayGreen(hwnd[i], i);
			//}
			//else
			//{
			//	PaintChild(hwnd[i], i);
			//}
				
		}
	}
	break;

	//case WM_ERASEBKGND:
	//{
	//	SetBkColor(GetDC(hwnd[0]), RGB(255, 0, 0));
	//}
	//break;
	
#pragma region keyboard_keys
		case WM_CHAR:
			OnChar(wParam);
		break;

		case WM_KEYDOWN:
		{
			GetTextInfoForKeyMsg(wParam, _T(" KEYDOWN "), buf, bufSize);
			SetWindowText(hWnd, buf);
			switch (wParam)
			{
				case 13: // Enter
				{
					for (int win_no = 0; win_no < window_count; win_no++)
						OnEnter(win_no);
				}
				break;

				case 8: // Backspace
					OnBackspace();
				break;

				default:
					;
				break;
			}	
		}
		break;
#pragma endregion keyboard_keys

		case WM_CTLCOLORSTATIC:
		{
			ofstream out; out.open("out.txt"); out <<"brush"; out.close();
			HBRUSH m_field_brush = CreateSolidBrush(RGB(121, 184, 81));
			return reinterpret_cast<INT_PTR>(m_field_brush);
		}

		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}