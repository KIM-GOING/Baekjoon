#include <iostream>
#include <string>
#include <map>
using namespace std;

int n, m;
map<string, int> dic1;
map<int, string> dic2;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string name;
		cin >> name;
		dic1.insert({ name, i + 1});
		dic2.insert({ i + 1, name });
	}
	for (int i = 0; i < m; i++) {
		string q;
		cin >> q;
		if ((int)q[0] - 48 >= 0 && (int)q[0] - 48 < 10) {
			cout << dic2[stoi(q)] << '\n';
		}
		else {
			cout << dic1[q] << '\n';
		}
	}

	return 0;
}