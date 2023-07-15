#include <iostream>
#include <vector>
using namespace std;

int n;
vector<long long> dp;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	dp.push_back(0);
	dp.push_back(1);

	cin >> n;

	for (int i = 0; i <= n; i++) {
		if (i == 0 || i == 1)
			continue;
		else
			dp.push_back(dp[i - 2] + dp[i - 1]);
	}

	cout << dp[n];

	return 0;
}