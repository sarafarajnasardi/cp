
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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<vector<pll>> vvpll;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
typedef map<int, int> mii;
typedef map<ll,ll> mll;

const ll MOD = 998244353;
const double eps = 1e-12;

#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define yes cout << "YES\n" ;
#define no cout << "NO\n" ;
#define iv(v,n) vector<ll> v(n); forn(i,n) cin >> v[i] ;


// unique sort :
// sort(all(v));
// v.resize(unique(all(v)) - v.begin()) ;

// Mathematical functions
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);} //__gcd 


ll lcm(ll a, ll b){return (a/gcd(a,b)*b);}

ll moduloMultiplication(ll a,ll b,ll mod){ll res = 0;a %= mod;while (b){if (b & 1)res = (res + a) % mod;b >>= 1;}return res;}

ll powermod( ll x, ll y, ll mod){ ll ans = 1;if( y == 0) return 1;while(y){   if(y%2) ans = (1ll*ans*x)%mod;    x = (1ll*x*x)%mod;    y /= 2;}return ans;}

ll binexp(ll a , ll b , ll m){
   ll result = 1;
   while(b > 0){
      if(b & 1){
        result = ((result % m) * (a % m)) % m;
  }
     a = ((a % m) * (a % m)) % m;
b >>= 1;
}
return result;
}

vector<vector<long long>> matrixmultiply(const vector<vector<long long>>& matrix1, const vector<vector<long long>>& matrix2) {
    int rows = matrix1.size();
    int cols = matrix2[0].size();
    int common = matrix2.size();
    vector<vector<long long>> result(rows, vector<long long>(cols, 0));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            for (int k = 0; k < common; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}



//Factorial by vector
//vll fact;
//void factorials(ll mod, ll maxi){fact.resize(maxi + 1, 1); for(int i = 2; i<= maxi ; i++) fact[i] = (fact[i-1]*i)%mod ;}
//ll nCr(ll n, ll r, ll mod){ if(r > n) return 0; ll x = (fact[r]*fact[n-r])%mod ;ll ans = (fact[n] * (powermod(x,mod-2, mod)))%mod;return ans;}
bool isPrime(ll n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}

bool isPowerOfTwo(int n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}

bool isPerfectSquare(ll x){if (x >= 0) {ll sr = sqrt(x);return (sr * sr == x);}return false;}


int mexi(vector<int>& a, int l, int r) {
    vector<bool> present(4, false);
    for (int i = l; i <= r && i < a.size(); i++) {
        if (a[i] < 4) present[a[i]] = true;
    }
    for (int i = 0; i < 4; i++) {
        if (!present[i]) return i;
    }
    return 4;
}
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    vector<pair<int, int>> ans;

    while (a.size() > 3) {
        bool check = false;
        for (auto x : a) {
            if (x == 0) { 
                check = true; 
                break; 
            }
        }
        if (check) {
            int pos = -1;
            auto it = find(a.begin(), a.end(), 0);
            if (it!=a.end()) {
                pos = it - a.begin();
            }
            if (pos == 0) {
                int m = mexi(a, 0, 1);
                ans.push_back({1, 2});
                vector<int> newArray;
                newArray.push_back(m);
                for (int i = 2; i < (int)a.size(); i++) {
                    newArray.push_back(a[i]);
                }
                a = newArray;
            } else {
                int m = mexi(a, pos - 1, pos);
                ans.push_back({pos, pos + 1});
                vector<int> newArray;
                for (int i = 0; i < pos - 1; i++) {
                    newArray.push_back(a[i]);
                }
                newArray.push_back(m);
                for (int i = pos + 1; i < (int)a.size(); i++) {
                    newArray.push_back(a[i]);
                }
                a = newArray;
            }
        } else {
            int m = mexi(a, 0, a.size() - 1);
            ans.push_back({1, (int)a.size()});
            vector<int> newArray;
            newArray.push_back(m);
            a = newArray;
            break;
        }
        if (a.size() == 3) {
            int p = mexi(a, 0, 1);
            if (p != 0 && a[2] != 0) {
                ans.push_back({1, 2});
                vector<int> newArray;
                newArray.push_back(p);
                newArray.push_back(a[2]);
                a = newArray;
            } else {
                int q = mexi(a, 1, 2);
                if (a[0] != 0 && q != 0) {
                    ans.push_back({2, 3});
                    vector<int> newArray;
                    newArray.push_back(a[0]);
                    newArray.push_back(q);
                    a = newArray;
                } else {
                    ans.push_back({1, 3});
                    int m = mexi(a, 0, 2);
                    vector<int> newArray;
                    newArray.push_back(m);
                    a = newArray;
                }
            }
        }

        if (a.size() == 2) {
            int m = mexi(a, 0, 1);
            ans.push_back({1, 2});
            vector<int> newArray;
            newArray.push_back(m);
            a = newArray;
        }
    }

    cout << ans.size() << "\n";
    for (auto &x : ans) {
        cout << x.first << " " << x.second << "\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
} 