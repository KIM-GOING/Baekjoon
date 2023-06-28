#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int c;
	cin >> c;

	for (int k = 0; k < c; k++) {
		int n;
		cin >> n;
		int* score = new int[n];
		int sum = 0;
		for (int i = 0; i < n; i++) {
			int s;
			cin >> s;
			score[i] = s;
			sum += s;
		}

		double average = (double)sum / (double)n;
		int student = 0;
		for (int i = 0; i < n; i++) {
			if (score[i] > average)
				student++;
		}

		double percentage = 0.0;
		percentage = (double)student / (double)n * 100;
		cout << fixed;
		cout.precision(3);
		cout << percentage << '%' << '\n';

		delete[] score;
	}

	return 0;
}