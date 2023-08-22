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

//�� �ձ�� ����ϰ� ������. ��? �ٵ� ����� ���� ���� �Ŷ� ���� �ƴϴ�.
//�ϴ� 2���� �迭�� ����������� ��.
//top-bottom���� �ؾ��ҵ�. bottom���� �ϴϱ� ���� �ȼ�.
//�迭�� �ǹ̰� ����
//bottom���� ������ ���� �Ծ��� �� �̷��� �Ѵ�~ ��� ����������
//top���� �����ϸ� ���� �����ִ°� � ��� ����.

//���� �˾࿡�� ���� ��Ģ���� �������ٺ���
//[0][����]�϶� ������ 1������ ǥ����!!