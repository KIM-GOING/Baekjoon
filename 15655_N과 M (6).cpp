#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int n, m;
vector<int> nums;	//사용할 숫자 배열
int visited[8];
vector<int> v;

void print() {
	for (int i = 1; i <= m; i++) {
		cout << v[i] << ' ';
	}
	cout << '\n';
}

void back(int a) {
	if (v.size() > m) {
		print();
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visited[i] == 0 && v.back() < nums[i]) {
			v.push_back(nums[i]);
			visited[i] == 1;

			back(a + 1);

			v.pop_back();
			visited[i] == 0;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		nums.push_back(num);
	}

	sort(nums.begin(), nums.end());

	v.push_back(0);

	back(0);

	return 0;
}