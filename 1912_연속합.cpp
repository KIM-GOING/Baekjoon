#include <iostream>
using namespace std;

int n;
int arr[100001];
int dp[100001];

int maxDP = 0;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];

		if (i == 0) {
			dp[i] = arr[i];
			maxDP = dp[i];
		}
		else {

			if (dp[i - 1] < 0)
				dp[i] = arr[i];
			else
				dp[i] = arr[i] + dp[i - 1];
		}

		if (maxDP < dp[i])
			maxDP = dp[i];
	}

	cout << maxDP;

	return 0;
}