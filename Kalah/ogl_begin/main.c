#include <windows.h>
#include <gl/gl.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include < string.h >
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#define hCon GetStdHandle(STD_OUTPUT_HANDLE)
#define infinity 10000
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))
double timenew;
double end;
double startnew;
char a[10000];
char b[10000];
int turn = 1;
double dif;

static struct stb_easy_font_info_struct {
	unsigned char advance;
	unsigned char h_seg;
	unsigned char v_seg;
} stb_easy_font_charinfo[96] = {
	{  6,  0,  0 },  {  3,  0,  0 },  {  5,  1,  1 },  {  7,  1,  4 },
	{  7,  3,  7 },  {  7,  6, 12 },  {  7,  8, 19 },  {  4, 16, 21 },
	{  4, 17, 22 },  {  4, 19, 23 },  { 23, 21, 24 },  { 23, 22, 31 },
	{ 20, 23, 34 },  { 22, 23, 36 },  { 19, 24, 36 },  { 21, 25, 36 },
	{  6, 25, 39 },  {  6, 27, 43 },  {  6, 28, 45 },  {  6, 30, 49 },
	{  6, 33, 53 },  {  6, 34, 57 },  {  6, 40, 58 },  {  6, 46, 59 },
	{  6, 47, 62 },  {  6, 55, 64 },  { 19, 57, 68 },  { 20, 59, 68 },
	{ 21, 61, 69 },  { 22, 66, 69 },  { 21, 68, 69 },  {  7, 73, 69 },
	{  9, 75, 74 },  {  6, 78, 81 },  {  6, 80, 85 },  {  6, 83, 90 },
	{  6, 85, 91 },  {  6, 87, 95 },  {  6, 90, 96 },  {  7, 92, 97 },
	{  6, 96,102 },  {  5, 97,106 },  {  6, 99,107 },  {  6,100,110 },
	{  6,100,115 },  {  7,101,116 },  {  6,101,121 },  {  6,101,125 },
	{  6,102,129 },  {  7,103,133 },  {  6,104,140 },  {  6,105,145 },
	{  7,107,149 },  {  6,108,151 },  {  7,109,155 },  {  7,109,160 },
	{  7,109,165 },  {  7,118,167 },  {  6,118,172 },  {  4,120,176 },
	{  6,122,177 },  {  4,122,181 },  { 23,124,182 },  { 22,129,182 },
	{  4,130,182 },  { 22,131,183 },  {  6,133,187 },  { 22,135,191 },
	{  6,137,192 },  { 22,139,196 },  {  6,144,197 },  { 22,147,198 },
	{  6,150,202 },  { 19,151,206 },  { 21,152,207 },  {  6,155,209 },
	{  3,160,210 },  { 23,160,211 },  { 22,164,216 },  { 22,165,220 },
	{ 22,167,224 },  { 22,169,228 },  { 21,171,232 },  { 21,173,233 },
	{  5,178,233 },  { 22,179,234 },  { 23,180,238 },  { 23,180,243 },
	{ 23,180,248 },  { 22,189,248 },  { 22,191,252 },  {  5,196,252 },
	{  3,203,252 },  {  5,203,253 },  { 22,210,253 },  {  0,214,253 },
};

static unsigned char stb_easy_font_hseg[214] = {
   97,37,69,84,28,51,2,18,10,49,98,41,65,25,81,105,33,9,97,1,97,37,37,36,
	81,10,98,107,3,100,3,99,58,51,4,99,58,8,73,81,10,50,98,8,73,81,4,10,50,
	98,8,25,33,65,81,10,50,17,65,97,25,33,25,49,9,65,20,68,1,65,25,49,41,
	11,105,13,101,76,10,50,10,50,98,11,99,10,98,11,50,99,11,50,11,99,8,57,
	58,3,99,99,107,10,10,11,10,99,11,5,100,41,65,57,41,65,9,17,81,97,3,107,
	9,97,1,97,33,25,9,25,41,100,41,26,82,42,98,27,83,42,98,26,51,82,8,41,
	35,8,10,26,82,114,42,1,114,8,9,73,57,81,41,97,18,8,8,25,26,26,82,26,82,
	26,82,41,25,33,82,26,49,73,35,90,17,81,41,65,57,41,65,25,81,90,114,20,
	84,73,57,41,49,25,33,65,81,9,97,1,97,25,33,65,81,57,33,25,41,25,
};

static unsigned char stb_easy_font_vseg[253] = {
   4,2,8,10,15,8,15,33,8,15,8,73,82,73,57,41,82,10,82,18,66,10,21,29,1,65,
	27,8,27,9,65,8,10,50,97,74,66,42,10,21,57,41,29,25,14,81,73,57,26,8,8,
	26,66,3,8,8,15,19,21,90,58,26,18,66,18,105,89,28,74,17,8,73,57,26,21,
	8,42,41,42,8,28,22,8,8,30,7,8,8,26,66,21,7,8,8,29,7,7,21,8,8,8,59,7,8,
	8,15,29,8,8,14,7,57,43,10,82,7,7,25,42,25,15,7,25,41,15,21,105,105,29,
	7,57,57,26,21,105,73,97,89,28,97,7,57,58,26,82,18,57,57,74,8,30,6,8,8,
	14,3,58,90,58,11,7,74,43,74,15,2,82,2,42,75,42,10,67,57,41,10,7,2,42,
	74,106,15,2,35,8,8,29,7,8,8,59,35,51,8,8,15,35,30,35,8,8,30,7,8,8,60,
	36,8,45,7,7,36,8,43,8,44,21,8,8,44,35,8,8,43,23,8,8,43,35,8,8,31,21,15,
	20,8,8,28,18,58,89,58,26,21,89,73,89,29,20,8,8,30,7,
};

typedef struct
{
	unsigned char c[4];
} stb_easy_font_color;

static int stb_easy_font_draw_segs(float x, float y, unsigned char* segs, int num_segs, int vertical, stb_easy_font_color c, char* vbuf, int vbuf_size, int offset)
{
	int i, j;
	for (i = 0; i < num_segs; ++i) {
		int len = segs[i] & 7;
		x += (float)((segs[i] >> 3) & 1);
		if (len && offset + 64 <= vbuf_size) {
			float y0 = y + (float)(segs[i] >> 4);
			for (j = 0; j < 4; ++j) {
				*(float*)(vbuf + offset + 0) = x + (j == 1 || j == 2 ? (vertical ? 1 : len) : 0);
				*(float*)(vbuf + offset + 4) = y0 + (j >= 2 ? (vertical ? len : 1) : 0);
				*(float*)(vbuf + offset + 8) = 0.f;
				*(stb_easy_font_color*)(vbuf + offset + 12) = c;
				offset += 16;
			}
		}
	}
	return offset;
}

static float stb_easy_font_spacing_val = 0;
static void stb_easy_font_spacing(float spacing)
{
	stb_easy_font_spacing_val = spacing;
}

static int stb_easy_font_print(float x, float y, char* text, unsigned char color[4], void* vertex_buffer, int vbuf_size)
{
	char* vbuf = (char*)vertex_buffer;
	float start_x = x;
	int offset = 0;

	stb_easy_font_color c = { 255,255,255,255 }; // use structure copying to avoid needing depending on memcpy()
	if (color) { c.c[0] = color[0]; c.c[1] = color[1]; c.c[2] = color[2]; c.c[3] = color[3]; }

	while (*text && offset < vbuf_size) {
		if (*text == '\n') {
			y += 12;
			x = start_x;
		}
		else {
			unsigned char advance = stb_easy_font_charinfo[*text - 32].advance;
			float y_ch = advance & 16 ? y + 1 : y;
			int h_seg, v_seg, num_h, num_v;
			h_seg = stb_easy_font_charinfo[*text - 32].h_seg;
			v_seg = stb_easy_font_charinfo[*text - 32].v_seg;
			num_h = stb_easy_font_charinfo[*text - 32 + 1].h_seg - h_seg;
			num_v = stb_easy_font_charinfo[*text - 32 + 1].v_seg - v_seg;
			offset = stb_easy_font_draw_segs(x, y_ch, &stb_easy_font_hseg[h_seg], num_h, 0, c, vbuf, vbuf_size, offset);
			offset = stb_easy_font_draw_segs(x, y_ch, &stb_easy_font_vseg[v_seg], num_v, 1, c, vbuf, vbuf_size, offset);
			x += advance & 15;
			x += stb_easy_font_spacing_val;
		}
		++text;
	}
	return (unsigned)offset / 64;
}

int depth_const = 1;
int comp_win_const = 0;
int startDesk[14] = { 6,6,6,6,6,6, 0, 6,6,6,6,6,6,0};

enum LEVEL { EASY = 1, MEDIUM = 5, HARD = 10 };
enum SIDE { A, B };

enum LEVEL maxDepth = EASY;

int setGame(void);
int makeTurn(int*, int);
int bestTurn(int*);
int alphaBeta(int*, int, enum SIDE, int, int);
int evaluate(int*);
char Error(int type);
void dropRemainStones(int* desk);

void print_string(float x, float y, char* text, float r, float g, float b) {
	static char buffer[99999];
	int num_quads;

	num_quads = stb_easy_font_print(x, y, text, NULL, buffer, sizeof(buffer));

	glColor3f(r, g, b);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(2, GL_FLOAT, 16, buffer);
	glDrawArrays(GL_QUADS, 0, num_quads * 4);
	glDisableClientState(GL_VERTEX_ARRAY);
}

int isEmptySide(int* desk, int flag) {
	int i;
	int j;
	int fin = 0;
	int fin2 = 0;

	for (i = 0; i < 6; i++) if (desk[i]) fin = 1;
	for (i = 7; i < 13; i++) if (desk[i]) fin2 = 1;

	if (flag == 1) {
		if (!fin || !fin2) fin = 0;
		if (fin) return fin;
		else { dropRemainStones(desk); }
	}
	else if (flag == 0) {
		if (fin && fin2) { return 0; }
		else {
			dropRemainStones(startDesk);
			if (startDesk[6] > startDesk[13]) { return 1; }
			else if (startDesk[6] < startDesk[13]) { return 2; }
			else { return 3; }
		}
	}

}

int makeTurn(int* desk, int move, int flag) {

	int i, stones, repeatTurn = 0;
	i = --move;
	if (flag == 0) {
		turn = 0;
		if (i < 0) { i = i + 8; }
	}

	stones = desk[i];
	desk[i] = 0;

	while (stones--) {
		i++;
		desk[i]++;
		if ((move > 6 && i == 6) || (move < 6 && i == 13)) {
			desk[i]--;
			stones++;
		}
		if (i == 13 && stones > 0) i = -1;
	}

	if ((desk[i] == 1 && desk[12 - i]) &&
		((move < 6 && i < 6) || (move > 6 && i > 6 && i < 13))) {
		if (move > 6) stones = 13;
		else stones = 6;

		desk[stones] = desk[stones] + desk[i] + desk[12 - i];
		desk[i] = desk[12 - i] = 0;
	}

	if (move < 6 && i == 6 || move > 6 && i == 13) repeatTurn = 1;
	return repeatTurn;
}

void dropRemainStones(int* desk) {
	int i = 0;
	int j = 0;
	for (i = 7, j = 0; i < 13 && j < 6; i++, j++) {
		desk[6] += desk[j]; desk[j] = 0;
		desk[13] += desk[i]; desk[i] = 0;
	}
}

int evaluate(int* desk) {
	turn = 1;
	int Kc = 0;
	int Kp = 0;
	int i = 0;

	for (i = 0; i < 6; i++) Kp += desk[i];
	for (i = 7; i < 13; i++) Kc += desk[i];

	return ((desk[13] - desk[6]) * 100 + Kc - Kp);
}

int bestTurn(int* desk) {
	startnew = clock();
	turn = 1;
	int move = 0;
	int j = 0;
	int k = 0;
	int score;
	int best = -infinity;
	int virtualDesk[14];
	int bestMove = 0;
	errno_t err;
	enum LEVEL Depth = maxDepth;
	
	if ((desk[13] > 2 * desk[5]) && (Depth > 2) && (depth_const==1) && (desk[13]>18)) {
		Depth = Depth - 2;
		depth_const = 0;
	}
	if (desk[13] > 36) {
		comp_win_const = 1;
	}

	for (move = 12; move > 6; move--) {
		err = memcpy_s(virtualDesk, sizeof(virtualDesk), desk, 14 * sizeof(int));
		if (virtualDesk[move] > 0) {
			k = makeTurn(virtualDesk, (move + 1), 1);
			if (!isEmptySide(virtualDesk, 1)) {
				dropRemainStones(virtualDesk);
				score = evaluate(virtualDesk);
			}
			else {
				if (k == 1) {
					score = alphaBeta(virtualDesk, Depth, B, -infinity, infinity);
				}
				else {
					score = alphaBeta(virtualDesk, Depth - 1, A, -infinity, infinity);
				}
			}
			if (score > best) {
				best = score;
				bestMove = move + 1;
			}
		}
	}
	
	return (bestMove - 7);
}

int alphaBeta(int* desk, int curDepth, enum SIDE side, int alpha, int beta) {
	turn = 1;
	int i = 0;
	int j = 0;
	int k = 0;
	int move = 0;
	int score = 0;
	int virtualDesk[14];
	int best = -infinity;
	errno_t err;

	if (curDepth == 0) return evaluate(desk);

	if (side == B) {
		for (move = 12; move > 6; move--) {
			err = memcpy_s(virtualDesk, sizeof(virtualDesk), desk, 14 * sizeof(int));
			if (virtualDesk[move] > 0) {
				k = makeTurn(virtualDesk, (move + 1), 1);
				if (!isEmptySide(virtualDesk, 1)) {
					dropRemainStones(virtualDesk);
					score = evaluate(virtualDesk);
				}
				else {
					if (k == 1) score = alphaBeta(virtualDesk, curDepth, side, alpha, beta);
					else score = alphaBeta(virtualDesk, curDepth - 1, A, alpha, beta);
				}
				if (score > best) {
					best = score;
					turn == 1;
					if (alpha > best) alpha = alpha;
					else alpha = best;
					if (alpha >= beta) return alpha;
				}
			}
		}
	}

	else if (side == A) {
		turn = 1;
		best = infinity;
		for (move = 5; move >= 0; move--) {
			err = memcpy_s(virtualDesk, sizeof(virtualDesk), desk, 14 * sizeof(int));
			if (virtualDesk[move] > 0) {
				k = makeTurn(virtualDesk, (move + 1), 1);
				if (!isEmptySide(virtualDesk, 1)) {
					dropRemainStones(virtualDesk);
					score = evaluate(virtualDesk);
				}
				else {
					if (k == 1) score = alphaBeta(virtualDesk, curDepth, side, alpha, beta);
					else score = alphaBeta(virtualDesk, curDepth - 1, B, alpha, beta);
				}
				if (score < best) {
					best = score;
					turn == 1;
					if (beta < best) beta = beta;
					else beta = best;
					if (beta <= alpha) return beta;
				}
			}
		}
	}
	return best;
}


#pragma comment(lib, "opengl32.lib")

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
void EnableOpenGL(HWND hwnd, HDC*, HGLRC*);
void DisableOpenGL(HWND, HDC, HGLRC);


int width, height;


typedef struct {
	char name[20];
	float vert[8];
} TButton;

TButton btn[] = {
	{"players", {0,0,100,0,100,30,0,30}},
	{"computer", {0,40,100,40,100,70,0,70}},
	{"quit", {0,80,100,80,100,110,0,110}}
};

void TButton_Show(TButton btn)
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glColor3f(0, 1, 0);
	glVertexPointer(2, GL_FLOAT, 0, btn.vert);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void ShowMenu()
{
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0, width, height, 0, -1, 1);
	TButton_Show(btn[0]);
	TButton_Show(btn[1]);
	TButton_Show(btn[2]);
	glPopMatrix();
}

TButton btn1[] = {
	{"11", {0,0,100,0,100,30,0,30}},
	{"12", {0,40,100,40,100,70,0,70}},
	{"13", {0,80,100,80,100,110,0,110}},
	{"14", {0,120,100,120,100,150,0,150}},
	{"15", {0,160,100,160,100,190,0,190}},
	{"16", {0,200,100,200,100,230,0,230}},
	{"21", {1000,0,1100,0,1100,30,1000,30}},
	{"22", {1000,40,1100,40,1100,70,1000,70}},
	{"23", {1000,80,1100,80,1100,110,1000,110}},
	{"24", {1000,120,1100,120,1100,150,1000,150}},
	{"25", {1000,160,1100,160,1100,190,1000,190}},
	{"26", {1000,200,1100,200,1100,230,1000,230}},
};


void ShowButtons()
{
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0, width, height, 0, -1, 1);
	TButton_Show(btn1[0]);
	TButton_Show(btn1[1]);
	TButton_Show(btn1[2]);
	TButton_Show(btn1[3]);
	TButton_Show(btn1[4]);
	TButton_Show(btn1[5]);
	TButton_Show(btn1[6]);
	TButton_Show(btn1[7]);
	TButton_Show(btn1[8]);
	TButton_Show(btn1[9]);
	TButton_Show(btn1[10]);
	TButton_Show(btn1[11]);
	glPopMatrix();
}


void ShowMenu1()
{
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0, width, height, 0, -1, 1);
	TButton_Show(btn1[0]);
	TButton_Show(btn1[6]);
	TButton_Show(btn1[7]);
	TButton_Show(btn1[8]);
	TButton_Show(btn1[9]);
	TButton_Show(btn1[10]);
	TButton_Show(btn1[11]);
	glPopMatrix();
}

int flag = 0;

enum SIDE side = A;
int answer = 0;
int start = 0;
int check_empty = 0;
int level = 0;


int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	WNDCLASSEX wcex;
	HWND hwnd;
	HDC hDC;
	HGLRC hRC;
	MSG msg;
	BOOL bQuit = FALSE;
	float theta = 0.0f;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_OWNDC;
	wcex.lpfnWndProc = WindowProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = "KALAH";
	wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);;


	if (!RegisterClassEx(&wcex))
		return 0;

	hwnd = CreateWindowEx(0,
		"KALAH",
		"KALAH GAME",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		1080,
		800,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(hwnd, nCmdShow);

	EnableOpenGL(hwnd, &hDC, &hRC);

	while (!bQuit)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				bQuit = TRUE;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			glPushMatrix();

			glScalef(0.015, -0.015, 1);
			glScalef(0.8, 0.9, 0.5);

			for (int i = 0; i < 14; i++) {
				int a = startDesk[i];
				char string[3];
				_itoa_s(a, string, _countof(string), 10);
				char counter_string[3];
				if (i < 6) {
					_itoa_s(i+1, counter_string, _countof(counter_string), 10);
					print_string(-54 + i * 20, 6, string, 0, 0, 1);
					print_string(-54 + i * 20, 22, counter_string, 1, 1, 1);
				}
				else if (i == 6) {
					print_string(53, -9, string, 0, 0, 1);
				}
				else if (i == 13) {
					print_string(-60, -9, string, 0, 1, 0);
				}
				else if (i > 6) {
					_itoa_s(13 - i, counter_string, _countof(counter_string), 10);
					print_string(-54 + (i - 7) * 20, -24, string, 0, 1, 0);
					print_string(-54 + (i - 7) * 20, -40, counter_string, 1, 1, 1);
				}
			}


			if (answer == 0) {
				ShowMenu();
				glScalef(0.5, 0.5, 1);
				print_string(-130, -145.8, "PvP", 1, 1, 1);
				print_string(-130, -130, "AI", 1, 1, 1);
				print_string(-130, -114.2, "Quit", 1, 1, 1);
			}
			if (answer == 1) {
				ShowMenu();
				glScalef(0.5, 0.5, 1);
				print_string(-132, -145.8, "1", 1, 1, 1);
				print_string(-132, -130, "2", 1, 1, 1);
				print_string(-132, -114.2, "3", 1, 1, 1);
				print_string(-132, -98.4, "4", 1, 1, 1);
				print_string(-132, -82.6, "5", 1, 1, 1);
				print_string(-132, -66.8, "6", 1, 1, 1);
				print_string(140, -145.8, "1", 1, 1, 1);
				print_string(140, -130, "2", 1, 1, 1);
				print_string(140, -114.2, "3", 1, 1, 1);
				print_string(140, -98.4, "4", 1, 1, 1);
				print_string(140, -82.6, "5", 1, 1, 1);
				print_string(140, -66.8, "6", 1, 1, 1);
				if (side == B)
					print_string(-50, 80, "Player B (GREEN) move", 1, 1, 1);
				else {
					print_string(-30, 80, "Player A (BLUE) move", 1, 1, 1);
				}
			}
			if (answer == 2) {
				ShowMenu();
				glScalef(0.5, 0.5, 1);
				print_string(-130, -145.8, "Easy", 1, 1, 1);
				print_string(-130, -130, "Medium", 1, 1, 1);
				print_string(-130, -114.2, "Hard", 1, 1, 1);
			}
			if (answer == 3) {
				glScalef(0.5, 0.5, 1);
				print_string(-130, -145.8, "Computer move", 1, 1, 1);
				print_string(140, -145.8, "1", 1, 1, 1);
				print_string(140, -130, "2", 1, 1, 1);
				print_string(140, -114.2, "3", 1, 1, 1);
				print_string(140, -98.4, "4", 1, 1, 1);
				print_string(140, -82.6, "5", 1, 1, 1);
				print_string(140, -66.8, "6", 1, 1, 1);
			}
			if (answer == 1) {
				ShowButtons();
				if (check_empty == 2) {
					answer = 4;
					print_string(-40, 100, "Player A wins", 0, 1, 0);
				}
				else if (check_empty == 1) {
					answer = 4;
					print_string(-40, 100, "Player B wins", 0, 1, 0);
				}
				else if (check_empty == 3) {
					answer = 4;
					print_string(-40, 100, "Draw", 0, 1, 0);
				}
			}
			if (answer == 3) {
				ShowMenu1();
				if ((check_empty == 2)||(comp_win_const==1)) {
					print_string(-40, 100, "Computer wins", 0, 1, 0);

				}
				else if (check_empty == 1) {
					print_string(-40, 100, "Player A wins", 0, 1, 0);
				}
				else if (check_empty == 3) {
					print_string(-40, 100, "Draw", 0, 1, 0);
				}
				else {
					if (side == B)
						print_string(-50, 80, "Press Computer (GREEN) move", 1, 1, 1);
					else {
						print_string(-30, 80, "Player move (BLUE)", 1, 1, 1);
					}
				}
			}

			glPopMatrix();
			SwapBuffers(hDC);

		}
	}

	DisableOpenGL(hwnd, hDC, hRC);

	DestroyWindow(hwnd);

	return msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CLOSE:
		PostQuitMessage(0);
		break;

	case WM_LBUTTONDOWN:
		if (answer == 0 || answer == 2) {
			for (int i = 0; i < 3; i++)
				if ((LOWORD(lParam) > btn[i].vert[0]) && (LOWORD(lParam) < btn[i].vert[4]) && (HIWORD(lParam) > btn[i].vert[1]) && (HIWORD(lParam) < btn[i].vert[5]))
				{
					if ((strcmp(btn[i].name, "quit") == 0) && (answer == 0))
						PostQuitMessage(0);
					else if ((strcmp(btn[i].name, "players") == 0) && (answer == 0))
						answer = 1;
					else if ((strcmp(btn[i].name, "computer") == 0) && (answer == 0)) {
						answer = 2;
					}
					else if ((strcmp(btn[i].name, "quit") == 0) && (answer == 2)) {
						answer = 3;
						maxDepth = HARD;
					}
					else if ((strcmp(btn[i].name, "players") == 0) && (answer == 2)) {
						answer = 3;
						maxDepth = MEDIUM;
					}
					else if ((strcmp(btn[i].name, "computer") == 0) && (answer == 2)) {
						answer = 3;
						maxDepth = EASY;
					}
				}
		}


		else if (answer == 1) {
			for (int i = 0; i < 12; i++)
				if ((LOWORD(lParam) > btn1[i].vert[0]) && (LOWORD(lParam) < btn1[i].vert[4]) &&
					(HIWORD(lParam) > btn1[i].vert[1]) && (HIWORD(lParam) < btn1[i].vert[5])) {
					if ((strcmp(btn1[i].name, "11") == 0) && (side == B) && (startDesk[12] != 0)) {
						int output = makeTurn(startDesk, 13, 0);
						check_empty = isEmptySide(startDesk, 0);
						if (output == 0) {
							if (side == A) side = B;
							else side = A;
						}
						if (start == 0) start = 1;
					}
					else if ((strcmp(btn1[i].name, "12") == 0) && (side == B) && (startDesk[11] != 0)) {
						int output = makeTurn(startDesk, 12, 0);
						check_empty = isEmptySide(startDesk, 0);
						if (output == 0) {
							if (side == A) side = B;
							else side = A;
						}
						if (start == 0) start = 1;
					}
					else if ((strcmp(btn1[i].name, "13") == 0) && (side == B) && (startDesk[10] != 0)) {
						int output = makeTurn(startDesk, 11, 0);
						check_empty = isEmptySide(startDesk, 0);
						if (output == 0) {
							if (side == A) side = B;
							else side = A;
						}
						if (start == 0) start = 1;
					}
					else if ((strcmp(btn1[i].name, "14") == 0) && (side == B) && (startDesk[9] != 0)) {
						int output = makeTurn(startDesk, 10, 0);
						check_empty = isEmptySide(startDesk, 0);
						if (output == 0) {
							if (side == A) side = B;
							else side = A;
						}
						if (start == 0) start = 1;
					}
					else if ((strcmp(btn1[i].name, "15") == 0) && (side == B) && (startDesk[8] != 0)) {
						int output = makeTurn(startDesk, 9, 0);
						check_empty = isEmptySide(startDesk, 0);
						if (output == 0) {
							if (side == A) side = B;
							else side = A;
						}
						if (start == 0) start = 1;
					}
					else if ((strcmp(btn1[i].name, "16") == 0) && (side == B) && (startDesk[7] != 0)) {
						int output = makeTurn(startDesk, 8, 0);
						check_empty = isEmptySide(startDesk, 0);
						if (output == 0) {
							if (side == A) side = B;
							else side = A;
						}
						if (start == 0) start = 1;
					}
					else if ((strcmp(btn1[i].name, "21") == 0) && (side == A) && (start == 1) && (startDesk[0] != 0)) {
						int output = makeTurn(startDesk, 1, 0);
						check_empty = isEmptySide(startDesk, 0);
						if (output == 0) {
							if (side == A) side = B;
							else side = A;
						}
						if (start == 0) start = 1;
					}
					else if ((strcmp(btn1[i].name, "22") == 0) && (side == A) && (startDesk[1] != 0)) { //
						int output = makeTurn(startDesk, 2, 0);
						check_empty = isEmptySide(startDesk, 0);
						if (output == 0) {
							if (side == A) side = B;
							else side = A;
						}
						if (start == 0) start = 1;
					}
					else if ((strcmp(btn1[i].name, "23") == 0) && (side == A) && (startDesk[2] != 0)) {
						int output = makeTurn(startDesk, 3, 0);
						check_empty = isEmptySide(startDesk, 0);
						if (output == 0) {
							if (side == A) side = B;
							else side = A;
						}
						if (start == 0) start = 1;
					}
					else if ((strcmp(btn1[i].name, "24") == 0) && (side == A) && (startDesk[3] != 0)) {
						int output = makeTurn(startDesk, 4, 0);
						check_empty = isEmptySide(startDesk, 0);
						if (output == 0) {
							if (side == A) side = B;
							else side = A;
						}
						if (start == 0) start = 1;
					}
					else if ((strcmp(btn1[i].name, "25") == 0) && (side == A) && (startDesk[4] != 0)) {
						int output = makeTurn(startDesk, 5, 0);
						check_empty = isEmptySide(startDesk, 0);
						if (output == 0) {
							if (side == A) side = B;
							else side = A;
						}
						if (start == 0) start = 1;
					}
					else if ((strcmp(btn1[i].name, "26") == 0) && (side == A) && (startDesk[5] != 0)) {
						int output = makeTurn(startDesk, 6, 0);
						check_empty = isEmptySide(startDesk, 0);
						if (output == 0) {
							if (side == A) side = B;
							else side = A;
						}
						if (start == 0) start = 1;
					}
				}
		}
		else if (answer == 3) {
			for (int i = 0; i < 12; i++)
				if ((LOWORD(lParam) > btn1[i].vert[0]) && (LOWORD(lParam) < btn1[i].vert[4]) &&
					(HIWORD(lParam) > btn1[i].vert[1]) && (HIWORD(lParam) < btn1[i].vert[5])) {
					if ((strcmp(btn1[i].name, "21") == 0) && (side == A) && (start == 1) && (startDesk[0] != 0)) {
						int output = makeTurn(startDesk, 1, 0);
						check_empty = isEmptySide(startDesk, 0);
						if (output == 0) {
							if (side == A) side = B;
							else side = A;
						}
						if (start == 0) start = 1;
					}
					else if ((strcmp(btn1[i].name, "22") == 0) && (side == A) && (startDesk[1] != 0)) { //
						int output = makeTurn(startDesk, 2, 0);
						check_empty = isEmptySide(startDesk, 0);
						if (output == 0) {
							if (side == A) side = B;
							else side = A;
						}
						if (start == 0) start = 1;
					}
					else if ((strcmp(btn1[i].name, "23") == 0) && (side == A) && (startDesk[2] != 0)) {
						int output = makeTurn(startDesk, 3, 0);
						check_empty = isEmptySide(startDesk, 0);
						if (output == 0) {
							if (side == A) side = B;
							else side = A;
						}
						if (start == 0) start = 1;
					}
					else if ((strcmp(btn1[i].name, "24") == 0) && (side == A) && (startDesk[3] != 0)) {
						int output = makeTurn(startDesk, 4, 0);
						check_empty = isEmptySide(startDesk, 0);
						if (output == 0) {
							if (side == A) side = B;
							else side = A;
						}
						if (start == 0) start = 1;
					}
					else if ((strcmp(btn1[i].name, "25") == 0) && (side == A) && (startDesk[4] != 0)) {
						int output = makeTurn(startDesk, 5, 0);
						check_empty = isEmptySide(startDesk, 0);
						if (output == 0) {
							if (side == A) side = B;
							else side = A;
						}
						if (start == 0) start = 1;
					}
					else if ((strcmp(btn1[i].name, "26") == 0) && (side == A) && (startDesk[5] != 0)) {
						int output = makeTurn(startDesk, 6, 0);
						check_empty = isEmptySide(startDesk, 0);
						if (output == 0) {
							if (side == A) side = B;
							else side = A;
						}
						if (start == 0) start = 1;
					}
					else if ((side == B) && (strcmp(btn1[i].name, "11") == 0)) {
						int computerTurn = bestTurn(startDesk);
						int output = makeTurn(startDesk, computerTurn + 7, 0);
						check_empty = isEmptySide(startDesk, 0);
						if (output == 0) {
							if (side == A) side = B;
							else side = A;
						}
						else { flag = 1; }
						if (start == 0) start = 1;
					}
				}
		}


		break;

	case WM_SIZE:
		width = LOWORD(lParam);
		height = HIWORD(lParam);
		glViewport(0, 0, width, height);
		glLoadIdentity();
		float k = width / (float)height;
		glOrtho(-k, k, -1, 1, -1, 1);
		break;

	case WM_DESTROY:
		return 0;

	case WM_KEYDOWN:
	{
		switch (wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		}
	}
	break;

	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}

	return 0;
}

void EnableOpenGL(HWND hwnd, HDC* hDC, HGLRC* hRC)
{
	PIXELFORMATDESCRIPTOR pfd;

	int iFormat;

	*hDC = GetDC(hwnd);

	ZeroMemory(&pfd, sizeof(pfd));

	pfd.nSize = sizeof(pfd);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW |
		PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 24;
	pfd.cDepthBits = 16;
	pfd.iLayerType = PFD_MAIN_PLANE;

	iFormat = ChoosePixelFormat(*hDC, &pfd);

	SetPixelFormat(*hDC, iFormat, &pfd);

	*hRC = wglCreateContext(*hDC);

	wglMakeCurrent(*hDC, *hRC);
}

void DisableOpenGL(HWND hwnd, HDC hDC, HGLRC hRC)
{
	wglMakeCurrent(NULL, NULL);
	wglDeleteContext(hRC);
	ReleaseDC(hwnd, hDC);
}
