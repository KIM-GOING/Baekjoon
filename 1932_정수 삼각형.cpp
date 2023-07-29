#include <iostream>
#include <algorithm>
using namespace std;

int n;
int top[500][500];	//입력되는 정수 삼각형
int sum[500][500];	//최대를 찾아가는 정수 삼각형

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
			if (j == 0)	//삼각형의 왼쪽 면
				sum[i][j] = top[i][j] + sum[i - 1][j];
			else if (j == i)	//삼각형의 오른쪽 면
				sum[i][j] = top[i][j] + sum[i - 1][j - 1];
			else	//삼각형의 가운데
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