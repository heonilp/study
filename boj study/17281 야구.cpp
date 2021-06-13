#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int>> mat;
int nusang[3];
int main(void) {

	int n;
	cin >> n;
	mat = vector<vector<int>>(n, vector<int>(9));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> mat[i][j];
		}
	}

	vector<int> d = { 1, 2, 3, 4, 5, 6 ,7, 8 };
	int ans = -1;



	do {
		int idx[9];
		memset(idx, 0, sizeof(idx));

		for (int i = 0; i < 3; i++) {
			idx[i] = d[i];
		}

		for (int i = 3; i < 8; i++) {
			idx[i + 1] = d[i];
		}

		int num = 0, player = idx[0];
		int inning = 0, score = 0, out = 0;
		memset(nusang, 0, sizeof(nusang));

		while (inning < n) {
			if (mat[inning][player] == 0) {
				out += 1;
			}

			else if (mat[inning][player] == 1) {
				if (nusang[2] == 1) {
					score += 1;
					nusang[2] = 0;
				}

				if (nusang[1] == 1) {
					nusang[2] = 1;
					nusang[1] = 0;
				}

				if (nusang[0] == 1) {
					nusang[1] = 1;
					nusang[0] = 0;
				}
				nusang[0] = 1;
			}

			else if (mat[inning][player] == 2) {

				if (nusang[2] == 1) {
					score += 1;
					nusang[2] = 0;
				}

				if (nusang[1] == 1) {
					score += 1;
					nusang[1] = 0;
				}

				if (nusang[0] == 1) {
					nusang[2] = 1;
					nusang[0] = 0;
				}

				nusang[1] = 1;

			}

			else if (mat[inning][player] == 3) {

				if (nusang[2] == 1) {
					score += 1;
					nusang[2] = 0;
				}

				if (nusang[1] == 1) {
					score += 1;
					nusang[1] = 0;
				}

				if (nusang[0] == 1) {
					score += 1;
					nusang[0] = 0;
				}

				nusang[2] = 1;

			}

			else if (mat[inning][player] == 4) {

				int check = 0;

				for (int i = 0; i < 3; i++) {

					if (nusang[i] == 1) {
						check += 1;
						nusang[i] = 0;

					}

				}
				score += check + 1;
			}



			if (out == 3) {
				out = 0;
				memset(nusang, 0, sizeof(nusang));
				inning += 1;
			}

			if (++num == 9) {
				num = 0;
			}

			player = idx[num];

		}

		if (ans == -1 || score > ans) {
			ans = score;
		}

	} while (next_permutation(d.begin(), d.end()));



	cout << ans << '\n';

	return 0;

}