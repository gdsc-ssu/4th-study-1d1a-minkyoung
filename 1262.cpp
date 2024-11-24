#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, r1, c1, r2, c2;
	cin >> n >> r1 >> c1 >> r2 >> c2;

	for (int i = 0,s=r1; i < r2 - r1 + 1; i++,s++) {
		for (int j = 0,e=c1; j < c2 - c1+1; j++,e++) {
			int x = s % (2 * n - 1);
			int y = e % (2 * n - 1);
			int dis = abs((n - 1) - x) + abs((n - 1) - y);

			if (dis >= n)cout << ".";
			else cout << (char)((dis%26)+'a');
		}
		cout << "\n";
	}
	return 0;
}