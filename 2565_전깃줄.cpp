#include <iostream>
#include <algorithm>
using namespace std;

struct Line {
	int a;
	int b;
	int share;
};

int n;	// n <= 100
Line line[101];

bool fx(Line a, Line b) {
	return a.share >= b.share;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		line[i] = { x, y, 0 };
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)	continue;
			if (line[i].a < line[j].a && line[i].b > line[j].b)	line[i].share++;
			if (line[i].a > line[j].a && line[i].b < line[j].b) line[i].share++;
		}
	}

	sort(line, line + n, fx);

	for (int i = 0; i < n; i++)
		cout << line[i].share << '\n';

	return 0;
}