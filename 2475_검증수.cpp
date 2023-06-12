#include <cstdio>
#include <cmath>
using namespace std;


int main() {
	int num[5] = { 0 };
	for (int i = 0; i < 5; i++)
		scanf_s("%d", &num[i]);

	int sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += pow(num[i], 2);
	}

	int final_num = sum % 10;

	printf("%d", final_num);

	return 0;
}