#include <iostream>
#include <vector>
using namespace std;

struct prefix_sum {
	int num = 0;
	int sum = 0;
};
int n, m, f, e, c, s = 0;
vector<prefix_sum> arr;	//인덱스에 해당하는 누적합 저장 구조체

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int n;
		cin >> n;
		s += n;
		arr.push_back({n,s});
	}

	while (e <= n - 1) {
		int first, last;
		if (f == 0)
			first = 0;
		else
			first = arr[f - 1].sum;

		last = arr[e].sum;

		if (last - first >= m){
			f++;
			if(last - first == m)
				c++;
		}
		else  {
			e++;
		}
	}

	cout << c;

	return 0;
}