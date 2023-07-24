#include <iostream>
#include <vector>
using namespace std;

int n;	//������ ����(1 <= n <= 100,000)
vector<int> heap;	//�ּ���

void enqueue(int num) {	//�켱���� ť ���Կ���
	heap.push_back(num);	//����Ʈ�� ���� ���� ����

	int index = heap.size() - 1;
	while (heap[index / 2] > heap[index]) {	//�θ��尡 �ڽĳ�庸�� �۴ٸ�
		int temp = heap[index / 2];
		heap[index / 2] = heap[index];
		heap[index] = temp;
		index = index / 2;
		if (index == 1)
			break;
	}
}

void dequeue() {	//�켱���� ť ��������
	if (heap.size() - 1 == 0) {
		cout << 0 << '\n';
		return;
	}
	else
		cout << heap[1] << '\n';	//�켱���� ť ���� ��� ���

	if (heap.size() - 1 == 1)	//�켱���� ť ũ�Ⱑ 1�̶��
		heap.pop_back();	//�׳� ���� ��.

	else if (heap.size() - 1 == 2) {	//�켱���� ť ũ�Ⱑ 2�̶��
		heap[1] = heap[heap.size() - 1];	//���� �� ��Ҹ� 1�� index�� �ű��
		heap.pop_back();	//���� �� ��� ����
	}

	else if (heap.size() - 1 == 3) {	//�켱���� ť ũ�Ⱑ 3�̶��
		heap[1] = heap[heap.size() - 1];	//���� �� ��Ҹ� 1�� index�� �ű��
		heap.pop_back();	//���� �� ��� ����

		if (heap[1] > heap[2]) {
			int temp = heap[1];
			heap[1] = heap[2];
			heap[2] = temp;
		}
	}

	else {	//�켱���� ť ũ�Ⱑ 4 �̻��̶��
		heap[1] = heap[heap.size() - 1];	//���� �� ��Ҹ� 1�� index�� �ű��
		heap.pop_back();	//���� �� ��� ����

		int index = 1;
		int min = 0;	//�ڽ� ��� �� ���� ���
		while (1) {
			if (heap.size() - 1 >= index * 2 + 1) {
				if (heap[index * 2] <= heap[index * 2 + 1])
					min = index * 2;
				else
					min = index * 2 + 1;

				if (heap[index] > heap[min]) {
					int temp = heap[index];
					heap[index] = heap[min];
					heap[min] = temp;
					index = min;
				}
				else
					break;
			}
			else if (heap.size() - 1 >= index * 2) {
				min = index * 2;

				if (heap[index] > heap[min]) {
					int temp = heap[index];
					heap[index] = heap[min];
					heap[min] = temp;
					index = min;
				}
				else
					break;
			}
			else
				break;
		}

	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	heap.push_back(0);	//index 0���� ������� ���� ����

	cin >> n;

	for (int u = 0; u < n; u++) {
		int x;
		cin >> x;

		if (x == 0)
			dequeue();

		else
			enqueue(x);
	}

	return 0;
}