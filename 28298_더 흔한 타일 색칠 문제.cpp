//���� ���̵��: ���� ��ǥ ��ġ���� ���� ���� ���� ���ĺ����� ���߱�

#include <iostream>
#include <string>
using namespace std;

int n, m, k;
char tile[500][500];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < m; j++) {
			tile[i][j] = line[j];
		}
	}

	for (int i = 0; i < n; i += k) {
		for (int j = 0; j < m; j += k) {

		}
	}

	return 0;
}