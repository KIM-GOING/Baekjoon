#include <iostream>
#include <string>
using namespace std;

int main() {
	string b = "long";
	int num = 0;
	
	cin >> num;
	int quarter = num / 4;

	for (int i = 0; i < quarter; i++) {
		cout << b << " ";
	}
	cout << "int\n";

	return 0;
}