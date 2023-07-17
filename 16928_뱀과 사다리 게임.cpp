#include <iostream>
#include <queue>
using namespace std;

struct Bridge {	//��ٸ� ����
	int from;
	int to;
};

int n, m;
Bridge bridge[30] = { 0, };
queue<int> q;	//�ʺ�켱Ž��
int now;	//���� ���� ��ġ
int nowCount;	//���� ��ġ���� ���µ��� �ֻ��� ���� Ƚ��
int visited[101] = { 0, };	//�� ��ġ���� ���°��� �ֻ��� ���� Ƚ�� ����
int v[101] = { 0, }; //�湮üũ

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n+m; i++) {	//������� ���� ����
		int a, b;
		cin >> a >> b;
		bridge[i] = { a, b };
	}

	q.push(1);	//�������� 1���� ����
	v[1] = 1;
	while (v[100] != 1) {
		now = q.front();
		nowCount = visited[q.front()];
		q.pop();

		for (int i = 1; i <= 6; i++) {	//�ֻ����� 6�� ���� ��
			int check2 = 0;
			for (int j = 0; j < n + m; j++) {
				if (now + i == bridge[j].from) {
					q.push(bridge[j].to);
					if(visited[bridge[j].to] == 0)
						visited[bridge[j].to] = nowCount + 1;
					v[bridge[j].from] = 1;
					v[bridge[j].to] = 1;
					check2 = 1;
					break;
				}
			}

			if (check2 == 0 && v[now + i] == 0) {
				q.push(now + i);
				visited[now + i] = nowCount + 1;
				v[now + i] = 1;
			}
		}
	}

	cout << visited[100];

	return 0;
}