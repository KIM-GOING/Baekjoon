#include <iostream>
#include <string>
#include <map>
using namespace std;

int n, m;
map<string, int> dic;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string name;
		cin >> name;
		dic.insert({ name, i + 1});
	}
	for (int i = 0; i < m; i++) {
		string q;
		cin >> q;
		if (stoi(q) >= 0 && stoi(q) < 10) {
			for (auto j = dic.begin(); j != dic.end(); j++) {
				if (j->second == stoi(q)) {
					cout << j->first << '\n';
					break;
				}
			}
		}
		else {
			cout << dic[q] << '\n';
		}
	}

	return 0;
}