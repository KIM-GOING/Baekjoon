#include <iostream>
#include <string>
using namespace std;

struct question {	//������ ���
	string num;	//������ ����
	int strike;	//���� ���ڿ� ���� ��Ʈ����ũ
	int ball;	//���� ���ڿ� ���� ��
};

int n;	//������ Ƚ��
question arr[100];	//�ִ� ���� 100��
int result; //�����

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n; 
	for (int i = 0; i < n; i++) {
		string n; int strike; int ball;
		cin >> n >> strike >> ball;
		arr[i] = { n, strike, ball };
	}
	
	//��� ���� ���鼭 ���� ���ڿ� ��
	for (int a = 1; a <= 9; a++) {	//�����ڸ�
		for (int b = 1; b <= 9; b++) {	//�����ڸ�
			if (a == b)    continue;
			for (int c = 1; c <= 9; c++) {	//�����ڸ�
				if (c == a || c == b)    continue;
				int insert[3] = { a, b, c };

				int check = 0;	//���� ���ڿ� Ʋ�� �� üũ
				for (int u = 0; u < n; u++) {
					int goal[3] = { (int)arr[u].num[0] - 48, (int)arr[u].num[1] - 48, (int)arr[u].num[2] - 48 };

					int s = 0;
					int b = 0;
					for (int i = 0; i < 3; i++) {
						if (insert[i] == goal[i])  s++;	//strike �Ǻ�

						for (int j = 0; j < 3; j++) {
							if (i != j && insert[i] == goal[j]) b++; //ball �Ǻ�
						}
					}
					if (s != arr[u].strike || b != arr[u].ball) {	//strike or ball�� �ٸ��ٸ�
						check = 1;	//�ش� ���ڴ� ���� ���� �ƴ�
						break;
					}
				}

				if (check == 0)	//strike and ball�� ��� �´ٸ�
					result++;	//���� ���� ���� ����
			}
		}
	}

	cout << result;

	return 0;
}