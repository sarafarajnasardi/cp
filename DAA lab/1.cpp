#include <iostream>

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long L, R;
    std::cin >> L >> R;

    // The problem statement implies that all trees in the given range are
    // considered "unlucky" because no specific rule is provided to determine
    // the number of magical fruits for each tree number.
    // Given the sample output (L=5, R=5 -> 1), it supports the interpretation
    // that every tree in the range [L, R] is considered unlucky.
    // Therefore, we just need to count the total number of trees in the range.
    long long count_unlucky_trees = R - L + 1;

    std::cout << count_unlucky_trees << std::endl;

    return 0;
}