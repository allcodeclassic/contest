#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numItem, capacityKnapsack;
	std::cin >> numItem >> capacityKnapsack;
	std::vector<int> weight(numItem + 1), value(numItem + 1);
	for (int index = 1; index <= numItem; index++) {
		std::cin >> weight[index] >> value[index];
	}
	int totalValue = accumulate(value.begin(), value.end(), 0);
	std::vector<std::vector<long long>> minSumWeight(numItem + 1, std::vector<long long>(totalValue + 1, 2e9));
	minSumWeight[0][0] = 0;
	for (int item = 1; item <= numItem; item++) {
		minSumWeight[item][0] = 0;
		for (int indexValue = 0; indexValue <= totalValue; indexValue++) {
			minSumWeight[item][indexValue] = minSumWeight[item - 1][indexValue];
			if (indexValue >= value[item]) {
				minSumWeight[item][indexValue] = std::min(minSumWeight[item][indexValue], minSumWeight[item - 1][indexValue - value[item]] + weight[item]);
			}
		}
	}
	for (int index = totalValue; index > 0; index--) {
		if (minSumWeight[numItem][index] <= capacityKnapsack) {
			std::cout << index;
			return 0;
		}
	}
	return 0;
}