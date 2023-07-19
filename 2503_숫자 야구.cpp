#include <iostream>
#include <string>
using namespace std;

struct question {	//질문과 대답
	string num;	//질문할 숫자
	int strike;	//질문 숫자에 대한 스트라이크
	int ball;	//질문 숫자에 대한 볼
};

int n;	//질문할 횟수
question arr[100];	//최대 질문 100개
int result; //결과값

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n; 
	for (int i = 0; i < n; i++) {
		string n; int strike; int ball;
		cin >> n >> strike >> ball;
		arr[i] = { n, strike, ball };
	}
	
	//모든 숫자 돌면서 질문 숫자와 비교
	for (int a = 1; a <= 9; a++) {	//백의자리
		for (int b = 1; b <= 9; b++) {	//십의자리
			if (a == b)    continue;
			for (int c = 1; c <= 9; c++) {	//일의자리
				if (c == a || c == b)    continue;
				int insert[3] = { a, b, c };

				int check = 0;	//질문 숫자와 틀린 점 체크
				for (int u = 0; u < n; u++) {
					int goal[3] = { (int)arr[u].num[0] - 48, (int)arr[u].num[1] - 48, (int)arr[u].num[2] - 48 };

					int s = 0;
					int b = 0;
					for (int i = 0; i < 3; i++) {
						if (insert[i] == goal[i])  s++;	//strike 판별

						for (int j = 0; j < 3; j++) {
							if (i != j && insert[i] == goal[j]) b++; //ball 판별
						}
					}
					if (s != arr[u].strike || b != arr[u].ball) {	//strike or ball이 다르다면
						check = 1;	//해당 숫자는 예상 값이 아님
						break;
					}
				}

				if (check == 0)	//strike and ball이 모두 맞다면
					result++;	//예상 숫자 개수 증가
			}
		}
	}

	cout << result;

	return 0;
}