#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int m, n;
	scanf_s("%d", &m);
	scanf_s("%d", &n);

	// 메모리 동적 할당
	bool* arr;
	arr = new bool[n + 1] { };	// 인덱스와 숫자의 대치를 같게하기 위해 n+1
	fill_n(arr, n+1, true);

	// 소수 분류 알고리즘
	for (int i = 2; i <= sqrt(n); i++)
		if (arr[i] == true)
			for (int j = i * 2; j <= n; j += i)
				arr[j] = false;

	for (int i = m; i <= n; i++)
		if (arr[i] == true)
			printf("%d\n", i);

	delete[] arr;

	return 0;
}