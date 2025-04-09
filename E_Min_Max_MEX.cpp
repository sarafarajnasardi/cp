
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
long long mexi( vector<long long>& a) {
    unordered_set<long long> s(a.begin(), a.end());
    long long mex = 0;
    while (s.count(mex)) {
        mex++;
    }
    return mex;
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    vll a(n);
    forn(i, n)
    {
        cin >> a[i];
    }

    ll low = 0, high = mexi(a)+1, ans = -1;
    while (low < high)
    {
        ll mid = (high+low) / 2;

        ll count = 0;  
        // unordered_set<ll> needed;
        // for (ll i = 0; i < mid; ++i){
        //     needed.insert(i);
        // }
        unordered_set<ll> current;
        bool check=false;
        ll c=0;
        for (ll i=0;i<n;i++) {
            ll num=a[i];
            if (num < mid) {
            current.insert(num);
                if (current.size()==mid) {
                    count++;
                    current.clear(); 
                }
                if(i==n-1){
                    check=true;
                }
            }
        }
        // if(!check){
        //     count=0;
        // }
        // cout<<"h"<<mid<<endl;
        // cout<<count<<endl;
        if(count>=k||mid==0){
            ans=mid;
        }
        if (count >= k||mid==0)
        {
            low=mid+1;
        }
        else
        {
            high=mid;
        }
    }

    cout << low-1 << ln;
}

int main()
{
    fast_cin();
    ll t;
    cin >> t;
    for (ll it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}