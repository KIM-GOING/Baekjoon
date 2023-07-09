#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n, m;
vector<int> nums;
vector<int> v;

void dfs(int num) {
	if (num == m) {
		for (int j = 0; j < m; j++)
			cout << v[j] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		if (nums[i] == 0) {
			v.push_back(i + 1);
			nums[i] = 1;
			dfs(num + 1);
			nums[i] = 0;
			v.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		nums.push_back(0);

	dfs(0);

	return 0;
}