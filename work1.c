#include <stdio.h>
#include <windows.h> // GotoXY() 콘솔창에서 원하는 위치에 커서 이동
#include <conio.h> // _kbhit() 키보드 누르면 1이 아닌 값 반환, _getch() 입력받은 키를 아스키 코드 값(정수)으로 변환
#include <time.h> //time()
#include <stdlib.h> // rand() 난수 생성, strand(time(Null)) 난수 시드(매번 다른 난수가 나오도록)
#define LEFT 75//왼쪽 화살표 아스키코드를 LEFT으로 선언
#define RIGHT 77//오른쪽 화살표 아스키코드를 RIGHT으로 선언
#define UP 72 //위쪽 화살표 아스키코드를 UP으로 선언
#define DOWN 80 //아래쪽 화살표 아스키코드를 DOWN으로 선언
#define ARROW 224 //화살표 아스키코드를 ARROW로 선언
int sy_x, sy_y, sy_i, sy_j;
int sy_block_shape;
int ch_block_kind;
int ch_block_rotate;
int ch_board[12][22];//보드판 10(행)X20(열)
int ch_x, ch_y; //반복 횟수
int ch_block[8][4][4][4] = { {
	 {	{0,0,0,0},
		 {0,2,2,0},
		 {0,2,2,0},
		 {0,0,0,0}
	 },
	 {	{0,0,0,0},
		 {0,2,2,0},
		 {0,2,2,0},
		 {0,0,0,0}
	 },
	 {	{0,0,0,0},
		 {0,2,2,0},
		 {0,2,2,0},
		 {0,0,0,0}
	 },
	 {	{0,0,0,0},
		 {0,2,2,0},
		 {0,2,2,0},
		 {0,0,0,0}
	 }
	},
{
	{	{0,0,0,0},
		{0,0,0,0},
		{2,2,2,2},
		{0,0,0,0}
	},
	{	{0,0,2,0},
		{0,0,2,0},
		{0,0,2,0},
		{0,0,2,0}
	},
	{	{0,0,0,0},
		{0,0,0,0},
		{2,2,2,2},
		{0,0,0,0}
	},
	{	{0,0,2,0},
		{0,0,2,0},
		{0,0,2,0},
		{0,0,2,0}
	}
},
{
	{	{0,0,0,0},
		{0,0,2,0},
		{0,0,2,0},
		{0,2,2,0}
	},
	{	{0,0,0,0},
		{0,2,2,2},
		{0,0,0,2},
		{0,0,0,0}
	},
	{	{0,0,0,0},
		{0,2,2,0},
		{0,2,0,0},
		{0,2,0,0}
	},
	{	{0,0,0,0},
		{2,0,0,0},
		{2,2,2,0},
		{0,0,0,0}
	}
},
{
	{	{0,0,0,0},
		{0,2,0,0},
		{0,2,0,0},
		{0,2,2,0}
	},
	{	{0,0,0,0},
		{2,2,2,0},
		{2,0,0,0},
		{0,0,0,0}
	},
	{	{0,0,0,0},
		{0,2,2,0},
		{0,2,0,0},
		{0,2,0,0}
	},
	{	{0,0,0,0},
		{0,0,0,2},
		{0,2,2,2},
		{0,0,0,0}
	}
},
{
	{	{0,0,0,0},
		{0,0,2,0},
		{0,2,2,0},
		{0,2,0,0}
	},
	{	{0,0,0,0},
		{0,2,2,0},
		{0,0,2,2},
		{0,0,0,0}
	},
	{	{0,0,0,0},
		{0,0,2,0},
		{0,2,2,0},
		{0,2,0,0}
	},
	{	{0,0,0,0},
		{0,2,2,0},
		{0,0,2,2},
		{0,0,0,0}
	}
},
{
	{	{0,0,0,0},
		{0,2,0,0},
		{0,2,2,0},
		{0,0,2,0}
	},
	{	{0,0,0,0},
		{0,2,2,0},
		{2,2,0,0},
		{0,0,0,0}
	},
	{	{0,0,0,0},
		{0,2,0,0},
		{0,2,2,0},
		{0,0,2,0}
	},
	{	{0,0,0,0},
		{0,2,2,0},
		{2,2,0,0},
		{0,0,0,0}
	}
},
{
	{	{0,0,0,0},
		{0,0,2,0},
		{0,2,2,2},
		{0,0,0,0}
	},
	{	{0,0,2,0},
		{0,2,2,0},
		{0,0,2,0},
		{0,0,0,0}
	},
	{	{0,0,0,0},
		{0,2,2,2},
		{0,0,2,0},
		{0,0,0,0}
	},
	{	{0,0,2,0},
		{0,0,2,2},
		{0,0,2,0},
		{0,0,0,0}
	}
},
	{
		{ {0,0,0,0},
			{ 0,0,0,0 },
			{ 0,0,0,0 },
			{ 0,0,0,0 }
		},
		{ {0,0,0,0},
			{0,0,0,0},
			{0,0,0,0},
			{0,0,0,0}
		},
		{ {0,0,0,0},
			{0,0,0,0},
			{0,0,0,0},
			{0,0,0,0}
		},
		{ {0,0,0,0},
			{0,0,0,0},
			{0,0,0,0},
			{0,0,0,0}
		}
	}
};                      //블럭만들기
void GotoXY(int sy_x, int sy_y) {
	COORD Pos;
	Pos.X = sy_x;
	Pos.Y = sy_y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void CursorView(char sy_show)
{
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = sy_show;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor);
}       //커서 안보이게 하는거
void BlockCreate(int sy_blockshape) {
	for (int sy_i = 0; sy_i < 4; sy_i++) {
		for (int sy_j = 0; sy_j < 4; sy_j++) {
			if (ch_block[sy_blockshape][0][sy_i][sy_j] == 2) {
				GotoXY(sy_i * 2, sy_j);
				printf("ㅁ");
			}
		}
	}
} 
/*int ch_emptycheck() {
	for (sy_i = 0; sy_i < 4; sy_i++) {
		for (sy_j = 0; sy_j < 4; sy_j++) {
			if (ch_block[ch_block_kind][ch_block_rotate][sy_j][sy_i] == 2) {
				GotoXY(sy_i * 2, sy_j - 1);
				if (ch_board[sy_i * 2][sy_j] == 1) return 1;
			}
		}
	}
	return 0;
}*/
void BoardMake(){
	for (ch_x = 0; ch_x < 12; ch_x++) {
		for (ch_y = 0; ch_y < 22; ch_y++) {
			ch_board[ch_x][ch_y] = 0;
		}
	}
	for (ch_y = 0; ch_y < 22; ch_y++) {
		ch_board[0][ch_y] = 1;
		ch_board[11][ch_y] = 1;
	}
	for (ch_x = 0; ch_x < 12; ch_x++) ch_board[ch_x][21] = 1;

	for (ch_x = 0; ch_x < 12; ch_x++) {
		for (ch_y = 0; ch_y < 22; ch_y++) {
			if (ch_board[ch_x][ch_y] == 1) {
				GotoXY(ch_x * 2, ch_y);
				printf("▩");
			}
		}
	}
}
void ch_block_end() {
	for (sy_i = 0; sy_i < 4; sy_i++) {
		for (sy_j = 0; sy_j < 4; sy_j++) {
			if (ch_block[ch_block_kind][ch_block_rotate][sy_j][sy_i] == 2) {
				GotoXY(sy_i * 2, sy_j);
				ch_board[sy_i * 2][sy_j] = 1;
			}
			printf("   ");
		}
	}
	BlockCreate(2);
	Lineclear();
}
void lineclear() {
	int goalscore;
	int ch_linecheck;
	int ch_y2;
	for (ch_y = 0; ch_y < 21; ch_y++) {
		ch_y2 = ch_y;
		for (ch_x = 1; ch_x < 11; ch++) {
			ch_linecheck += ch_board[ch_x][ch_y];
		}
		if (ch_linecheck == 10) {
			goalscore += 100;
			for (ch_y2; ch_y2 > 0; ch_y2--) {
				for (ch_x = 1; ch_x < 11; ch_x++) {
					ch_board[ch_x][ch_y2] = ch_board[ch_x][ch_y2 - 1];
				}
			}
			for (ch_y2 = 0; ch_y2 < 11; ch_y2++) {
				for (ch_x = 1; ch_x < 11; ch_x++) {
					GotoXY(ch_x, ch_y2);
					if (ch_board[ch_x][ch_y2] == 1) {
						printf("□");
					}
					else printf("  ");
				}
			}
		}
	}
}
sy_x = 2; sy_y = 1;
int main(void) {
    BoardMake();
	CursorView(1);
	GotoXY(sy_x, sy_y);
	while (1) {
		BlockCreate(2);
		if (sy_y < 20) {
			GotoXY(sy_x, sy_y);
			BlockCreate(7);
			sy_y++;
		}
		GotoXY(sy_x, sy_y);
		BlockCreate(2);
		Sleep(1000); 
		if (_kbhit()) {
			int sy_nkey = _getch();
			if (sy_nkey == ARROW) {
				sy_nkey = _getch();
				GotoXY(sy_x, sy_y);
				BlockCreate(7);
				switch (sy_nkey) {
				case LEFT:
					if (sy_x > 2) sy_x--;
					break;
				case RIGHT:
					if (sy_x < 20) sy_x++;
					break;
				case DOWN:
					if (sy_y < 20) sy_y++;
					break;
				case ROTATE:
					break;
				}
			}
		}
		GotoXY(sy_x, sy_y);
	}
	return 0;
}