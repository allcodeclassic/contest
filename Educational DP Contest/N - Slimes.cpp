#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numSlime;
	std::cin >> numSlime;
	std::vector<int> sizeSlime(numSlime + 1);
	std::vector<long long> preffixSum(numSlime + 1);
	for (int index = 1; index <= numSlime; index++) {
		std::cin >> sizeSlime[index];
		preffixSum[index] = preffixSum[index - 1] + sizeSlime[index];
	}
	std::vector<std::vector<long long>> minCost(numSlime + 1, std::vector<long long>(numSlime + 1, 1e18));
	for (int index = 1; index <= numSlime; index++) {
		minCost[index][index] = 0;
	}
	for (int index = 1; index + 1 <= numSlime; index++) {
		minCost[index][index + 1] = sizeSlime[index] + sizeSlime[index + 1];
	}
	for (int left = numSlime; left > 0; left--) {
		for (int right = left + 2; right <= numSlime; right++) {
			long long minCurrent = 1e18;
			for (int index = left; index < right; index++) {
				minCurrent = std::min(minCurrent, minCost[left][index] + minCost[index + 1][right]);
			}
			minCost[left][right] = preffixSum[right] - preffixSum[left - 1] + minCurrent;
		}
	}
	std::cout << minCost[1][numSlime];
	return 0;
}
