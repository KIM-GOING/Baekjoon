#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string n1, n2;
	cin >> n1;
	cin >> n2;

	vector<char> num1;
	vector<char> num2;
	for(int i = 0; i < n1.length(); i++)
		num1.insert(num1.begin(), n1[i]);
	for (int i = 0; i < n2.length(); i++)
		num2.insert(num2.begin(), n2[i]);

	int size = 0;
	if (num1.size() >= num2.size())
		size = num1.size();
	else
		size = num2.size();

	int temp = 0;
	int p1, p2, number = 0;
	vector<int> finalNum;
	for (int i = 0; i < size; i++) {
		if (num1.size() < size) {
			p1 = num2[i] - 48;
			number = p1 + temp;
			if (number > 9)
				temp = 1;
			finalNum.insert(finalNum.begin(), number % 10);
		}
		else if (num2.size() < size) {
			p1 = num1[i] - 48;
			number = p1 + temp;
			if (number > 9)
				temp = 1;
			finalNum.insert(finalNum.begin(), number % 10);
		}
		else {
			p1 = num1[i] - 48;
			p2 = num2[i] - 48;
			number = p1 + p2 + temp;
			finalNum.insert(finalNum.begin(), number % 10);
			if (number > 9)
				temp = 1;
			else
				temp = 0;
		}
	}
	if (temp == 1)
		finalNum.insert(finalNum.begin(), temp);

	for (int i = 0; i < finalNum.size(); i++)
		cout << finalNum[i];

	return 0;
}