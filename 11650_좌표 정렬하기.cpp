#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Locate {
	int x;
	int y;
};

int n;
vector<Locate> arr;

bool comp(Locate a, Locate b) {
	if (a.x < b.x)	return true;
	else if (a.x == b.x)
		return a.y < b.y;
	else
		return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr.push_back({ a, b });
	}

	sort(arr.begin(), arr.end(), comp);

	for (int i = 0; i < n; i++) 
		cout << arr[i].x << ' ' << arr[i].y << '\n';

	return 0;
}