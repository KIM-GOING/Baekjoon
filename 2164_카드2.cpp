#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
queue<int> card;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		card.push(i + 1);

	while (card.size() > 1) {
		card.pop();
		if (card.size() == 1)
			break;
		card.push(card.front());
		card.pop();
	}

	cout << card.front();

	return 0;
}