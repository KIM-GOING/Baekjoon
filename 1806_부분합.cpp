#include <iostream>
using namespace std;

int n;
int arr[100001];
long long s;
long long sum[100001];
int length;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> s;
	
	int ss = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		ss = arr[i] + ss;
		sum[i] = ss;
	}

	int f = -1;
	int e = 0;
	int first, last;

	while (e < n) {
		if (f == -1)
			first = 0;
		else
			first = sum[f];
		last = sum[e];

		if (last - first >= s) {
			if(length == 0)
				length = e - f;
			else if(length > e - f)
				length = e - f;
			f++;
		}
		else
			e++;
	}

	if (length == 0)
		cout << 0;
	else
		cout << length;

	return 0;
}