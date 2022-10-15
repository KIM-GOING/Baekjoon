#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int m, n;
	scanf_s("%d", &m);
	scanf_s("%d", &n);

	// �޸� ���� �Ҵ�
	bool* arr;
	arr = new bool[n + 1] { };	// �ε����� ������ ��ġ�� �����ϱ� ���� n+1
	fill_n(arr, n+1, true);

	// �Ҽ� �з� �˰���
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