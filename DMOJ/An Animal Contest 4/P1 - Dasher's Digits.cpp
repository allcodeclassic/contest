#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int lengthString, num0;
	std::cin >> lengthString >> num0;
	std::string letters;
	std::cin >> letters;
	std::vector<int> position0(num0);
	for (int index = 0; index < num0; index++) {
		std::cin >> position0[index];
	}
	int maxPosition = -1e9, last = 0;
	for (int index = 0, indexPosition0 = 0; index < lengthString; index++) {
		if (letters[index] == '0') {
			int current = position0[indexPosition0];
			indexPosition0++;
			if (current >= maxPosition) {
				maxPosition = current;
				last = index;
			}
		}
	}
	for (int index = 0; index < lengthString; index++) {
		char letter = letters[(index + last) % lengthString];
		if (letter != '0') {
			std::cout << letter;
		}
	}
	std::cout << '\n';
	return 0;
}
