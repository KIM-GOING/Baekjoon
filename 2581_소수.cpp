#include <cstdio>
#include <vector>
using namespace std;

bool prime(int n) {
	int result = 0;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0)
			result++;
	}
	return result == 2;
}

int main() {
	int m, n;
	scanf_s("%d", &m);
	scanf_s("%d", &n);

	vector<int> primenum;
	int sum = 0;
	for (int i = m; i <= n; i++) {
		if (prime(i)) {
			primenum.push_back(i);
			sum += i;
		}
	}

	if (primenum.size() > 0) {
		printf("%d\n", sum);
		printf("%d", primenum[0]);
	}
	else
		printf("%d", -1);

	return 0;
}