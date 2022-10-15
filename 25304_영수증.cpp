#include <cstdio>
#include <vector>
using namespace std;

struct product {
	int price;
	int num;
	product(int p = 0, int n = 0) { price = p; num = n; };
};

int main() {
	int totalPrice;
	int num;
	vector<product> products;

	scanf_s("%d", &totalPrice);
	scanf_s("%d", &num);

	for (int i = 0; i < num; i++) {
		int p, n;
		scanf_s("%d", &p);
		scanf_s("%d", &n);
		products.push_back(product(p, n));
	}

	int sumPrice = 0;
	for (int i = 0; i < num; i++) {
		sumPrice += products[i].price * products[i].num;
	}

	if (sumPrice == totalPrice)
		printf("Yes");
	else
		printf("No");

	return 0;
}