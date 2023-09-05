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
#define ROTATE 32
int sy_x, sy_y, sy_i, sy_j;
int sy_block_shape;
int ch_block_kind;
int ch_block_rotate;
int ch_board[12][22];//보드판 10(행)X20(열)
int ch_x, ch_y; //반복 횟수
int ch_rand;//난수
int goalscore; //점수
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
	Pos.X = sy_x; //화면의 x좌표
	Pos.Y = sy_y; //화면의 y좌표
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void CursorView(char sy_show)
{
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = sy_show;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor);
}       //커서 안보이게 하는거
void BlockCreate(int sy_blockshape, int sy_block_x, int sy_block_y) {
	for (int sy_i = 0; sy_i < 4; sy_i++) {
		for (int sy_j = 0; sy_j < 4; sy_j++) {
			if (ch_block[sy_blockshape][ch_block_rotate%4][sy_j][sy_i] == 2) {
				GotoXY(sy_block_x + sy_i * 2, sy_block_y + sy_j);
				printf("▢");//4x4 블럭 배열 중에 2 있는 곳에 ▢ 채우기
			}
			else if (ch_block[sy_blockshape][ch_block_rotate%4][sy_j][sy_i] == 0) {
				GotoXY(sy_block_x + sy_i * 2, sy_block_y + sy_j);
				printf(" ");//4x4 블럭 배열 중에 0 있는 곳 공백으로 두기
			}
		}
	}
}
int ch_emptycheck(int sy_blockshape, int ch_block_rotate, int sy_x, int sy_y) {
	for (sy_i = 0; sy_i < 4; sy_i++) {
		for (sy_j = 0; sy_j < 4; sy_j++) {
			if (ch_block[ch_block_kind][ch_block_rotate%4][sy_j][sy_i] == 2) {
				if (ch_board[sy_x+sy_i ][sy_y+sy_j] == 1) return 0;
			}
		}
	}
	return 1;
}
void BoardMake() {                  //보드 만들기
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
}                        //보드 만들기
void lineclear() {      //한 줄 없애기 및 위에 쌓인 블럭 내리기
	int goalscore = 0;
	int ch_linecheck = 0;
	int ch_y2;
	for (ch_y = 0; ch_y < 21; ch_y++) {
		ch_y2 = ch_y;
		for (ch_x = 1; ch_x < 11; ch_x++) {
			ch_linecheck += ch_board[ch_x][ch_y];
		}
		if (ch_linecheck == 10) {
			goalscore += 100;
			for (ch_y2; ch_y2 > 0; ch_y2--) {
				for (ch_x = 1; ch_x < 11; ch_x++) {
					ch_board[ch_x][ch_y2] = ch_board[ch_x][ch_y2 - 1]; //보드판 내 배열 재설정
				}
			}
			for (ch_y2 = 0; ch_y2 < 11; ch_y2++) {      //재설정 된대로 재출력
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
void ch_block_end() {       //수정 필요
	for (sy_i = 0; sy_i < 4; sy_i++) {
		for (sy_j = 0; sy_j < 4; sy_j++) {
			if (ch_block[ch_block_kind][ch_block_rotate][sy_j][sy_i] == 2) {
				GotoXY(sy_x+sy_i * 2,sy_y+ sy_j);
				ch_board[sy_i * 2][sy_j] = 1;
			}
			printf("   ");
		}
	}
	BlockCreate(1, sy_x, sy_y);
	lineclear();
}
sy_x = 2; sy_y = 1;
int main(void) {
	srand((unsigned int)time(NULL));
	ch_rand = rand();
	int ch_a; //for문 반복
	ch_block_rotate = 0;
	BoardMake();
	CursorView(0);
	GotoXY(sy_x, sy_y);
	while (1) {
		BlockCreate(ch_rand % 7, sy_x, sy_y);
		Sleep (1000);
		if (sy_y < 17) {
			GotoXY(sy_x, sy_y);
			BlockCreate(7, sy_x, sy_y);
			sy_y++;
		}
		GotoXY(sy_x, sy_y);
		
		if (_kbhit()) {
			int sy_nkey = _getch();
			if (sy_nkey == ARROW) {
				sy_nkey = _getch();
				GotoXY(sy_x, sy_y);
				BlockCreate(7,sy_x, sy_y);
				switch (sy_nkey) {
				case LEFT:
				
					if (sy_x > 2) sy_x--;
					if (ch_emptycheck(sy_block_shape, ch_block_rotate, sy_x, sy_y)==1){
					BlockCreate(7, sy_x, sy_y);
					BlockCreate(ch_rand % 7, sy_x, sy_y);
					}
					else sy_x++;
					break;
				case RIGHT:
				
					if (sy_x < 20) sy_x++;
					if (ch_emptycheck(sy_block_shape, ch_block_rotate, sy_x, sy_y)==1){
					BlockCreate(7, sy_x, sy_y);
					BlockCreate(ch_rand % 7, sy_x, sy_y);
					}
					else sy_x--;
					break;
				case DOWN:
				
					if (sy_y < 18) sy_y++;
					if (ch_emptycheck(sy_block_shape, ch_block_rotate, sy_x, sy_y)==1){
					BlockCreate(7, sy_x, sy_y);
					BlockCreate(ch_rand % 7, sy_x, sy_y);
					}
					else sy_y--;
					break;
				}
			}
			
			else if(sy_nkey==ROTATE){
				ch_block_rotate++;
				if (ch_emptycheck(sy_block_shape, ch_block_rotate, sy_x, sy_y)==1){
					BlockCreate(7, sy_x, sy_y);
					BlockCreate(ch_rand % 7, sy_x, sy_y);
					}
				else ch_block_rotate--;
			}
		}
		lineclear();
		GotoXY(sy_x, sy_y);
		BlockCreate(1, sy_x, sy_y);
	}
	return 0;
}
//c언어 커밋