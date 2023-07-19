#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> s;

void b(int a) {
	if (a == m) {
		for (int j = 0; j < m; j++)
			cout << s[j] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (s.empty() || s[a - 1] <= i) {
			s.push_back(i);
			b(a + 1);
			s.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	b(0);

	return 0;
}