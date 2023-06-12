#include <cstdio>
#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int main() {
	string word;
	cin >> word;
	int arr[26] = { 0 };
	int counter = 0;

	for (int i = 0; i < word.length(); i++)
		word[i] = toupper(word[i]);

	for (int i = 65; i < 91; i++) {
		for (int j = 0; j < word.length(); j++) {
			if (i == word[j])
				counter++;
		}
		arr[i - 65] = counter;
		counter = 0;
	}

	int max = 0;
	char result;
	for (int i = 0; i < 26; i++) {
		if (arr[i] > max) {
			max = arr[i];
			result = i+'A';

		}
		else if (arr[i] == max) {
			result = '?';
		}

	}

	cout << result;

	return 0;
}