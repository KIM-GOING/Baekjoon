#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

struct triangle {
	int edge[3] = {};
};

int main() {
	vector<triangle> arr;

	while (1) {
		triangle tri = {};
		int a, b, c;
		scanf_s("%d", &a);
		scanf_s("%d", &b);
		scanf_s("%d", &c);

		if (a == 0 && b == 0 && c == 0)
			break;

		tri.edge[0] = a;
		tri.edge[1] = b;
		tri.edge[2] = c;
		arr.push_back(tri);
	}

	for (int i = 0; i < arr.size(); i++) {
		int max = arr[i].edge[0];
		int bigEdgeNum = 0;
		for (int j = 0; j < 3; j++) {
			if (max < arr[i].edge[j]) {
				max = arr[i].edge[j];
				bigEdgeNum = j;
			}
		}

		int bigEdge = max;
		int extraEdge = 0;
		for (int j = 0; j < 3; j++) {
			if (bigEdgeNum != j)
				extraEdge += pow(arr[i].edge[j], 2);
		}
		if (pow(max, 2) == extraEdge)
			printf("right\n");
		else
			printf("wrong\n");
	}

	return 0;
}