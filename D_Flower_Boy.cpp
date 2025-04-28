// Flower Boy — O(n + m)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<ll> a(n + 1), b(m + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= m; i++) {
            cin >> b[i];
        }

        // 1) Prefix match L[i]
        vector<int> L(n + 1, 0);
        int j = 0;
        for (int i = 1; i <= n; i++) {
            if (j < m && a[i] >= b[j + 1]) {
                j++;
            }
            L[i] = j;
        }

        // If we can already collect all m flowers without insertion
        if (L[n] == m) {
            cout << 0 << '\n';
            continue;
        }

        // 2) Suffix match R[i]
        vector<int> R(n + 2, 0);
        int t2 = 0;
        for (int i = n; i >= 1; i--) {
            if (t2 < m && a[i] >= b[m - t2]) {
                t2++;
            }
            R[i] = t2;
        }

        // 3) Try insertion between positions i and i+1
        ll answer = LLONG_MAX;
        for (int i = 0; i <= n; i++) {
            int matchedPref = L[i];
            if (matchedPref == m) {
                // already matched all
                answer = 0;
                break;
            }
            // we will use inserted flower to match b[matchedPref+1]
            int needSuffix = m - (matchedPref + 1);
            // can the suffix from i+1 cover the rest?
            if (needSuffix <= R[i + 1]) {
                answer = min(answer, b[matchedPref + 1]);
            }
        }

        if (answer == LLONG_MAX) cout << -1 << '\n';
        else cout << answer << '\n';
    }
    return 0;
}
