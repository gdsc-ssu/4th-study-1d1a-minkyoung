#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		double x, y, result;
		cin >> x >> y;

		double i = 1;
		for (;; i++) {
			if (y - x < i*i)
				break;
		}

		if (y - x == (i - 1)*(i - 1)) {
			result = 2 * (i - 1) - 1;
		}
        
		else if (y - x < ((i - 1)*(i - 1) + i * i) / 2) {
			result = 2 * (i - 1);
		}

		else {
			result = 2 * i - 1;
		}
		cout << result << '\n';
	}
}