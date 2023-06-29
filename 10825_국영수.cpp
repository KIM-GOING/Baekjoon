#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct Student {
	string name;
	int korean;
	int english;
	int math;
};

bool fx(Student a, Student b) {
	if (a.korean > b.korean)
		return true;
	else if (a.korean < b.korean)
		return a.korean > b.korean;
	else {
		if (a.english < b.english)
			return true;
		else if (a.english > b.english)
			return a.english < b.english;
		else {
			if (a.math > b.math)
				return true;
			else if (a.math < b.math)
				return a.math > b.math;
			else {
				if (a.name < b.name)
					return true;
				else if (a.name > b.name)
					return a.name < b.name;
				else
					return false;
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<Student> arr;
	for (int i = 0; i < n; i++) {
		string n;
		int k, e, m;
		cin >> n >> k >> e >> m;
		Student person;
		person.name = n;
		person.korean = k;
		person.english = e;
		person.math = m;
		arr.push_back(person);
	}

	sort(arr.begin(), arr.end(), fx);

	for (int i = 0; i < n; i++) {
		cout << arr[i].name << '\n';
	}

	return 0;
}