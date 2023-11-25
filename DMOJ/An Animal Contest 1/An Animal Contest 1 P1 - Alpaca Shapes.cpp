#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numNode;
	std::cin >> numNode;
	std::vector<std::tuple<int, int, int>> edge(numNode - 1);
	std::vector<std::vector<std::pair<int, int>>> adjacent(numNode);
	for (int index = 0; index < numNode - 1; index++) {
		int u, v, distanceUV;
		std::cin >> u >> v >> distanceUV;
		u--; v--;
		distanceUV &= 1;
		edge[index] = std::tie(u, v, distanceUV);
		adjacent[u].emplace_back(v, distanceUV);
		adjacent[v].emplace_back(u, distanceUV);
	}
	std::vector<std::vector<int>> count(numNode, std::vector<int>(2));
	std::function<void(int, int, int)> depthFirstSearch = [&](int currentNode, int previousNode, int depth) {
		count[currentNode][depth & 1]++;
		for (auto [nextNode, distanceCurrentNext] : adjacent[currentNode]) {
			if (nextNode != previousNode) {
				depthFirstSearch(nextNode, currentNode, depth + distanceCurrentNext);
				count[currentNode][0] += count[nextNode][0];
				count[currentNode][1] += count[nextNode][1];
			}
		}
	};
	depthFirstSearch(0, -1, 0);
	long long totalEdgeOdd = 1ll * count[0][0] * count[0][1];
	long long totalEdgeEven = 1ll * numNode * (numNode - 1) / 2 - totalEdgeOdd;
	long long result = abs(totalEdgeOdd - totalEdgeEven);
	for (int index = 1; index < numNode; index++) {
		int newCountOdd = count[0][0] + count[index][1] - count[index][0];
		int newCountEven = count[0][1] + count[index][0] - count[index][1];
		long long newTotalEdgeOdd = 1ll * newCountOdd * newCountEven;
		long long newTotalEdgeEven = 1ll * numNode * (numNode - 1) / 2 - newTotalEdgeOdd;
		result = std::min(result, abs(newTotalEdgeOdd - newTotalEdgeEven));
	}
	std::cout << result;
	return 0;
}