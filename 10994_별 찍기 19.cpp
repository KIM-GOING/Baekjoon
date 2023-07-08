#include <iostream>
using namespace std;

int n, length;

int main() {
    cin >> n;
    int first = n;

    int count = 0;
    while (n >= 1) {
        length = 1 + 4 * (n - 1);

        for (int i = 0; i < count; i++) {
            cout << '*' << ' ';
        }
        for (int i = 0; i < length; i++) {
            cout << '*';
        }
        for (int i = 0; i < count; i++) {
            cout << ' ' << '*';
        }

        if (n == 1) {
            cout << '\n';
            n--;
            count++;
            continue;
        }

        cout << '\n';

        for (int i = 0; i < count; i++) {
            cout << '*' << ' ';
        }
        cout << '*';
        for (int i = 0; i < length - 2; i++) {
            cout << ' ';
        }
        cout << '*';
        for (int i = 0; i < count; i++) {
            cout << ' ' << '*';
        }

        cout << '\n';
        n--;
        count++;
    }
    n += 2;
    count -= 2;

    while (n <= first) {
        length = 1 + 4 * (n - 1);

        for (int i = 0; i < count; i++) {
            cout << '*' << ' ';
        }
        cout << '*';
        for (int i = 0; i < length - 2; i++) {
            cout << ' ';
        }
        cout << '*';
        for (int i = 0; i < count; i++) {
            cout << ' ' << '*';
        }

        cout << '\n';

        for (int i = 0; i < count; i++) {
            cout << '*' << ' ';
        }
        for (int i = 0; i < length; i++) {
            cout << '*';
        }
        for (int i = 0; i < count; i++) {
            cout << ' ' << '*';
        }

        cout << '\n';

        n++;
        count--;
    }

    return 0;
}
