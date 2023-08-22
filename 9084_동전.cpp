#include <iostream>
#include <vector>
using namespace std;

int t;	//�׽�Ʈ���̽� ����

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;

	for (int l = 0; l < t; l++) {
		int n;	//������ ���� ��
		cin >> n;

		vector<int> coins;	//����� ���� �迭
		for (int i = 0; i < n; i++) {
			int coin;
			cin >> coin;
			coins.push_back(coin);
		}

		int m;	//�������� ������ �� �ݾ�
		cin >> m;

		//���̵�� : �ش� ������ ���� �������� �����ֱ�
		int dp[10001];
		dp[0] = 1;
		for (int i = 1; i <= m; i++)
			dp[i] = 0;

		for (int i = 0; i < coins.size(); i++) 
			for (int j = 1; j <= m; j++) {
				if (j - coins[i] < 0) continue;
				dp[j] = dp[j] + dp[j - coins[i]];
			}

		cout << dp[m] << '\n';
	}

	return 0;
}