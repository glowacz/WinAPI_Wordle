#pragma once

#include "wordle.h"

void OnEnter(int win_no)
{
	if (j_tile < WORD_LEN - 1)
		return;

	char word[WORD_LEN + 1];
	for (int j = 0; j < WORD_LEN; j++)
		word[j] = tolower(letters[i_tile][j][0]);
	word[WORD_LEN] = '\0';

	if (dict.find(word) == dict.end())
	{
		//out.open("out.txt", ios_base::app);
		//out <<"if: " << word << "\n"; out.close();

		for (int j = 0; j < WORD_LEN; j++)
			letters[i_tile][j][0] = '\0';

		if (win_no == window_count - 1)
			j_tile = -1;

		SetPaintRow(i_tile, win_no);
		InvalidateRect(hwnd[win_no], NULL, FALSE);
		UpdateWindow(hwnd[win_no]); // not absolutely necessary ???
		return;
	}

	//out.open("out.txt", ios_base::app);
	//out << "enter2: " << win_no << "  " << word << "\n"; out.close();

	int green_count = 0;
	for (int j = 0; j < WORD_LEN; j++)
	{
		bool fl = false;
		if (word[j] == solution[win_no][j])
		{
			green_count++;
			fl = true;
			//white[i_tile][j][win_no] = false;
			//green[i_tile][j][win_no] = true;
			temp_colors[j][win_no] = 'g';

			for (int k = 0; k < KEY_COUNT; k++)
			{
				if (key_letters[k][0] == letters[i_tile][j][0])
				{
					key_white[k][win_no] = false;
					key_green[k][win_no] = true;
				}
			}
		}
		for (int i = 0; i < WORD_LEN; i++)
		{
			if (word[j] == solution[win_no][i])
			{
				fl = true;
				//white[i_tile][j][win_no] = false;
				//yellow[i_tile][j][win_no] = true;
				if(temp_colors[j][win_no] != 'g')
					temp_colors[j][win_no] = 'y';

				for (int k = 0; k < KEY_COUNT; k++)
				{
					if (key_letters[k][0] == letters[i_tile][j][0])
					{
						key_white[k][win_no] = false;
						key_yellow[k][win_no] = true;
					}
				}
			}
		}
		if (!fl)
		{
			//white[i_tile][j][win_no] = false;
			//grey[i_tile][j][win_no] = true;

			temp_colors[j][win_no] = 's';

			for (int k = 0; k < KEY_COUNT; k++)
			{
				if (key_letters[k][0] == letters[i_tile][j][0])
				{
					key_white[k][win_no] = false;
					key_grey[k][win_no] = true;
				}
			}
		}
	}
	
	if (win_no == window_count - 1)
	{
        InvalidateRect(hwnd_keyboard, NULL, TRUE);
        UpdateWindow(hwnd_keyboard); // not absolutely necessary ???

		StartAnimation(0, i_tile);
		i_tile++;
		j_tile = -1;
	}	

    if (green_count == WORD_LEN)
    {
        window_green[win_no] = true;
        OverlayGreen(hwnd[win_no], win_no);
    }

	//if (i_tile == 5)
	//{
	//	// Set WS_EX_LAYERED on this window
	//	SetWindowLong(hwnd[0], GWL_EXSTYLE, GetWindowLong(hwnd[0], GWL_EXSTYLE) | WS_EX_LAYERED);
	//	// Make this window 50% alpha
	//	SetLayeredWindowAttributes(hwnd[0], 0, (255 * 50) / 100, LWA_ALPHA);
	//}
}

void OnBackspace()
{
	if (j_tile == -1)
		return;

	if (j_tile >= WORD_LEN)
		j_tile = WORD_LEN - 1;

	letters[i_tile][j_tile][0] = '\0';

	//paint_rect[i_tile][j_tile][win_no] = true;
	//InvalidateRect(hwnd[win_no], NULL, FALSE);
	//UpdateWindow(hwnd[win_no]); // not absolutely necessary ???

	for (int i = 0; i < window_count; i++)
	{
		paint_rect[i_tile][j_tile][i] = true;
		InvalidateRect(hwnd[i], NULL, FALSE);
		UpdateWindow(hwnd[i]); // not absolutely necessary ???
	}

	//if(win_no == window_count - 1)
		j_tile--;

	if (j_tile < -1)
		j_tile = -1;
}

void OnChar(WPARAM wParam)
{
	if (!isalpha((TCHAR)wParam))
		return;

	if (j_tile + 1 < WORD_LEN)
		j_tile++;

	letters[i_tile][j_tile][0] = toupper((TCHAR)wParam);
	letters[i_tile][j_tile][1] = '\0';

	/*if (win_no == 0)
	{
		if (j_tile + 1 < WORD_LEN)
			j_tile++;

		letters[i_tile][j_tile][0] = toupper((TCHAR)wParam);
		letters[i_tile][j_tile][1] = '\0';
	}*/

	//paint_rect[i_tile][j_tile][win_no] = true;
	//InvalidateRect(hwnd[win_no], NULL, FALSE);
	//UpdateWindow(hwnd[win_no]); // not absolutely necessary ???

	for (int i = 0; i < window_count; i++)
	{
        if (window_green[i])
            continue;
		paint_rect[i_tile][j_tile][i] = true;
		InvalidateRect(hwnd[i], NULL, FALSE);
		UpdateWindow(hwnd[i]); // not absolutely necessary ???
	}
}

void GetTextInfoForKeyMsg(WPARAM wParam, const TCHAR* msgName, TCHAR* buf, int bufSize)
{
	static int counter = 0;
	counter++;
	_stprintf_s(buf, bufSize, _T("%s key: %d ( counter : %d)"), msgName, wParam, counter);
}