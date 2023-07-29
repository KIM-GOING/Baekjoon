#include <iostream>
#include <algorithm>
using namespace std;

int n;
int top[500][500];	//�ԷµǴ� ���� �ﰢ��
int sum[500][500];	//�ִ븦 ã�ư��� ���� �ﰢ��

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			cin >> top[i][j];

	sum[0][0] = top[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0)	//�ﰢ���� ���� ��
				sum[i][j] = top[i][j] + sum[i - 1][j];
			else if (j == i)	//�ﰢ���� ������ ��
				sum[i][j] = top[i][j] + sum[i - 1][j - 1];
			else	//�ﰢ���� ���
				sum[i][j] = top[i][j] + max(sum[i - 1][j - 1], sum[i - 1][j]);
		}
	}

	int m = sum[n - 1][0];
	for (int i = 1; i < n; i++) {
		if (sum[n - 1][i] > m)
			m = sum[n - 1][i];
	}

	cout << m;

	return 0;
}