#include <iostream>
#include <vector>
using namespace std;

long long n, m;
long long nums[1000001];	//���� ���� �迭
long long sums[1000001];	//���� �� ���� �迭
long long shared[1001];	//�������� m���� ������ �� ������
long long result;	//���� �����

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
		sum += nums[i];
		sums[i] = sum;
		shared[sums[i] % m]++;	//�������� m���� ���� �������� �ش��ϴ� ���ڸ� 1 ������Ŵ
	}

	result += shared[0];  //������ �������� 0 == �� ��ü ���ڸ� m���� ������ ���� 0
	for (int i = 0; i < m; i++)
		result += shared[i] * (shared[i] - 1) / 2;	//����

	cout << result;

	return 0;
}