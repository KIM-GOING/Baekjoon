#include <iostream>
using namespace std;

int n;
int dp[1000001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= n; i++) {
		int nums[3];

		if (i % 3 == 0)
			nums[0] = dp[i / 3] + 1;
		else
			nums[0] = 1000000;
		if (i % 2 == 0)
			nums[1] = dp[i / 2] + 1;
		else
			nums[1] = 1000000;
		nums[2] = dp[i - 1] + 1;

		int min = nums[0];
		for (int j = 1; j < 3; j++) {
			if (min > nums[j])
				min = nums[j];
		}

		dp[i] = min;
	}

	cout << dp[n];

	return 0;
}