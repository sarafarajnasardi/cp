
// Author : Sarafaraj Nasardi

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<vector<pll>> vvpll;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
typedef map<int, int> mii;
typedef map<ll, ll> mll;

const ll MOD = 998244353;
const double eps = 1e-12;

#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define iv(v, n)     \
    vector<ll> v(n); \
    forn(i, n) cin >> v[i];

// unique sort :
// sort(all(v));
// v.resize(unique(all(v)) - v.begin()) ;

// Mathematical functions
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
} //__gcd

ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }

ll moduloMultiplication(ll a, ll b, ll mod)
{
    ll res = 0;
    a %= mod;
    while (b)
    {
        if (b & 1)
            res = (res + a) % mod;
        b >>= 1;
    }
    return res;
}

ll powermod(ll x, ll y, ll mod)
{
    ll ans = 1;
    if (y == 0)
        return 1;
    while (y)
    {
        if (y % 2)
            ans = (1ll * ans * x) % mod;
        x = (1ll * x * x) % mod;
        y /= 2;
    }
    return ans;
}

ll binexp(ll a, ll b, ll m)
{
    ll result = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            result = ((result % m) * (a % m)) % m;
        }
        a = ((a % m) * (a % m)) % m;
        b >>= 1;
    }
    return result;
}

vector<vector<long long>> matrixmultiply(const vector<vector<long long>> &matrix1, const vector<vector<long long>> &matrix2)
{
    int rows = matrix1.size();
    int cols = matrix2[0].size();
    int common = matrix2.size();
    vector<vector<long long>> result(rows, vector<long long>(cols, 0));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            for (int k = 0; k < common; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}

// Factorial by vector
// vll fact;
// void factorials(ll mod, ll maxi){fact.resize(maxi + 1, 1); for(int i = 2; i<= maxi ; i++) fact[i] = (fact[i-1]*i)%mod ;}
// ll nCr(ll n, ll r, ll mod){ if(r > n) return 0; ll x = (fact[r]*fact[n-r])%mod ;ll ans = (fact[n] * (powermod(x,mod-2, mod)))%mod;return ans;}
bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;
    return (ceil(log2(n)) == floor(log2(n)));
}

bool isPerfectSquare(ll x)
{
    if (x >= 0)
    {
        ll sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}
typedef vector<vector<char>> vvch;

unordered_map<ll, unordered_map<ll, unordered_map<bool, ll>>> memo;

long long rec(vvch &grid, ll i, ll j, ll d, bool check)
{
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
        return memo[i][j][check] = 0;
    if (grid[i][j] != 'X')
        return memo[i][j][check] = 0;
    if (memo[i][j].count(check))
        return memo[i][j][check];

    if (i == 0)
    {
        ll sum = 1;
        for (ll k = j + 1; k < grid[0].size() && k - j <= d; k++)
            if (grid[i][k] == 'X')
                sum++;
        for (ll k = j - 1; k >= 0 && j - k <= d; k--)
            if (grid[i][k] == 'X')
                sum++;

        return memo[i][j][check] = sum % MOD;
    }

    vector<ll> maxi;
    ll ans = 0;
    ll ans1 = 0;
    if (!check)
    {
        for (ll k = 0; k < grid[0].size(); k++)
        {
            if (k != j && grid[i][k] == 'X' && abs(k - j) <= d)
            {
                ll add = rec(grid, i, k, d, true);
                ans1 = (ans1 + add) % MOD;
            }
        }
    }

    for (ll k = 0; k < grid[0].size(); k++)
    {
        ll x = 1 + (k - j) * (k - j);
        if (x <= d * d && grid[i - 1][k] == 'X')
            ans = (ans + rec(grid, i - 1, k, d, false)) % MOD;
    }

    return memo[i][j][check] = (ans + ans1) % MOD;
}
void solve()
{
    ll n, m, d;
    cin >> n >> m >> d;

    vvll grid(n, vector<ll>(m));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            grid[i][j] = (c == 'X') ? 1 : 0;
        }
    }

    vector<vector<ll>> dp(n, vector<ll>(m, 0));
    vector<ll> pref(m, 0);

    pref[0] = grid[0][0];
    for (ll i = 1; i < m; i++)
    {
        pref[i] = (pref[i - 1] + grid[0][i]) % MOD;
    }

    for (ll i = 0; i < m; i++)
    {
        if (grid[0][i] == 1)
        {
            ll sum1 = pref[i] - (i - d - 1 >= 0 ? pref[i - d - 1] : 0);
            ll sum2 = (i + d < m) ? (pref[i + d] - pref[i]) : (pref[m - 1] - pref[i]);
            dp[0][i] = ((sum1 + sum2) % MOD + MOD) % MOD;
        }
    }
    
    for (ll i = 1; i < n; i++)
    {
        vector<ll> pref1(m, 0);
        vector<ll> pref2(m, 0);
        pref2[0] = dp[i - 1][0];

        for (ll j = 1; j < m; j++)
        {
            pref2[j] = (pref2[j - 1] + dp[i - 1][j]) % MOD;
        }

        for (ll j = 0; j < m; j++)
        {
            ll ans = 0;
            if (grid[i][j] == 1)
            {
                ll left = max(0LL, j - (ll)floor(sqrt(d * d - 1)));
                ll right = min(m - 1, j + (ll)floor(sqrt(d * d - 1)));

                ans = ((pref2[right] - (left > 0 ? pref2[left - 1] : 0)) % MOD + MOD) % MOD;
            }
            pref1[j] = (j == 0) ? ans : (pref1[j - 1] + ans) % MOD;
        }

        for (ll j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                ll sum1 = pref1[j] - (j - d - 1 >= 0 ? pref1[j - d - 1] : 0);
                ll sum2 = (j + d < m) ? (pref1[j + d] - pref1[j]) : (pref1[m - 1] - pref1[j]);
                dp[i][j] = ((sum1 + sum2) % MOD + MOD) % MOD; 
            }
        }
    }

    ll result = 0;
    for (ll j = 0; j < m; j++)
    {
        result = (result + dp[n - 1][j]) % MOD;
    }
    cout << result << "\n";
}

int main()
{
    fast_cin();
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}