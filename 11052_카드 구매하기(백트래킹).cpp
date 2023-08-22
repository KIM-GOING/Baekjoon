#include <iostream>
#include <vector>
using namespace std;

int n;	//구매하려고 하는 카드의 개수
int moneys[10001];	//카드덱에 따른 값
vector<int> buy;	//백트랙킹 저장 배열
int cards;	//백트랙킹에 저장한 카드 수
int total;	//백트랙킹에 저장한 카드덱 값의 합
int maxPrice;	//현재까지의 최대 값

void back() {
	if (cards == n) {
		if (maxPrice < total) {
			maxPrice = total;
		}
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!buy.empty() && buy[buy.size() - 1] > i) continue;
		if (cards + i <= n) {
			buy.push_back(i);
			cards += i;
			total += moneys[i];

			back();

			cards -= i;
			total -= moneys[i];
			buy.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> moneys[i];

	back();

	cout << maxPrice;

	return 0;
}