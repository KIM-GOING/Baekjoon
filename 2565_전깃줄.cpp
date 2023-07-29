#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Line {
	int a;
	int b;
	int share;
};

int n;	// n <= 100
vector<Line> line;

bool fx(const Line& a, const Line& b) {
	return a.share > b.share;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		line.push_back({ x, y, 0 });
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)	continue;
			if (line[i].a < line[j].a && line[i].b > line[j].b)	line[i].share++;
			if (line[i].a > line[j].a && line[i].b < line[j].b) line[i].share++;
		}
	}

	sort(line.begin(), line.end(), fx);

	int front = 0;
	while (line[front].share != 0) {
		front++;

		for (int i = front; i < n; i++) {
			for (int j = front; j < n; j++) {
				if (i == j)	continue;
				if (line[i].a < line[j].a && line[i].b > line[j].b)	line[i].share++;
				if (line[i].a > line[j].a && line[i].b < line[j].b) line[i].share++;
			}
		}
	}

	cout << front;

	return 0;
}