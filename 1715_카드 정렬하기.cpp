#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;
int result;
priority_queue<int, vector<int>, greater<int>> q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int deck;
		cin >> deck;
		q.push(deck);
	}

	while (q.size() > 1) {
		int first = q.top();
		q.pop();
		int second = q.top();
		q.pop();

		int new_deck = first + second;
		q.push(new_deck);

		result += new_deck;
	}

	cout << result;

	return 0;
}