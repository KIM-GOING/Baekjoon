#include <iostream>
using namespace std;

int scores[5];
int sum = 0;

int main() {
	for (int i = 0; i < 5; i++) {
		cin >> scores[i];
		sum += scores[i];
	}
	
	cout << sum;

	return 0;
}