#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 100000;

// Array to store the number of distinct prime factors for each number
vector<int> prime_factors_count(MAX_N + 1, 0);

// 2D array to store prefix sums for k-primes
vector<vector<int>> prefix_k_primes(101, vector<int>(MAX_N + 1, 0));

// Function to preprocess the prime factors count using a sieve-like method
void preprocess() {
    // Modified sieve to count distinct prime factors
    for (int i = 2; i <= MAX_N; ++i) {
        if (prime_factors_count[i] == 0) { // i is a prime number
            for (int j = i; j <= MAX_N; j += i) {
                prime_factors_count[j]++;
            }
        }
    }

    // Fill the prefix sums for k-primes
    for (int i = 1; i <= MAX_N; ++i) {
        int k = prime_factors_count[i];
        if (k <= 100) {
            prefix_k_primes[k][i] = 1;
        }
    }

    // Calculate prefix sums
    for (int k = 1; k <= 100; ++k) {
        for (int i = 1; i <= MAX_N; ++i) {
            prefix_k_primes[k][i] += prefix_k_primes[k][i - 1];
        }
    }
}

int main() {
    // Preprocess to fill prime_factors_count and prefix_k_primes
    preprocess();

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        if (k > 100) {
            // If k is greater than 100, there are no numbers with more than 100 distinct prime factors
            cout << 0 << endl;
        } else {
            cout << prefix_k_primes[k][n] << endl;
        }
    }

    return 0;
}
