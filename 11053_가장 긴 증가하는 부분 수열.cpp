#include <iostream>
#include <algorithm>
using namespace std;

int num_arr[1001];	//입력되는 수열
int dp[1001];	//dp 수열
int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> num_arr[i];

	for (int i = 0; i < n; i++) {
		dp[i] += 1;

		for (int j = 0; j < n - 1; j++) {
			if (num_arr[i] > num_arr[j] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}
	}

	cout << *max_element(dp, dp + n);

	return 0;
}