#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> students;
	for (int i = 0; i < 28; i++) {
		int num;
		scanf_s("%d", &num);
		students.push_back(num);
	}

	for (int i = 1; i <= 30; i++) {
		if (find(students.begin(), students.end(), i) == students.end())
			printf("%d\n", i);
	}

	return 0;
}