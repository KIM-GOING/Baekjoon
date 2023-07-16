#include <iostream>
#include <vector>
using namespace std;

int n, m;
int nums[9] = { 0, };
vector<int> s;

void back(int a) {
	if (a == m) {
		for (int j = 0; j < m; j++)
			cout << s[j] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		int check = 0;
		for (int k = 0; k < s.size(); k++) {
			if (s[k] > i) {
				check = 1;
				break;
			}
		}
		if (check == 1)
			continue;
		if (nums[i] == 0) {
			s.push_back(i);
			nums[i] = 1;
			back(a + 1);
			nums[i] = 0;
			s.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	
	back(0);
	
	return 0;
}