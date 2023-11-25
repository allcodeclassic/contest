#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int numStone;
    std::cin >> numStone;
    std::vector<int> heightStone(numStone);
    for (int index = 0; index < numStone; index++) {
        std::cin >> heightStone[index];
    }
    std::vector<int> dp(numStone, 1e9);
    dp[0] = 0;
    for (int index = 1; index < numStone; index++) {
        dp[index] = dp[index - 1] + abs(heightStone[index] - heightStone[index - 1]);
        if (index > 1) {
            dp[index] = std::min(dp[index], dp[index - 2] + abs(heightStone[index] - heightStone[index - 2]));
        }
    }
    std::cout << dp[numStone - 1];
    return 0;
}
