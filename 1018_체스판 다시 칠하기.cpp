#include <iostream>
#include <string>
using namespace std;

int n, m;
int wcount = 0;
int bcount = 0;
int minW = 10000;
int minB = 10000;

string board[51];
string WB[8] = { "WBWBWBWB" ,
				 "BWBWBWBW" ,
				 "WBWBWBWB" ,
				 "BWBWBWBW" ,
				 "WBWBWBWB" ,
				 "BWBWBWBW" ,
				 "WBWBWBWB" ,
				 "BWBWBWBW" };
string BB[8] = { "BWBWBWBW" ,
				 "WBWBWBWB" ,
				 "BWBWBWBW" ,
				 "WBWBWBWB" ,
				 "BWBWBWBW" ,
				 "WBWBWBWB" ,
				 "BWBWBWBW" ,
				 "WBWBWBWB" };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> board[i];

	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			for (int x = 0; x < 8; x++) {
				for (int y = 0; y < 8; y++) {
					if (board[x + i][y + j] != WB[x][y])
						wcount++;
					if (board[x + i][y + j] != BB[x][y])
						bcount++;
				}
			}
			if (minW > wcount)
				minW = wcount;
			if (minB > bcount)
				minB = bcount;
			wcount = 0;
			bcount = 0;
		}
	}

	if (minW >= minB)
		cout << minB;
	else
		cout << minW;

	return 0;
}