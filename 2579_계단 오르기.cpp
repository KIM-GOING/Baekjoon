#include <iostream>
using namespace std;

int dp[301];
int scores[301];

int stairs;

int max(int a, int b) {
	if (a >= b)
		return a;
	else
		return b;
}

int main() {
	cin >> stairs;

	for (int i = 1; i <= stairs; i++)
		cin >> scores[i];

	dp[1] = scores[1];
	dp[2] = scores[1] + scores[2];
	if (scores[1] + scores[3] >= scores[2] + scores[3])
		dp[3] = scores[1] + scores[3];
	else
		dp[3] = scores[2] + scores[3];

	for (int i = 4; i <= stairs; i++) {
		dp[i] = max(scores[i - 1] + dp[i - 3], dp[i - 2]) + scores[i];
	}

	cout << dp[stairs];

	return 0;
}