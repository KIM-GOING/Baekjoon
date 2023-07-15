#include <iostream>
using namespace std;

int n, kim, lim, r;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> kim >> lim;

	r = 1;

	while (kim != lim) {
		if (kim % 2 == 0)
			kim = kim / 2;
		else
			kim = kim / 2 + 1;
		if (lim % 2 == 0)
			lim = lim / 2;
		else
			lim = lim / 2 + 1;

		if (kim == lim)
			break;
		else
			r++;
	}

	cout << r;

	return 0;
}