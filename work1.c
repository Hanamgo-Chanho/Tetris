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
}
int main(){
    //1.보드 만들기
    char ch_board1[12][22];//보드판 10(행)X20(열)
    int ch_i; //반복 횟수
    for (ch_i=0;ch_i<22;ch_i++){
        ch_board1[0][ch_i]='■';
        ch_board1[11][ch_i]='■';
    }

    
   /* 2.블럭 만들기
    3.보드 블럭 상호작용
    4.블럭 내리기
        -(1) 기존 블럭 지우기
        -(2) 내려간 블럭 출력하기
        -(3) 보드 바닥 인식하고 멈추기
        -(4) 쌓인 블럭 인식하고 멈추기
    5.방향키 이벤트 처리
        -(1) 키보드 입력 인식
        -(2) 블럭 좌우 이동
        -(3) 이동 시 보드 벽면 인식하고 멈추기
        -(4) 아래 키로 빨리 내려가기
        -(5) 위 키로 한 번에 내리기
        -(6) 스페이스로 회전시키기
        -(7) 회전 시 보드 벽면 인식하고 멈추기
        *심화 -(8) 홀드 키 구현
    6.게임 룰 진행
        -(1) 앞블럭 이벤트 종료 인식
        -(2) 랜덤으로 새로운 블럭 생성
        -(3) 한 줄 꽉 차면 지우기
        -(4) 지우고 위에 블럭 한 칸씩 내리기
        -(5) 블럭 생성 위치에 이미 쌓인 블럭 있는지 판단
        -(6) 게임 오버 판정, 모두 멈추기
    *심화
    7.스코어 내기
    8.블럭 색칠하기
    9.낙하 속도 조절하기
    10.배경음악 넣기        */
    return 0;
}