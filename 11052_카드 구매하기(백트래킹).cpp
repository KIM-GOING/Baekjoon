#include <iostream>
#include <vector>
using namespace std;

int n;	//�����Ϸ��� �ϴ� ī���� ����
int moneys[10001];	//ī�嵦�� ���� ��
vector<int> buy;	//��Ʈ��ŷ ���� �迭
int cards;	//��Ʈ��ŷ�� ������ ī�� ��
int total;	//��Ʈ��ŷ�� ������ ī�嵦 ���� ��
int maxPrice;	//��������� �ִ� ��

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