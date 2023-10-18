#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n;
vector<string> dict;

bool comp(string s1, string s2) {
	if (s1.size() != s2.size())
		return s1.size() < s2.size();
	else
		return s1 < s2;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;

		int check = 0;
		for (int i = 0; i < dict.size(); i++)
			if (word == dict[i]) {
				check = 1;
				break;
			}

		if (check == 0)
			dict.push_back(word);
	}

	sort(dict.begin(), dict.end(), comp);

	for (int i = 0; i < dict.size(); i++)
		cout << dict[i] << '\n';

	return 0;
}