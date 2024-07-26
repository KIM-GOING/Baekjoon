#include <iostream>
#include <algorithm>
using namespace std;

int n;
int weight[5001];

int dp(int k) {
	if (weight[k] >= 1)
		return weight[k];
	else if (weight[k] == -1)
		return 100000001;
	else {

		weight[k] = min(dp(k - 3), dp(k - 5)) + 1;
		return weight[k];
	}

}

int main() {
	cin >> n;

	weight[1] = -1;
	weight[2] = -1;
	weight[3] = 1;
	weight[4] = -1;
	weight[5] = 1;
	weight[7] = -1;

	dp(n);

	cout << weight[n];

	return 0;
}