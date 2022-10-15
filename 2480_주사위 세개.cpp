#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> dice;
	int money = 0;

	for (int i = 0; i < 3; i++) {
		int num;
		scanf_s("%d", &num);
		dice.push_back(num);
	}

	sort(dice.begin(), dice.end());

	if(dice[0] == dice[2])
		money = 10000 + dice[0] * 1000;
	else if (dice[0] == dice[1] || dice[1] == dice[2])
		money = 1000 + dice[1] * 100;
	else
		money = dice[2] * 100;

	printf("%d", money);

	return 0;
}