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
	int size;
	scanf_s("%d", &size);

	vector<int> numbers;
	for (int i = 0; i < size; i++) {
		int num;
		scanf_s("%d", &num);
		numbers.push_back(num);
	}

	int sum = 0;
	for (int i = 0; i < size; i++) {
		if (prime(numbers[i]))
			sum++;
	}

	printf("%d", sum);

	return 0;
}