/* ���� ���̵��
1. ���� Ÿ�Ϸ� ������ �� �� Ÿ���� ���� �������� ��
2. ���� ���� �������� ��� ���� �ٲ�
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Locate {
	int c;
	int r;
	char color;
};

struct Color_info {
	char color;
	int num;
};

int n, m, k, c;
char tile[500][500]; //�Է¹޴� Ÿ�� ����
vector<Locate> small_tile;	//���� Ÿ�� ������ ��ǥ
vector<Color_info> color_search;	//���� Ž�� ���� ���� ����

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;

	//Ÿ�� ���� �Է�
	for (int i = 0; i < n; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < m; j++) {
			tile[i][j] = line[j];
		}
	}

	//���� Ÿ�� ��ġ�� ���� (ex. k==2�� ��, 00/01/10/11)
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			small_tile.push_back({ i, j });
		}
	}

	//���� Ÿ�Ϸ� ������ �� ���� ��ǥ���� ���� Ž��
	for (int t = 0; t < small_tile.size(); t++) {    //���� Ÿ�Ͽ����� ��ġ��
		int temp = color_search.size();
		for (int i = 0; i < temp; i++)
			color_search.pop_back();
		
		for (int i = small_tile[t].c; i < n; i += k) {
			for (int j = small_tile[t].r; j < m; j += k) {
				int check = 0;
				for (int u = 0; u < color_search.size(); u++) {
					if (tile[i][j] == color_search[u].color) {    //���� ���� Ž�� ���� ���Ϳ� �ش� ������ �ִٸ�
						check = 1;
						color_search[u].num++;    //�ش� ������ ī��Ʈ ����
						break;
					}
				}
				if (check == 0)    //���ٸ�
					color_search.push_back({ tile[i][j], 1 });    //���Ϳ� ���� �߰�
			}
		}

		//���� ���� ���� ���� ã��
		Color_info max = color_search[0];
		for (int i = 0; i < color_search.size(); i++) {
			if (max.num < color_search[i].num)
				max = color_search[i];
		}
		small_tile[t].color = max.color;
	}

	//���� Ÿ�Ϸ� �� ��ü�ϱ�
	for (int t = 0; t < small_tile.size(); t++) {
		for (int i = small_tile[t].c; i < n; i += k) {
			for (int j = small_tile[t].r; j < m; j += k) {
				if (tile[i][j] != small_tile[t].color) {
					c++;
					tile[i][j] = small_tile[t].color;
				}
			}
		}
	}

	cout << c << '\n';	//�ٲ� Ƚ��

	//�ٲ� Ÿ�����
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << tile[i][j];
		}
		cout << '\n';
	}

	return 0;
}