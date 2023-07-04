#include <iostream>
#include <string>
using namespace std;

int main() {
	string jay;
	cin >> jay;
	string doc;
	cin >> doc;

	if (jay.size() >= doc.size())
		cout << "go";
	else
		cout << "no";

	return 0;
}