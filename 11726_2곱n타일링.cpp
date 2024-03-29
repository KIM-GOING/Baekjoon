#include <iostream>
#include <vector>
using namespace std;

int n;
vector<long long> dp;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	dp.push_back(0);
	dp.push_back(1);
	dp.push_back(2);

	for (int i = 3; i <= n; i++)
		dp.push_back((dp[i - 2] + dp[i - 1]) % 10007);

	cout << dp[n];

	return 0;
}