#include <iostream>
#include <vector>
using namespace std;

long long n, m;
long long nums[1000001];	//숫자 저장 배열
long long sums[1000001];	//누적 합 저장 배열
long long shared[1001];	//누적합을 m으로 나눴을 때 나머지
long long result;	//최종 결과값

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
		shared[sums[i] % m]++;	//누적합을 m으로 나눈 나머지에 해당하는 숫자를 1 증가시킴
	}

	result += shared[0];  //누적합 나머지가 0 == 그 자체 숫자를 m으로 나눴을 때도 0
	for (int i = 0; i < m; i++)
		result += shared[i] * (shared[i] - 1) / 2;	//조합

	cout << result;

	return 0;
}