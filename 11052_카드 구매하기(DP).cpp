#include <iostream>
#include <algorithm>
using namespace std;

int n;
int moneys[10001];
int dp[10001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> moneys[i];

	dp[1] = moneys[1];

	for (int i = 2; i <= n; i++) {
		int m = 0;
		for (int j = 1; j < i; j++)
			if (m < dp[i - j] + dp[j])
				m = dp[i - j] + dp[j];
		dp[i] = max(m, moneys[i]);
	}

	cout << dp[n];

	return 0;
}