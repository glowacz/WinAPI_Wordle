#pragma once

#include "wordle.h"

void ReadTxt()
{
	ifstream in;
	in.open("Wordle.txt");

	int i = 0;
	while (in >> words[i]) dict.insert(words[i++]);
	in.close();
}

void SetKeyCords()
{
	SetKeyLetters();

	for (int i = 0; i < 10; i++)
	{
		keys[i][0][0].left = (i + 1) * tile_margin + i * tile_size;
		keys[i][0][0].top = tile_margin;
		keys[i][0][0].right = (i + 1) * tile_margin + (i + 1) * tile_size;
		keys[i][0][0].bottom = tile_margin + tile_size;
	}

	for (int i = 0; i < 9; i++)
	{
		keys[i + 10][0][0].left = (i + 1) * tile_margin + i * tile_size + tile_size / 2;
		keys[i + 10][0][0].top = 2 * tile_margin + tile_size;
		keys[i + 10][0][0].right = (i + 1) * tile_margin + (i + 1) * tile_size + tile_size / 2;
		keys[i + 10][0][0].bottom = 2 * tile_margin + 2 * tile_size;
	}

	for (int i = 0; i < 7; i++)
	{
		keys[i + 19][0][0].left = (i + 2) * tile_margin + i * tile_size + tile_size / 2 + tile_size;
		keys[i + 19][0][0].top = 3 * tile_margin + 2 * tile_size;
		keys[i + 19][0][0].right = (i + 2) * tile_margin + (i + 1) * tile_size + tile_size / 2 + tile_size;
		keys[i + 19][0][0].bottom = 3 * tile_margin + 3 * tile_size;
	}

	// MEDIUM DIFFICULTY - EACH KEY SPLIT VERTICALLY IN HALF
	for (int i = 0; i < KEY_COUNT; i++)
	{
		keys[i][1][0] = keys[i][0][0];
		keys[i][1][0].right = (keys[i][0][0].left + keys[i][0][0].right) / 2;

		keys[i][1][1] = keys[i][0][0];
		keys[i][1][1].left = (keys[i][0][0].left + keys[i][0][0].right) / 2;
	}

	// HARD DIFFICULTY - EACH KEY SPLIT IN FOUR
	for (int i = 0; i < KEY_COUNT; i++)
	{
		keys[i][2][0] = keys[i][1][0];
		keys[i][2][0].bottom = (keys[i][1][0].top + keys[i][1][0].bottom) / 2;

		keys[i][2][1] = keys[i][1][1];
		keys[i][2][1].bottom = (keys[i][1][0].top + keys[i][1][0].bottom) / 2;

		keys[i][2][2] = keys[i][1][0];
		keys[i][2][2].top = (keys[i][0][0].top + keys[i][0][0].bottom) / 2;

		keys[i][2][3] = keys[i][1][1];
		keys[i][2][3].top = (keys[i][0][0].top + keys[i][0][0].bottom) / 2;
	}
}

void SetKeyLetters()
{
	key_letters[0] = L"Q";
	key_letters[1] = L"W";
	key_letters[2] = L"E";
	key_letters[3] = L"R";
	key_letters[4] = L"T";
	key_letters[5] = L"Y";
	key_letters[6] = L"U";
	key_letters[7] = L"I";
	key_letters[8] = L"O";
	key_letters[9] = L"P";
	key_letters[10] = L"A";
	key_letters[11] = L"S";
	key_letters[12] = L"D";
	key_letters[13] = L"F";
	key_letters[14] = L"G";
	key_letters[15] = L"H";
	key_letters[16] = L"J";
	key_letters[17] = L"K";
	key_letters[18] = L"L";
	key_letters[19] = L"Z";
	key_letters[20] = L"X";
	key_letters[21] = L"C";
	key_letters[22] = L"V";
	key_letters[23] = L"B";
	key_letters[24] = L"N";
	key_letters[25] = L"M";
}

void SetTileCords()
{
	for (int i = 0; i < MAX_WORD_COUNT; i++)
	{
		for (int j = 0; j < WORD_LEN; j++)
		{
			tiles[i][j].left = (j + 1) * tile_margin + j * tile_size;
			tiles[i][j].top = (i + 1) * tile_margin + i * tile_size;
			tiles[i][j].right = (j + 1) * tile_margin + (j + 1) * tile_size;
			tiles[i][j].bottom = (i + 1) * tile_margin + (i + 1) * tile_size;
		}
	}
}

void SetWhite()
{
	for (int win_no = 0; win_no < MAX_WIN_COUNT; win_no++)
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

void SetPaintAll()
{
	for (int win_no = 0; win_no < window_count; win_no++) {
		for (int i = 0; i < MAX_WORD_COUNT; i++)
			for (int j = 0; j < WORD_LEN; j++)
				paint_rect[i][j][win_no] = true;
	}
}

void SetPaintRow(int row, int win_no)
{
    //if (window_green[win_no])
    //    return;
	//for (int win_no = 0; win_no < window_count; win_no++) {
			for (int j = 0; j < WORD_LEN; j++)
				paint_rect[row][j][win_no] = true;
	//}
}