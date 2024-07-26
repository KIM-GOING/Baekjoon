#include <iostream>
using namespace std;

int t;
int n;

pair<int, int> fibo[41];

void fiboInitialize() {
    fibo[0].first = 1;
    fibo[0].second = 0;
    fibo[1].first = 0;
    fibo[1].second = 1;

    for (int i = 2; i < 41; i++) {
        fibo[i].first = 0;
        fibo[i].second = 0;
    }
}

pair<int, int> fibonacci(int num) {
    if (num == 0) {
        return { fibo[0].first, fibo[0].second };
    }
    else if (num == 1) {
        return { fibo[1].first, fibo[1].second };
    }
    else {
        int zero = 0;
        int one = 0;

        // fibo[n] = fibo[n-1] + fibo[n-2]
        if (fibo[num - 1].first != 0 && fibo[num - 1].second != 0) {
            zero += fibo[num - 1].first;
            one += fibo[num - 1].second;
        }
        else {
            fibo[num - 1].first = fibonacci(num - 1).first;
            fibo[num - 1].second = fibonacci(num - 1).second;
            zero += fibo[num - 1].first;
            one += fibo[num - 1].second;
        }
        if (fibo[num - 2].first != 0 && fibo[num - 2].second != 0) {
            zero += fibo[num - 2].first;
            one += fibo[num - 2].second;
        }
        else {
            fibo[num - 2].first = fibonacci(num - 2).first;
            fibo[num - 2].second = fibonacci(num - 2).second;
            zero += fibo[num - 2].first;
            one += fibo[num - 2].second;
        }

        return { zero, one };
    }
}

int main() {
    fiboInitialize();

	cin >> t;

	while (t > 0) {
		cin >> n;

        cout << fibonacci(n).first << ' ' << fibonacci(n).second << '\n';
        
		t--;
	}

	return 0;
}