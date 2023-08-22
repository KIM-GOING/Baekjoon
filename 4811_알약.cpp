#include <iostream>
using namespace std;

long long dp[31][31];

long long pill(int w, int h) {
	if (dp[w][h] > 0)
		return dp[w][h];
	else if (w == 0) {
		return 1;
	}
	else if (h == 0) {
		dp[w][h] = pill(w - 1, h + 1);
	}
	else {
		dp[w][h] = pill(w - 1, h + 1) + pill(w, h - 1);
	}

	return dp[w][h];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (1) {
		int t;
		cin >> t;

		if (t == 0)
			break;

		cout << pill(t, 0) << '\n';
	}

	return 0;
}

//벽 뚫기랑 비슷하게 생각함. 어? 근데 경우의 수를 세는 거라서 뭔가 아니다.
//일단 2차원 배열만 가져가보기로 함.
//top-bottom으로 해야할듯. bottom부터 하니까 각이 안서.
//배열의 의미가 뭐지
//bottom으로 생각할 때는 먹었을 때 이렇게 한다~ 라고 생각했으니
//top으로 생각하면 지금 남아있는게 몇개 라고 생각.

//현재 알약에서 나올 규칙으로 내려가다보면
//[0][숫자]일때 무조건 1가지로 표현됨!!