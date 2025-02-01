
// Author : Sarafaraj Nasardi


#include <bits/stdc++.h>

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

#define forn(i,e) for(ll i = 0; i < e; i++)

#define all(x) (x).begin(), (x).end()


// Mathematical functions
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);} //__gcd 


ll lcm(ll a, ll b){return (a/gcd(a,b)*b);}

ll moduloMultiplication(ll a,ll b,ll mod){ll res = 0;a %= mod;while (b){if (b & 1)res = (res + a) % mod;b >>= 1;}return res;}

ll powermod( ll x, ll y, ll mod){ ll ans = 1;if( y == 0) return 1;while(y){   if(y%2) ans = (1ll*ans*x)%mod;    x = (1ll*x*x)%mod;    y /= 2;}return ans;}

//ll binexp(ll a , ll b , ll m){ll result = 1;while(b > 0){if( b& 1){result = ((result%m )( a%m))%m ;}a = ((a%m)(a%m))%m ;b >>= 1;}return result;}

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


void solve(){
    ll n;
    cin>>n;
    mll mp;
    forn(i,n){
        ll a,b;
        cin>>a>>b;
        mp[a]++;
        mp[b+1]--;
    }
    ll ans = 0;
    for(auto it:mp){
        ans+=it.second;
        if(ans>2){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}
int main() {
   solve();
}
