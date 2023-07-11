/* 구현 아이디어
1. 작은 타일로 나눴을 때 그 타일의 같은 구역끼리 비교
2. 제일 많은 색상으로 모든 곳을 바꿈
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
char tile[500][500]; //입력받는 타일 정보
vector<Locate> small_tile;	//작은 타일 사이즈 좌표
vector<Color_info> color_search;	//색상 탐색 정보 저장 벡터

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;

	//타일 정보 입력
	for (int i = 0; i < n; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < m; j++) {
			tile[i][j] = line[j];
		}
	}

	//작은 타일 위치값 저장 (ex. k==2일 때, 00/01/10/11)
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			small_tile.push_back({ i, j });
		}
	}

	//작은 타일로 나눴을 때 같은 좌표끼리 색상 탐색
	for (int t = 0; t < small_tile.size(); t++) {    //작은 타일에서의 위치값
		int temp = color_search.size();
		for (int i = 0; i < temp; i++)
			color_search.pop_back();
		
		for (int i = small_tile[t].c; i < n; i += k) {
			for (int j = small_tile[t].r; j < m; j += k) {
				int check = 0;
				for (int u = 0; u < color_search.size(); u++) {
					if (tile[i][j] == color_search[u].color) {    //만약 색상 탐색 저장 벡터에 해당 색상이 있다면
						check = 1;
						color_search[u].num++;    //해당 색상의 카운트 증가
						break;
					}
				}
				if (check == 0)    //없다면
					color_search.push_back({ tile[i][j], 1 });    //벡터에 색상 추가
			}
		}

		//제일 많이 나온 색상 찾기
		Color_info max = color_search[0];
		for (int i = 0; i < color_search.size(); i++) {
			if (max.num < color_search[i].num)
				max = color_search[i];
		}
		small_tile[t].color = max.color;
	}

	//작은 타일로 다 교체하기
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

	cout << c << '\n';	//바꿀 횟수

	//바꾼 타일출력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << tile[i][j];
		}
		cout << '\n';
	}

	return 0;
}