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

int n;	//������ ũ��
int k;	//����� ����
int board[101][101];	//���� ���� ��
int l;	//���� ���� ��ȯ Ƚ��
Info info[100];	//���� ���� ��ȯ ���� �迭
int t;	//���ӿ� �ɸ� �ð�

queue<Locate> q;	//�� ���� ��ġ ť

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
		q.pop();	//���� ��ġ ����
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
		t++;	//1�� ����
		step1(nowX, nowY, nowL); //�Ӹ� ����ĭ �̵�
		step2();	//�� or ���� �ε����� ����
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
		board[x][y] = 1;	//��� ��ġ�� 1�� ����
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