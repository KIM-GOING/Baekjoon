#include <iostream>
#include <queue>
#define INF 99999999
using namespace std;

struct info {
	int dist;
	int goal;
};

struct fx {	//�켱���� ť ���Լ�
	bool operator()(info a, info b) {
		if (a.dist <= b.dist)
			return true;
		else
			return false;
	}
};

int v; //������ ����
int e; //������ ����
int start; //��������

int dist[20001][20001]; //���� �� ����ġ �迭
int dp[20001];	//�ִܰ�� ���� dp
int visited[20001];
priority_queue<info, vector<info>, fx> pq;	//�켱���� ť

int selectV() {

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> v >> e;
	cin >> start;

	for (int i = 0; i < e; i++) {
		int v1, v2, d;
		cin >> v1 >> v2 >> d;
		dist[v1][v2] = d;
	}

	for (int i = 1; i <= v; i++) {
		if (i == 1)
			dp[i] = 0;
		else if (dist[start][i] != 0)
			dp[i] = dist[start][i];
		else
			dp[i] = INF;
	}
	
	visited[1] = 1;

	for (int i = 1; i <= v - 2; i++) {
		int minV;

	}

	return 0;
}