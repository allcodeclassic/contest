#include <bits/stdc++.h>

const int MODULO = 1e9 + 7;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numNode;
	std::cin >> numNode;
	std::vector<std::vector<int>> adjacent(numNode);
	for (int index = 0; index < numNode - 1; index++) {
		int u, v;
		std::cin >> u >> v;
		u--; v--;
		adjacent[u].emplace_back(v);
		adjacent[v].emplace_back(u);
	}
	std::vector<std::vector<long long>> numWay(numNode, std::vector<long long>(2)); // 0-white 1-black
	std::function<void(int, int)> depthFirstSearch = [&] (int currentNode, int previousNode) {
		numWay[currentNode][0] = numWay[currentNode][1] = 1;
		for (int nextNode : adjacent[currentNode]) {
			if (nextNode != previousNode) {
				depthFirstSearch(nextNode, currentNode);
				numWay[currentNode][0] = numWay[currentNode][0] * ((numWay[nextNode][0] + numWay[nextNode][1]) % MODULO) % MODULO;
				numWay[currentNode][1] = numWay[currentNode][1] * numWay[nextNode][0] % MODULO;
			}
		}
	};
	depthFirstSearch(0, -1);
	std::cout << (numWay[0][0] + numWay[0][1]) % MODULO;
	return 0;
}
