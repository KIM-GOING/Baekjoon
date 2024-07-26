#include <iostream>
using namespace std;

int n, t, p;
int s[6];
int tshirt = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < 6; i++) 
		cin >> s[i];
	
	cin >> t >> p;

	for (int i = 0; i < 6; i++) {
		if (s[i] == 0)
			continue;
		else if (s[i] <= t)
			tshirt++;
		else {
			if (s[i] % t != 0)
				tshirt += s[i] / t + 1;
			else
				tshirt += s[i] / t;
		}
	}

	cout << tshirt << '\n';
	cout << n / p << ' ' << n % p;

	return 0;
}