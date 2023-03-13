#pragma once

#include "wordle.h"

void OnEnter(int win_no)
{
	//if (win_no > 0) {
	//	ofstream out;
	//	out.open("out.txt");
	//	out << window_count;
	//	out.close();
	//}

	if (j_tile < WORD_LEN - 1)
		return;

	char word[WORD_LEN + 1];
	for (int j = 0; j < WORD_LEN; j++)
		word[j] = tolower(letters[i_tile][j][0]);
	word[WORD_LEN] = '\0';

	if (dict.find(word) == dict.end())
	{
		for (int j = 0; j < WORD_LEN; j++)
			letters[i_tile][j][0] = '\0';

		if (win_no == window_count - 1)
			j_tile = -1;

		InvalidateRect(hwnd[win_no], NULL, TRUE);
		UpdateWindow(hwnd[win_no]); // not absolutely necessary ???
		return;
	}

	int green_count = 0;
	for (int j = 0; j < WORD_LEN; j++)
	{
		bool fl = false;
		if (word[j] == solution[win_no][j])
		{
			green_count++;
			fl = true;
			white[i_tile][j][win_no] = false;
			green[i_tile][j][win_no] = true;

			for (int k = 0; k < KEY_COUNT; k++)
			{
				if (key_letters[k][0] == letters[i_tile][j][0])
				{
					key_white[k][win_no] = false;
					key_green[k][win_no] = true;

					//ofstream out; out.open("out.txt"); out << "green\n"<<win_no; out.close();
				}
			}
		}
		for (int i = 0; i < WORD_LEN; i++)
		{
			if (word[j] == solution[win_no][i])
			{
				fl = true;
				white[i_tile][j][win_no] = false;
				yellow[i_tile][j][win_no] = true;

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
			white[i_tile][j][win_no] = false;
			grey[i_tile][j][win_no] = true;

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

	//for (int i = 0; i < window_count; i++)
	//{
	//	InvalidateRect(hwnd[i], NULL, TRUE);
	//	UpdateWindow(hwnd[i]); // not absolutely necessary ???
	//}

	InvalidateRect(hwnd[win_no], NULL, TRUE);
	UpdateWindow(hwnd[win_no]); // not absolutely necessary ???

	InvalidateRect(hwnd_main, NULL, TRUE);
	UpdateWindow(hwnd_main); // not absolutely necessary ???
}

void OnBackspace()
{
	if (j_tile == -1)
		return;
	if (j_tile == WORD_LEN)
		j_tile--;
	letters[i_tile][j_tile--][0] = '\0';
	if (j_tile < -1)
		j_tile = -1;

	for (int i = 0; i < window_count; i++)
	{
		InvalidateRect(hwnd[i], NULL, TRUE);
		UpdateWindow(hwnd[i]); // not absolutely necessary ???
	}
}

void OnChar(WPARAM wParam)
{
	if (!isalpha((TCHAR)wParam))
		return;

	if (j_tile + 1 < WORD_LEN)
		j_tile++;

	letters[i_tile][j_tile][0] = toupper((TCHAR)wParam);
	letters[i_tile][j_tile][1] = '\0';

	for (int i = 0; i < window_count; i++)
	{
		InvalidateRect(hwnd[i], NULL, TRUE);
		UpdateWindow(hwnd[i]); // not absolutely necessary ???
	}
}

void GetTextInfoForKeyMsg(WPARAM wParam, const TCHAR* msgName, TCHAR* buf, int bufSize)
{
	static int counter = 0;
	counter++;
	_stprintf_s(buf, bufSize, _T("%s key: %d ( counter : %d)"), msgName, wParam, counter);
}