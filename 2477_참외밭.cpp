// 미완성 코드

#include <cstdio>
using namespace std;

struct edge {
	int way;
	int length;
};

int main() {
	int k;
	edge field[6] = { 0 };
	scanf_s("%d", &k);
	
	for (int i = 0; i < 6; i++) {
		int w, l;
		edge edges;
		scanf_s("%d", &w);
		scanf_s("%d", &l);
		edges.way = w;
		edges.length = l;
		field[i] = edges;
	}



	return 0;
}