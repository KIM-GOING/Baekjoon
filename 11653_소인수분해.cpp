#include <cstdio>
using namespace std;

int main() {
	int n;
	scanf_s("%d", &n);

	while (1) {
		if (n == 1)
			break;

		for (int i = 2; i <= n; i++) {
			if (n % i == 0) {
				printf("%d\n", i);
				n = n / i;
				break;
			}
		}
	}

	return 0;
}