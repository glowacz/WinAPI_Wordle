#pragma once
#include "wordle.h"
#include "paints.h"
#include "init.h"
#include "my_init.h"
#include "levels.h"
#include "keys.h"
#include "overlays.h"
#include "animation.h"

using namespace std;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	show = nCmdShow;
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	SetTileCords();
	SetKeyCords();

	ReadTxt();

	RegisterClassKeyboard(hInstance);
	RegisterClassBoard(hInstance);
	RegisterClassOverlay(hInstance);

	hInst = hInstance;

	//if (!InitInstance(hInstance, nCmdShow))
	//	return FALSE;

	InitInstance();

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
	static auto drawTime1 = chrono::high_resolution_clock::now(), drawTime2 = chrono::high_resolution_clock::now();
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
			InvalidateRect(hwnd_keyboard, NULL, TRUE);
			break;
		case IDM_MEDIUM:
			Medium(hWnd);
			InvalidateRect(hwnd_keyboard, NULL, TRUE);
			break;
		case IDM_HARD:
			Hard(hWnd);
			InvalidateRect(hwnd_keyboard, NULL, TRUE);
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
	//	if( DefWindowProc(hWnd, message, wParam, lParam) == HTCLIENT)
	//		return HTCAPTION;
	//	return DefWindowProc(hWnd, message, wParam, lParam);	
	//}
	//break;

	case WM_CREATE:
	{
		startTime = chrono::high_resolution_clock::now();
		SetTimer(hwnd_keyboard, 7, 2, NULL); // Creating first timer
	}
	break;

	case WM_TIMER:
	{

		if (wParam == 1) // animation
		{
			//drawTime1 = chrono::high_resolution_clock::now();
			//auto drawDuration = chrono::duration_cast<chrono::milliseconds>(drawTime1 - drawTime2);
			//drawTime2 = chrono::high_resolution_clock::now();
			//auto elapsedDur = drawDuration.count();

            ofstream out; out.open("logs.txt");
            out <<"anim timer"; out.close();
			
			Animate(getting_smaller.first);
			break;
		}

		// timer
		auto curTime = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::milliseconds>(curTime - startTime);
		auto elapsed = duration.count();
		auto sec = elapsed / 1000;

		TCHAR s[256];
		_stprintf_s(s, 256, _T("WORDLE - KEYBOARD. Elapsed time : %d,%d"), (int)sec, (int)elapsed % 1000);
		SetWindowText(hwnd_keyboard, s);
		SetTimer(hwnd_keyboard, 2, 1, NULL); // Creating another timer
	}
	break;

	case WM_PAINT:
	{
		//if (paint_keyboard) 
		if (hWnd == hwnd_keyboard) 
		{
			PaintKeyboard(hwnd_keyboard);
			//paint_keyboard = false;
		}

		for (int i = 0; i < window_count; i++)
		{
			if(hwnd[i] == hWnd)
				PaintChild(hwnd[i], i);
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
		{
			OnChar(wParam);
		}
		break;

		case WM_KEYDOWN:
		{
			switch (wParam)
			{
				case 13: // Enter
				{
					for (int win_no = 0; win_no < window_count; win_no++)
						OnEnter(win_no);
				}
				break;

				case 8: // Backspace
				{
					//for (int win_no = 0; win_no < window_count; win_no++)
					//	if (hwnd[win_no] == hWnd)
					OnBackspace();
				}
				break;

				default:
					;
				break;
			}	
		}
		break;
#pragma endregion keyboard_keys

        case WM_NCHITTEST: 
        {
            if (DefWindowProc(hWnd, message, wParam, lParam) == HTCLIENT)
                return HTCAPTION;
            return DefWindowProc(hWnd, message, wParam, lParam);
        }

        //case WM_SIZE:
        //{
        //    if (wParam == SIZE_MINIMIZED)
        //    {
        //        ofstream out; out.open("out.txt", ios_base::app);
        //        if(hWnd = hwnd_keyboard)
        //            out << "hide keyboard" << "\n";
        //            
        //        for (int win_no = 0; win_no < window_count; win_no++)
        //            if(hwnd[win_no] == hWnd)
        //                out << "hide" <<win_no << "\n";
        //        out.close();

        //        for (int win_no = 0; win_no < window_count; win_no++)
        //            ShowWindow(hwnd[win_no], SW_HIDE);
        //        break;
        //    }
        //    //else if(wParam == SI)

        //    ofstream out; out.open("out.txt", ios_base::app);
        //    
        //    if (hWnd = hwnd_keyboard)
        //        out << "show keyboard" << "\n";
        //    else
        //        out << "show board" << "\n";

        //    out.close();
        //        
        //    SetPaintAll();
        //        
        //    for (int win_no = 0; win_no < window_count; win_no++) 
        //    {
        //        InvalidateRect(hwnd[win_no], NULL, TRUE);
        //        ShowWindow(hwnd[win_no], SW_SHOW);
        //        UpdateWindow(hwnd[win_no]);
        //     
        //    }
        //    //InvalidateRect(hwnd_keyboard, NULL, TRUE);
        //}
        //break;

        //case WM_SHOWWINDOW:
        //{
        //    if (wParam == FALSE)
        //    {
        //        ofstream out; out.open("out.txt", ios_base::app);
        //        out << "hide keyboard" << "\n"; out.close();
        //        
        //        for (int win_no = 0; win_no < window_count; win_no++)
        //            if(hwnd[win_no] == hWnd)
        //                out << "hide" <<win_no << "\n"; out.close();

        //        for (int win_no = 0; win_no < window_count; win_no++)
        //            ShowWindow(hwnd[win_no], SW_HIDE);
        //        break;
        //    }

        //    ofstream out; out.open("out.txt", ios_base::app);
        //    out << "show" << "\n"; out.close();
        //    
        //    SetPaintAll();
        //    
        //    for (int win_no = 0; win_no < window_count; win_no++) 
        //    {
        //        InvalidateRect(hwnd[win_no], NULL, TRUE);
        //        //ShowWindow(hwnd[win_no], SW_SHOW);
        //        //UpdateWindow(hwnd[win_no]);
        //    }
        //    //InvalidateRect(hwnd_keyboard, NULL, TRUE);
        //}
        //break;

		//case WM_CTLCOLORSTATIC:
		//{
		//	
		//	HBRUSH m_field_brush = CreateSolidBrush(RGB(121, 184, 81));
		//	return reinterpret_cast<INT_PTR>(m_field_brush);
		//}

        //case WM_CLOSE:
        //{
        //    ofstream init; init.open("Wordle.ini");
        //    init << window_count; init.close();
        //}

		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}