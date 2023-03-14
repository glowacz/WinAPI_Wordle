#pragma once

#include "wordle.h"

void StartAnimation(int win_no, int row)
{
	getting_smaller = {row, 0};
	getting_bigger = {row, -1};
	SetTimer(hwnd[win_no], 1, 1, nullptr);
}

void Animate(int row)
{
	if (getting_bigger.second == WORD_LEN - 1 &&
		tiles[getting_bigger.first][getting_bigger.second].bottom - tiles[getting_bigger.first][getting_bigger.second].top >= tile_size)
		return;

	ChangeTileSize();

	if (tiles[getting_smaller.first][getting_smaller.second].bottom - tiles[getting_smaller.first][getting_smaller.second].top <= 0)
	{
		getting_bigger = getting_smaller;

		for (int win_no = 0; win_no < window_count; win_no++)
		{
			white[getting_bigger.first][getting_bigger.second][win_no] = false;
			if (temp_colors[getting_bigger.second][win_no] == 'g')
				green[getting_bigger.first][getting_bigger.second][win_no] = true;
			else if (temp_colors[getting_bigger.second][win_no] == 'y')
				yellow[getting_bigger.first][getting_bigger.second][win_no] = true;
			else if (temp_colors[getting_bigger.second][win_no] == 's')
				grey[getting_bigger.first][getting_bigger.second][win_no] = true;
		}
		getting_smaller.second++;
	}

	SetTimer(hwnd[0], 1, 15, nullptr);
}

void ChangeTileSize()
{
	for (int win_no = 0; win_no < window_count; win_no++)
	{
		InvalidateRect(hwnd[win_no], NULL, TRUE);
		//InvalidateRect(hwnd[win_no], &tiles[getting_smaller.first][getting_smaller.second], TRUE);
		UpdateWindow(hwnd[win_no]); // not absolutely necessary ???
	}

	//InvalidateRect(hwnd[0], NULL, TRUE);

	if (getting_smaller.second < WORD_LEN)
	{
		tiles[getting_smaller.first][getting_smaller.second].bottom--;
		tiles[getting_smaller.first][getting_smaller.second].top++;
	}

	if (getting_bigger.second != -1)
	{
		tiles[getting_bigger.first][getting_bigger.second].bottom++;
		tiles[getting_bigger.first][getting_bigger.second].top--;
	}
}