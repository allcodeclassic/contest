#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numChoose, numStone;
	std::cin >> numChoose >> numStone;
	std::vector<int> choose(numChoose);
	for (int index = 0; index < numChoose; index++) {
		std::cin >> choose[index];
	}
	std::vector<bool> canRemove(numStone);
	for (int stone = 0; stone <= numStone; stone++) {
		for (int index = 0; index < numChoose; index++) {
			if (stone >= choose[index] && !canRemove[stone - choose[index]]) {
				canRemove[stone] = true;
			}
		}
	}
	std::cout << (canRemove[numStone] ? "First" : "Second");
	return 0;
}
