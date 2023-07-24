#include <iostream>
#include <vector>
using namespace std;

int n;	//연산의 개수(1 <= n <= 100,000)
vector<int> heap;	//최소힙

void enqueue(int num) {	//우선순위 큐 삽입연산
	heap.push_back(num);	//이진트리 끝에 숫자 삽입

	int index = heap.size() - 1;
	while (heap[index / 2] > heap[index]) {	//부모노드가 자식노드보다 작다면
		int temp = heap[index / 2];
		heap[index / 2] = heap[index];
		heap[index] = temp;
		index = index / 2;
		if (index == 1)
			break;
	}
}

void dequeue() {	//우선순위 큐 삭제연산
	if (heap.size() - 1 == 0) {
		cout << 0 << '\n';
		return;
	}
	else
		cout << heap[1] << '\n';	//우선순위 큐 제일 상단 출력

	if (heap.size() - 1 == 1)	//우선순위 큐 크기가 1이라면
		heap.pop_back();	//그냥 삭제 끝.

	else if (heap.size() - 1 == 2) {	//우선순위 큐 크기가 2이라면
		heap[1] = heap[heap.size() - 1];	//제일 끝 요소를 1번 index로 옮기고
		heap.pop_back();	//제일 끝 요소 삭제
	}

	else if (heap.size() - 1 == 3) {	//우선순위 큐 크기가 3이라면
		heap[1] = heap[heap.size() - 1];	//제일 끝 요소를 1번 index로 옮기고
		heap.pop_back();	//제일 끝 요소 삭제

		if (heap[1] > heap[2]) {
			int temp = heap[1];
			heap[1] = heap[2];
			heap[2] = temp;
		}
	}

	else {	//우선순위 큐 크기가 4 이상이라면
		heap[1] = heap[heap.size() - 1];	//제일 끝 요소를 1번 index로 옮기고
		heap.pop_back();	//제일 끝 요소 삭제

		int index = 1;
		int min = 0;	//자식 노드 중 작은 노드
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

	heap.push_back(0);	//index 0번은 사용하지 않을 것임

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