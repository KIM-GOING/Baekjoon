#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[10001];
int dp[10001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	dp[0] = arr[0];
	dp[1] = arr[0] + arr[1];

	if (dp[1] < arr[1] + arr[2])
		dp[2] = arr[1] + arr[2];
	else
		dp[2] = dp[1];

	for (int i = 0; i < n; i++) {
		int c1, c2, c3;

		c1 = arr[i] + arr[i - 1] + dp[i - 3];
		c2 = arr[i] + dp[i - 2];
		c3 = dp[i - 1];

		dp[i] = max(c1, max(c2, c3));
	}

	cout << *max_element(dp, dp + n);

	return 0;
}