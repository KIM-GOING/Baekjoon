#include <iostream>
using namespace std;

int n, m;
int parent[1000001];

int Find(int x) {
	if (parent[x] == x) return parent[x];
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	int px = Find(x);
	int py = Find(y);
	if (px == py) return;
	parent[py] = px;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i <= n; i++)
		parent[i] = i;

	for (int u = 0; u < m; u++) {
		int q, a, b;
		cin >> q >> a >> b;

		if (q == 0)
			Union(a, b);
		else
			if (Find(a) == Find(b))
				cout << "YES" << '\n';
			else
				cout << "NO" << '\n';
	}

	return 0;
}