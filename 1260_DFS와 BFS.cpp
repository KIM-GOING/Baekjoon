#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

bool num(int a, int b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, v;
	cin >> n >> m >> v;
	
	//인접 행렬 2차원 배열 동적 할당
	int** arr = new int*[n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[n];

	//그래프 구현
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			arr[i][j] = 0;
	}
	for (int i = 0; i < m; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		arr[n1 - 1][n2 - 1] = 1;
	}

	//DFS
	stack<int> dfs;
	vector<int> checkArr_dfs;	//탐색한 노드 저장 벡터

	int node = v;
	dfs.push(v);
	checkArr_dfs.push_back(v);
	while (dfs.size() != 0) {
		cout << dfs.top() << ' ';
		node = dfs.top();
		dfs.pop();
		vector<int> sort_arr;
		for (int i = 0; i < n; i++) {
			if (arr[node - 1][i] == 1) {
				int check = 0;
				for (int j = 0; j < checkArr_dfs.size(); j++) {
					if (checkArr_dfs[j] == i + 1) {
						check = 1;
						break;
					}
				}
				if(check == 0)
					sort_arr.push_back(i + 1);
			}
		}
		sort(sort_arr.begin(), sort_arr.end(), num);
		for (int i = 0; i < sort_arr.size(); i++) {
			dfs.push(sort_arr[i]);
			checkArr_dfs.push_back(sort_arr[i]);
		}
	}

	

	//인접 행렬 2차원 배열 할당 해제
	for (int i = 0; i < n; i++)
		delete[] arr[i];
	delete[] arr;

	return 0;
}