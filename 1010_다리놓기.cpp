//미완성 코드

#include <cstdio>
using namespace std;

int main() {
	int test;
	scanf_s("%d", &test);

	int* west = new int[test];
	int* east = new int[test];

	for (int i = 0; i < test; i++) {
		int n, m;
		scanf_s("%d", &n);
		scanf_s("%d", &m);
		west[i] = n;
		east[i] = m;
	}

	
	for (int i = 0; i < test; i++) {
		long long top = 1;
		long long bottom = 1;
		int n = west[i];
		int m = east[i];

		for (int j = n; j > 0; j--) {
			top *= m - (n - j);
			bottom *= j;
		}
		printf("%d\n", top / bottom);
	}

	delete[] west;
	delete[] east;

	return 0;
}