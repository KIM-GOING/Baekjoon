#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());

	int m;
	cin >> m;
	vector<int> arr2;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		arr2.push_back(num);
	}

	for (int i = 0; i < m; i++) {
		int goal = arr2[i];
		int count = upper_bound(arr.begin(), arr.end(), goal) - lower_bound(arr.begin(), arr.end(), goal);
		cout << count << '\n';
	}

	/*	직접 구현했는데 시간초과. 문제를 모르겠음.
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		arr2.push_back(num);

		int goal = arr2[i];
		int l = 0;
		int h = n - 1;
		int check = (h + l) / 2;
		int count = 0;
		while (1) {
			if (arr[check] == goal) {
				int temp = check;
				count++;
				int ch_l = check - 1;
				int ch_h = check + 1;
				while (ch_l != -1 && ch_h != n) {
					if (arr[ch_l] == goal) {
						count++;
						check = check - 1;
					}
					if (arr[ch_h] == goal) {
						count++;
						check = check + 1;
					}
				}
				cout << count << '\n';
				break;
			}
			else if (arr[check] < goal) {
				if (l >= h) {
					cout << 0 << '\n';
					break;
				}
				l = check + 1;
				check = (h + l) / 2;
			}
			else if (arr[check] > goal) {
				if (l >= h) {
					cout << 0 << '\n';
					break;
				}
				h = check - 1;
				check = (h + l) / 2;
			}
		}
	}
	*/

	return 0;
}