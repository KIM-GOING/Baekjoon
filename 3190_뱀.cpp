#include <iostream>
#include <queue>
using namespace std;

struct Info {
	int x;
	char c;
};

struct Locate {
	int x;
	int y;
};

int n;	//보드의 크기
int k;	//사과의 개수
int board[101][101];	//게임 보드 판
int l;	//뱀의 방향 변환 횟수
Info info[100];	//뱀의 방향 변환 정보 배열
int t;	//게임에 걸린 시간

queue<Locate> q;	//뱀 현재 위치 큐

int nowX = 1;
int nowY = 1;
int nowL = 1;

bool gameover = false;

Locate head = { 1, 1 };
Locate tail = { 1, 1 };

void step1(int x, int y, int l) {
	if (l == 0) {
		nowX = x - 1;
		nowY = y ;
		nowL = l;
	}
	else if (l == 1) {
		nowX = x;
		nowY = y + 1;
		nowL = l;
	}
	else if (l == 2) {
		nowX = x + 1;
		nowY = y;
		nowL = l;
	}
	else {
		nowX = x;
		nowY = y - 1;
		nowL = l;
	}
	head = { nowX, nowY };
}

void step2() {
	if (nowX < 1 || nowX > n || nowY < 1 || nowY > n || board[nowX][nowY] == 2)
		gameover = true;
}

void step3() {
	if (board[nowX][nowY] == 1) {
		board[nowX][nowY] = 2;
		q.push({ nowX, nowY });
	}
	else {
		board[nowX][nowY] = 2;
		board[tail.x][tail.y] = 0;
		q.pop();	//꼬리 위치 변경
		q.push({ nowX, nowY });
		tail = { q.front().x, q.front().y };
	}
}

void turn(int time) {
	for (int i = 0; i < l; i++) {
		if (info[i].x == time) {
			if (info[i].c == 'L') {
				if (nowL == 0)
					nowL = 3;
				else
					nowL = nowL - 1;
			}
			if (info[i].c == 'D') {
				if (nowL == 3)
					nowL = 0;
				else
					nowL = nowL + 1;
			}
			break;
		}
		if (info[i].x > time)
			break;
	}
}


void snake() {

	while (1) {
		t++;	//1초 증가
		step1(nowX, nowY, nowL); //머리 다음칸 이동
		step2();	//벽 or 몸과 부딪히면 종료
		if (gameover) break;
		step3();
		turn(t);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	cin >> k;

	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		board[x][y] = 1;	//사과 위치는 1로 설정
	}

	q.push({ 1,1 });

	cin >> l;

	for (int i = 0; i < l; i++) {
		int x;
		char c;
		cin >> x >> c;
		info[i] = { x, c };
	}

	snake();

	cout << t;

	return 0;
}