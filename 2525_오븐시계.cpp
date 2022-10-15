#include <iostream>
using namespace std;

int main() {
	int hour = 0, min = 0, add_min = 0;
	int extra_hour = 0, extra_min = 0;
	int result_hour = 0, result_min = 0;
	cin >> hour >> min;
	cin >> add_min;

	if (min + add_min < 60) {
		result_hour = hour;
		result_min = min + add_min;
	}
	else {
		extra_hour = (min + add_min) / 60;
		if (hour + extra_hour < 24)
			result_hour = hour + extra_hour;
		else
			result_hour = (hour + extra_hour) % 24;
		result_min = (min + add_min) % 60;
	}

	cout << result_hour << " " << result_min;

	return 0;
}