#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int sizeStr;
	std::cin >> sizeStr;
	std::string str;
	std::cin >> str;
	str = ' ' + str;
	// longest common subsequence between str and reverse of str
	std::vector<int> previous(sizeStr + 1, 0), current(sizeStr + 1, 0);
	for (int index = 1; index <= sizeStr; index++) {
		for (int indexReverse = 1; indexReverse <= sizeStr; indexReverse++) {
			if (str[index] == str[sizeStr - indexReverse + 1]) {
				current[indexReverse] = previous[indexReverse - 1] + 1;
			} else {
				current[indexReverse] = std::max(current[indexReverse - 1], previous[indexReverse]);
			}
		}
		previous = current;
	}
	std::cout << sizeStr - current[sizeStr];
	return 0;
}