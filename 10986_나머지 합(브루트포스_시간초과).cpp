#include <iostream>
using namespace std;

int n, m;
int nums[1000001];
long long sums[1000001];
int c;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	int sum = 0;
	sums[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
		sum += nums[i];
		sums[i] = sum;
	}

	for (int i = 0; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if ((sums[j] - sums[i]) % m == 0) 
				c++;
			
		}
	}

	cout << c;

	return 0;
}