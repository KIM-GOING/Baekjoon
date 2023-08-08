#include <iostream>
using namespace std;

int n;	//도시의 수
int m;	//여행 계획에 속한 도시들의 수
int parent[201];	 //분리집합 루트 배열

int Find(int x) {
	if (x == parent[x])	return parent[x];
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	int px = Find(x);
	int py = Find(y);

	if (px != py) 
		parent[py] = px;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		parent[i] = i;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int link;
			cin >> link;

			if (i > j)	continue;

			if(link == 1)
				Union(i, j);
		}
	}

	int check = 0;
	int group = 0;
	for (int i = 0; i < m; i++) {
		int city;
		cin >> city;

		if (i == 0)
			group = Find(city);
		else {
			if (Find(city) != group) {
				check = 1;
				break;
			}
		}
	}

	if (check == 0)	cout << "YES";
	else cout << "NO";

	return 0;
}