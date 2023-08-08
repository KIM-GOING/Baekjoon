#include <iostream>
#include <vector>
using namespace std;

int n;	//���� ����
int cal;	//������ ����
int nums[11];	//���꿡 ����� ���� �迭
int cals[10];	//���꿡 ����� ������ �迭
int calsV[10];	//������ �迭 �湮 üũ
vector<int> calArray;	//������ ����

int minN = 1000000000;	//�ּڰ�
int maxN = -1000000000;	//�ִ�

int sum(int a, int b) {
	return a + b;
}

int sub(int a, int b) {
	return a - b;
}

int mul(int a, int b) {
	return a * b;
}

int division(int a, int b) {
	return a / b;
}

void back(int a) {
	if (a == cal) {
		int result = nums[0];
		for (int i = 0; i < cal; i++) {
			if (calArray[i] == 0)
				result = sum(result, nums[i + 1]);
			else if (calArray[i] == 1)
				result = sub(result, nums[i + 1]);
			else if (calArray[i] == 2)
				result = mul(result, nums[i + 1]);
			else
				result = division(result, nums[i + 1]);
		}
		
		if (result > maxN)
			maxN = result;
		if (result < minN)
			minN = result;

		return;
	}

	for (int i = 0; i < cal; i++) {
		if (calsV[i] == 0) {
			calArray.push_back(cals[i]);
			calsV[i] = 1;

			back(a + 1);

			calArray.pop_back();
			calsV[i] = 0;
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> nums[i];

	cal = n - 1;

	int index = 0;
	for (int i = 0; i < 4; i++) {
		int c;
		cin >> c;

		for (int j = 0; j < c; j++) {
			cals[index] = i;
			index++;
		}
	}
	
	back(0);

	cout << maxN << '\n' << minN;

	return 0;
}