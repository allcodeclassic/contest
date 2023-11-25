#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numNode, numEdge;
	std::cin >> numNode >> numEdge;
	std::vector<std::vector<int>> adjacent(numNode);
	while (numEdge--) {
		int u, v;
		std::cin >> u >> v;
		u--; v--;
		adjacent[u].emplace_back(v);
	}
	std::vector<int> longestPathStart(numNode, -1);
	std::function<int(int)> depthFirstSearch = [&](int currentNode) {
		if (longestPathStart[currentNode] != -1) {
			return longestPathStart[currentNode];
		}
		longestPathStart[currentNode] = 0;
		for (int nextNode : adjacent[currentNode]) {
			longestPathStart[currentNode] = std::max(longestPathStart[currentNode], depthFirstSearch(nextNode) + 1);
		}
		return longestPathStart[currentNode];
	};
	int result = 0;
	for (int node = 0; node < numNode; node++) {
		result = std::max(result, depthFirstSearch(node));
	}
	std::cout << result;
	return 0;
}
