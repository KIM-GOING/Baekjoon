#include <iostream>
#include <algorithm>
using namespace std;

struct Consult {
	int day;
	int pay;
};

int n;
int result;
Consult schedule[16];

int DFS(int d) {
	if (d > n)
		return 0;
	else if (d == n) {
		if (schedule[d].day == 1)
			return schedule[d].pay;
		else
			return 0;
	}
	else {
		if (schedule[d].day <= n - d + 1)
			return max(DFS(d + 1), DFS(d + schedule[d].day) + schedule[d].pay);
		else
			return DFS(d + 1);
	}
		

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		int d;
		int p;
		cin >> d >> p;
		schedule[i] = { d, p };
	}

	cout << DFS(1);

	return 0;
}