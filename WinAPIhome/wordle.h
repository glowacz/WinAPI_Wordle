#pragma once

//#include "wingdi.h"

#include "framework.h"
#include "resource.h"
#include <tchar.h>
#include <string>
#include <list>
#include <chrono>
#include <fstream>
#include <time.h>
#include <random>
#include <set>

#define MAX_LOADSTRING 100

using namespace std;

const int width = 616 + 16, height = 189 + 100, w_child = 311 + 16, h_easy = 372, h_medium = 494 + 2 * 8 * 4, h_hard = 616 + 64;
const int tile_size = 55, tile_margin = 6;
const int WORD_LEN = 5, MAX_WORD_COUNT = 10;
const int KEY_COUNT = 26;
const int MAX_WIN_COUNT = 4;
const int DICT_SIZE = 16825;

int show, window_count, word_count, level;
HWND hwnd_main, hwnd[MAX_WIN_COUNT], hwnd_overlay[2];

bool window_green[MAX_WIN_COUNT];

// keyboard keys
RECT keys[KEY_COUNT][MAX_WIN_COUNT][MAX_WIN_COUNT];
LPCWSTR key_letters[KEY_COUNT];
bool key_white[KEY_COUNT][MAX_WIN_COUNT], key_grey[KEY_COUNT][MAX_WIN_COUNT], key_yellow[KEY_COUNT][MAX_WIN_COUNT], key_green[KEY_COUNT][MAX_WIN_COUNT];

// tiles
RECT tiles[MAX_WORD_COUNT][WORD_LEN];
TCHAR letters[MAX_WORD_COUNT][WORD_LEN][2];
bool white[MAX_WORD_COUNT][WORD_LEN][MAX_WIN_COUNT], grey[MAX_WORD_COUNT][WORD_LEN][MAX_WIN_COUNT], 
	yellow[MAX_WORD_COUNT][WORD_LEN][MAX_WIN_COUNT], green[MAX_WORD_COUNT][WORD_LEN][MAX_WIN_COUNT];
int i_tile, j_tile;

// words
string words[DICT_SIZE];
string solution[MAX_WIN_COUNT];
set<string> dict;

// random
random_device rd;
mt19937 eng(chrono::steady_clock::now().time_since_epoch().count());

HINSTANCE hInst;
WCHAR szTitle[MAX_LOADSTRING], TitleOv[MAX_LOADSTRING];
WCHAR szWindowClass[MAX_LOADSTRING], ClassOv[MAX_LOADSTRING];

// my_init.h
void ReadTxt();
void SetKeyCords();
void SetTileCords();
void SetKeyLetters();

// keys.h
void OnEnter(int);
void OnBackspace();
void OnChar(WPARAM);
void GetTextInfoForKeyMsg(WPARAM wParam, const TCHAR* msgName, TCHAR* buf, int bufSize);

// paints.h
void PaintKeyboard(HWND hWnd);
void PaintChild(HWND, int);

// levels.h
void ChooseSol();
void Destroy_children();
void Easy(HWND hWnd);
void Medium(HWND hWnd);
void Hard(HWND hWnd);
void SetWhite();

// overlays.h
void OverlayGreen(HWND hWnd, int win_no);

// init.h
ATOM MyRegisterClass(HINSTANCE hInstance);
ATOM RegisterClassOverlay(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE, int);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK About(HWND, UINT, WPARAM, LPARAM);