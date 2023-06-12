/*
int main() {
	int weight;
	scanf_s("%d", &weight);

	int sum = 0;
	int num = weight / 2;

	for (int i = num; i >= 1; i--) {
		if (weight % 2 == 0)
			sum += 1;
		int two = num;
		int one = weight % 2;
	}
	

	return 0;
}
*/

#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int weight;
	scanf_s("%d", &weight);

	vector<int> weights;
	for (int i = 0; i < weight; i++) {
		int num = 0;
		if (i == 0)
			num = 1;
		else if (i == 1)
			num = 2;
		else 
			num = weights[i - 2] + weights[i - 1];
		weights.push_back(num);
	}



	return 0;
}