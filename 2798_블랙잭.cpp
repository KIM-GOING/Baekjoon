#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int cards[101];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> cards[i];

	sort(cards, cards+n);

	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)	continue;
			for (int k = 0; k < n; k++) {
				if (i == k)	continue;
				if (j == k)	continue;

				int sum = cards[i] + cards[j] + cards[k];
				if (sum > m)	break;
				if (max < sum)
					max = sum;
			}
		}
	}

	cout << max;

	return 0;
}