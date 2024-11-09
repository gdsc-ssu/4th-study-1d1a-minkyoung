#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		long long s, e;
		cin >> s >> e;

		long long n = 1;
		long long dis = e - s - 2;

		if (dis <= 0) {
			cout << dis + 2 << "\n";
			continue;
		}

		while ((n*n + 3 * n) < dis) {
			n++;
		}

		if ((n*n + 2 * n) <= dis) n *= 2;
		else n = n * 2 - 1;

		cout << n + 2 << "\n";
	}

	return 0;
}