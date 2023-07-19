#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int nums[8];
int used[8];
vector<int> s;

void b(int a) {
	if (a == m) {
		for (int j = 0; j < m; j++)
			cout << s[j] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		if (used[i] == 0) {
			s.push_back(nums[i]);
			used[i] = 1;
			b(a + 1);
			used[i] = 0;
			s.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	sort(nums, nums + n);

	b(0);

	return 0;
}