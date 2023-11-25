#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numLight, numScenario;
	std::cin >> numLight >> numScenario;
	std::vector<long long> multipleLight(numLight + 1);
	multipleLight[0] = 1;
	int countAvailable = 0;
	for (int index = 1; index <= numLight; index++) {
		int time;
		std::cin >> time;
		long long current = multipleLight[index - 1] / std::__gcd(multipleLight[index - 1], 1ll * time) * time;
		multipleLight[index] = current;
		countAvailable++;
		if (current > 1e9) {
			break;
		}
	}
	for (int index = countAvailable; index < numLight; index++) {
		int time;
		std::cin >> time;
	}
	while (numScenario--) {
		int time;
		std::cin >> time;
		int low = 1, high = countAvailable, result = -1;
		while (low <= high) {
			int middle = ((low + high) >> 1);
			if (time % multipleLight[middle] == 0) {
				low = middle + 1;
			} else {
				high = middle - 1;
				result = middle;
			}
		}
		std::cout << result << '\n';
	}
	return 0;
}
