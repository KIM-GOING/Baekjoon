#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string n;
int sum, result, check;
vector<int> arr;

int fx(int a, int b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n.size(); i++) {
		sum += (int)n[i] - 48;	//�� �ڸ����� ���� 3�� ������� �Ǻ��ϱ� ���� �� ����
		arr.push_back((int)n[i] - 48);	//�ڸ� ���� ������ ���� ���Ϳ� ����
		if ((int)n[i] - 48 == 0)	//30�� ��� ������ 0�� ������ �˱� ���� �ܰ�
			check = 1;
	}
	if (sum % 3 != 0 || check == 0) {		//30�� ����� �ȵǴ� ����
		cout << -1;
		return 0;
	}
	else {
		sort(arr.begin(), arr.end(), fx);	//�������� ����
		for (int i = 0; i < arr.size(); i++) {
			cout << arr[i];
		}
		return 0;
	}
}