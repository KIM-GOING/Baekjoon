#include <iostream>
#include <string>
using namespace std;

string s;
int box[2] = { 0, 0 };
char target;

int main() {
	cin >> s;

	target = s[0];
	if (s[0] == '0') 
		box[0]++;
	else 
		box[1]++;

	for (int i = 1; i < s.size(); i++) {
		if (target != s[i]) {
			if (s[i] == '0')
				box[0]++;
			else
				box[1]++;
			target = s[i];
		}
	}

	if (box[0] >= box[1])
		cout << box[1];
	else
		cout << box[0];

	return 0;
}