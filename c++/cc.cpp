/*
░██████╗░█████╗░██████╗░░█████╗░███████╗░█████╗░██████╗░░█████╗░░░░░░██╗
██╔════╝██╔══██╗██╔══██╗██╔══██╗██╔════╝██╔══██╗██╔══██╗██╔══██╗░░░░░██║
╚█████╗░███████║██████╔╝███████║█████╗░░███████║██████╔╝███████║░░░░░██║
░╚═══██╗██╔══██║██╔══██╗██╔══██║██╔══╝░░██╔══██║██╔══██╗██╔══██║██╗░░██║
██████╔╝██║░░██║██║░░██║██║░░██║██║░░░░░██║░░██║██║░░██║██║░░██║╚█████╔╝
╚═════╝░╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░░░░╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝░╚════╝░

███╗░░██╗░█████╗░░██████╗░█████╗░██████╗░██████╗░██╗
████╗░██║██╔══██╗██╔════╝██╔══██╗██╔══██╗██╔══██╗██║
██╔██╗██║███████║╚█████╗░███████║██████╔╝██║░░██║██║
██║╚████║██╔══██║░╚═══██╗██╔══██║██╔══██╗██║░░██║██║
██║░╚███║██║░░██║██████╔╝██║░░██║██║░░██║██████╔╝██║
╚═╝░░╚══╝╚═╝░░╚═╝╚═════╝░╚═╝░░╚═╝╚═╝░░╚═╝╚═════╝░╚═╝

*/
#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pll pair<ll, ll>
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve2()
{
    int n;
    cin >> n;
    vector<ll> arr;
    arr.push_back(1);
    for (int i = 2; i < n; i++)
    {
        if (gcd(n, i) == 1)
        {
            arr.push_back(i);
        }
    }
    cout << arr.size() << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
}
void solve3()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pll> p(n);
        ll maxi = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> p[i].ff >> p[i].ss;
            maxi = max(maxi, p[i].ss); // Find maximum `ss`
        }

        ll strt = 0, end = maxi, ans = -1;

        // Binary search
        while (strt <= end)
        {
            ll mid = strt + (end - strt) / 2;
            ll sum = 0;
            bool check = true;

            for (int i = 0; i < n; i++)
            {
                if (sum + mid < p[i].ff)
                {
                    check = false;
                    break;
                }
                if (sum - mid > p[i].ss)
                {
                    check = false;
                    break;
                }
                if (p[i + 1].ff >= p[i].ss)
                {
                    if (sum + mid >= p[i].ss)
                    {
                        sum = p[i].ss;
                    }
                }
                else if (p[i + 1].ss <= p[i].ff)
                {
                    if (sum - mid <= p[i].ff)
                    {
                        sum = p[i].ff;
                    }
                }
                else if (p[i + 1].ss <= p[i].ss && p[i + 1].ff >= p[i].ff)
                {
                    if (sum - mid <= p[i].ff && abs(p[i + 1].ff - p[i].ff) <= abs(p[i + 1].ss - p[i].ss))
                    {
                        sum = p[i].ff;
                    }
                }
            }

            if (check)
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                strt = mid + 1;
            }
        }

        cout << ans << endl;
    }
}
void solve4()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k, x;
        cin >> n >> k >> x;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        vector<ll> pref(n);
        pref[0] = arr[0];
        for (ll i = 1; i < n; i++)
        {
            pref[i] = pref[i - 1] + arr[i];
        }
        ll ans = LLONG_MIN;
        for (ll j = 0; j <= k; j++)
        {
            ll sum = 0;
            ll c = x;
            ll l = -1;
            ll strt = n - 1 - j;
            // for (; i >= 0; i--) {
            //     sum += l * arr[i];
            //     c--;
            //     if (c == 0) {
            //         break;
            //     }
            // }
            if (strt < 0)
            {
                ans = max(ans, 0LL);
                continue;
            }
            ll end = strt - c;
            if (end < 0)
            {
                sum = -1 * pref[strt];
            }
            else
            {
                sum = -1 * (pref[strt] - pref[end]);
            }
            if ((end + 1) >= 1)
            {
                sum += pref[end];
            }
            ans = max(ans, sum);
        }

        cout << ans << "\n";
    }
}
// const long long MOD = 1e9 + 7;

// long long modExpo(long long n, long long m) {
//     long long result = 1;
//     n = n % MOD;  // Ensure n is within mod
//     while (m > 0) {
//         if (m % 2 == 1) {  // If m is odd, multiply n with result
//             result = (result * n) % MOD;
//         }
//         n = (n * n) % MOD;  // Square n
//         m /= 2;  // Divide m by 2
//     }
//     return result;
// }
long long minswaps(vector<ll> arr, ll n)
{
    ll ans = 0;
    vector<long long> mp(n + 1);
    for (long long i = 0; i < n; i++)
    {
        mp[arr[i]] = i;
    }
    for (ll i = 0; i < n; i++)
    {
        if (arr[i] != i + 1)
        {
            swap(arr[i], arr[mp[i + 1]]);
            mp[arr[mp[i + 1]]] = mp[i + 1];
            mp[i + 1] = i;
            ans++;
        }
    }
    return ans;
}

long long minswaps1(vector<ll> arr, ll n)
{
    ll ans = 0;
    vector<long long> mp(n + 1);
    for (long long i = 0; i < n; i++)
    {
        mp[arr[i]] = i;
    }
    for (ll i = 0; i < n; i++)
    {
        if (arr[arr[i] - 1] != i + 1)
        {
            swap(arr[arr[i] - 1], arr[mp[i + 1]]);
            mp[arr[mp[i + 1]]] = mp[i + 1];
            mp[i + 1] = i;
            ans++;
        }
    }
    return ans;
}

void solve5()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        ll ans1 = minswaps(arr, n);
        ll ans2 = minswaps1(arr, n);
        cout << min(ans1, ans2) << "\n";
    }
}
void solve6()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, f, a, b;
        cin >> n >> f >> a >> b;
        vector<ll> arr(n);
        for (auto &i : arr)
            cin >> i;
        vector<ll> sum(n);
        sum[0] = min(arr[0] * a, b);
        ll s = 0;
        for (int i = 1; i < n; i++)
        {
            s = abs(arr[i] - arr[i - 1]) * a;
            sum[i] = min(s, b);
        }
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += sum[i];
        }

        if (ans < f)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
void solve7()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> arr(n);
        for (auto &i : arr)
            cin >> i;

        vector<ll> brr(k);
        for (auto &i : brr)
            cin >> i;

        sort(arr.begin(), arr.end());
        sort(brr.begin(), brr.end(), greater<ll>());

        ll sum = 0;
        ll i = 0, j = n - 1;
        ll i1 = 0, j1 = k - 1;
        ll c = 0;
        while (c != n)
        {
            if (i == j)
            {
                sum += max(llabs(arr[i] - brr[i1]), llabs(arr[j] - brr[j1]));
                break;
            }
            ll x = llabs(arr[i] - brr[i1]);
            ll y = llabs(arr[j] - brr[j1]);
            if (x > y)
            {
                sum += x;
                i++;
                i1++;
            }
            else
            {
                sum += y;
                j--;
                j1--;
            }
            c++;
        }
        cout << sum << endl;
    }
}

void solve8()
{
    int t;
    cin >> t;
    while (t--)
    {
        int h, w, x, y, x1, y1;
        cin >> h >> w >> x >> y >> x1 >> y1;

        vector<vector<char>> grid(h, vector<char>(w, '.'));
        grid[x - 1][y - 1] = 'A';
        grid[x1 - 1][y1 - 1] = 'B';
        if (x1 < x)
        {
            cout << "Draw" << endl;
            continue;
        }
        int m = x1 - x;
        bool right = false;
        bool left = false;
        if (m % 2 == 0)
        {
            if (y >= y1)
            {
                right = true;
            }
            else
            {
                left = true;
            }
        }
        else
        {
            if (y1 >= y)
            {
                left = true;
            }
            else
            {
                right = true;
            }
        }
        queue<tuple<int, int, char>> q;
        q.push({x - 1, y - 1, 'A'});
        q.push({x1 - 1, y1 - 1, 'B'});

        vector<pair<int, int>> directionsA = {{1, 0}, {1, 1}, {1, -1}};
        vector<pair<int, int>> directionsB = {{-1, 0}, {-1, 1}, {-1, -1}};

        int check = -1;

        while (!q.empty())
        {
            auto it = q.front();
            int r = get<0>(it);
            int c = get<1>(it);
            char b = get<2>(it);
            if ((b == 'A' && r == h - 1) || (b == 'B' && r == 0))
            {
                check = -1;
                break;
            }
            q.pop();

            if (b == 'A')
            {
                for (auto x : directionsA)
                {
                    int dr = x.ff;
                    int dc = x.ss;
                    int nr = r + dr, nc = c + dc;
                    if (nr >= 0 && nr < h && nc >= 0 && nc < w && m % 2 != 0)
                    {
                        if (right)
                        {
                            if (dc = 1)
                            {
                                continue;
                            }
                        }
                        if (left)
                        {
                            if (dc = -1)
                            {
                                continue;
                            }
                        }
                        if (grid[nr][nc] == 'B')
                        {
                            check = 1;
                            break;
                        }
                        if (grid[nr][nc] == '.')
                        {
                            grid[nr][nc] = 'A';
                            q.push({nr, nc, 'A'});
                        }
                    }
                    else if (nr >= 0 && nr < h && nc >= 0 && nc < w && m % 2 == 0)
                    {
                        if (nc != w - 1 && nc != 0 && dc == 0)
                        {
                            continue;
                        }
                        if (right)
                        {
                            if (dc = -1)
                            {
                                continue;
                            }
                        }
                        if (left)
                        {
                            if (dc = 1)
                            {
                                continue;
                            }
                        }
                        if (grid[nr][nc] == 'B')
                        {
                            check = 1;
                            break;
                        }
                        if (grid[nr][nc] == '.')
                        {
                            grid[nr][nc] = 'A';
                            q.push({nr, nc, 'A'});
                        }
                    }
                }
            }
            else
            {
                for (auto x : directionsB)
                {
                    int dr = x.ff;
                    int dc = x.ss;
                    int nr = r + dr, nc = c + dc;

                    if (nr >= 0 && nr < h && nc >= 0 && nc < w && m % 2 != 0)
                    {
                        if (nc != w - 1 && nc != 0 && dc == 0)
                        {
                            continue;
                        }
                        if (right)
                        {
                            if (dc = 1)
                            {
                                continue;
                            }
                        }
                        if (left)
                        {
                            if (dc = -1)
                            {
                                continue;
                            }
                        }
                        if (grid[nr][nc] == 'A')
                        {
                            check = 0;
                            break;
                        }
                        if (grid[nr][nc] == '.')
                        {
                            grid[nr][nc] = 'B';
                            q.push({nr, nc, 'B'});
                        }
                    }
                    else if (nr >= 0 && nr < h && nc >= 0 && nc < w && m % 2 == 0)
                    {
                        if (right)
                        {
                            if (dc = -1)
                            {
                                continue;
                            }
                        }
                        if (left)
                        {
                            if (dc = 1)
                            {
                                continue;
                            }
                        }
                        if (grid[nr][nc] == 'A')
                        {
                            check = 0;
                            break;
                        }
                        if (grid[nr][nc] == '.')
                        {
                            grid[nr][nc] = 'B';
                            q.push({nr, nc, 'B'});
                        }
                    }
                }
            }
            if (check != -1)
                break;
        }

        if (check == 1)
        {
            cout << "Alice" << endl;
        }
        else if (check == 0)
        {
            cout << "Bob" << endl;
        }
        else
        {
            cout << "Draw" << endl;
        }
    }
}
void solve9()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        set<ll> s;
        s.insert(0);
        ll pref = 0;
        ll c = 0;
        for (ll i = 0; i < n; i++)
        {
            pref += arr[i];
            if (s.count(pref) > 0)
            {
                c++;
                s.clear();
            }
            s.insert(pref);
        }
        cout << c << "\n";
    }
}

void solve10()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            int count = 1;
            while (i < n && s[i] != s[i + 1])
            {
                if (i == n - 1)
                {
                    count--;
                }
                i++;
                count++;
            }
            maxi = max(maxi, count);
        }
        cout << maxi << endl;
    }
}

void solve11()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        // priority_queue<tuple<int, int, int>> arr;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> arr;

        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            int sum = a + b;
            arr.push({sum, a, b});
        }

        vector<int> ans;
        while (!arr.empty())
        {
            auto x = arr.top();
            arr.pop();
            ans.push_back(get<1>(x));
            ans.push_back(get<2>(x));
        }

        for (const auto &x : ans)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}
void solve12()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        ll maxi = arr[n - k];
        ll sum = 0;
        for (int i = n - k; i < n; i++)
        {
            sum += (arr[i] - maxi);
        }
        cout << sum + maxi << endl;
    }
}
void solve13()
{
    ll n, x, y;
    cin >> n >> x >> y;
    vector<vector<int>> grid(n * n, vector<int>(n * n));
    for (int i = 0; i < n * n; i++)
    {
        for (int j = 0; j < n * n; j++)
        {
            cin >> grid[i][j];
        }
    }
    ll x1 = x - x % n;
    if (x % n == 0)
    {
        x1 = x - n;
    }
    ll y1 = y - y % n;
    if (y % n == 0)
    {
        y1 = y - n;
    }
    ll sum = 0;
    for (int i = x1; i < x1 + n; i++)
    {
        for (int j = y1; j < y1 + n; j++)
        {
            sum += grid[i][j];
        }
    }
    cout << sum << endl;
}
void solve14()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> p0, p1;

        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            if (b == 0)
            {
                p0.push_back({a, b});
            }
            else
            {
                p1.push_back({a, b});
            }
        }

        sort(p0.begin(), p0.end());
        sort(p1.begin(), p1.end());

        ll sum = 0;
        unordered_set<int> p1_values;
        for (const auto &p : p1)
        {
            p1_values.insert(p.first);
        }

        for (auto x : p0)
        {
            int current = x.first;
            if (p1_values.count(current))
            {
                sum += (n - 2);
            }
            if (p1_values.count(current - 1) && p1_values.count(current + 1))
            {
                sum++;
            }
        }

        unordered_set<int> p0_values;
        for (const auto &p : p0)
        {
            p0_values.insert(p.first);
        }

        for (auto x : p1)
        {
            int current = x.first;
            if (p0_values.count(current - 1) && p0_values.count(current + 1))
            {
                sum++;
            }
        }

        cout << sum << endl;
    }
}
void solve15()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll strt = 1;
        ll end = n;
        ll sum = LLONG_MAX;
        ll ind = -1;

        while (strt <= end)
        {
            ll mid = strt + (end - strt) / 2;
            ll x = (mid) * (2 * k + (mid - 1));
            ll y = (n * k + (n * (n - 1)) / 2);
            ll ans = abs(x - y);

            if (sum > ans)
            {
                sum = ans;
                ind = mid;
            }

            if (x == y)
            {
                break;
            }
            if (x < y)
            {
                strt = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        cout << sum << endl;
    }
}
void rotate_vector(vector<ll> &vec, int k)
{
    int n = vec.size();
    k = k % n; // Handle cases where k > n
    if (k < 0)
    {
        k += n; // Handle negative rotations
    }

    // Rotate left in three steps
    reverse(vec.begin(), vec.begin() + k);
    reverse(vec.begin() + k, vec.end());
    reverse(vec.begin(), vec.end());
}
void solve16()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, q;
        cin >> n >> q;
        vector<ll> arr;
        ll sum = 0;
        for (ll i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            arr.push_back(a);
            sum += arr[i];
        }
        vector<ll> pref(n, 0);
        pref[0] = arr[0];
        for (ll i = 1; i < n; i++)
        {
            pref[i] = pref[i - 1] + arr[i];
        }
        while (q--)
        {
            ll l, r;
            cin >> l >> r;
            l--;
            r--;
            ll l1 = l / n;
            ll r1 = r / n;
            l = l % n;
            r = r % n;
            ll ans = sum * l1;
            ll ans1 = sum * r1;
            // for(ll i=l1;i<(l+l1);i++){
            //     ans+=arr[i%n];
            // }
            // for(ll i=r1;i<=r+r1;i++){
            //     ans1+=arr[i%n];
            // }
            ll x1 = 0;
            if ((l1 + l) == n)
            {
                x1 = (pref[n - 1] - pref[l1 % n] + arr[l1 % n]);
            }
            else if ((l1 + l) > n)
            {
                if ((l + l1) % n > 0)
                    x1 = pref[n - 1] - pref[l1 % n] + arr[l1 % n] + pref[(l1 + l) % n - 1];
            }
            else
            {
                if ((l + l1) % n > 0)
                    x1 = (pref[(l + l1) % n - 1] - pref[l1 % n] + arr[l1 % n]);
            }
            ll y1 = 0;
            if ((r1 + r) >= n)
            {
                y1 = pref[n - 1] - pref[r1 % n] + arr[r1 % n] + pref[(r1 + r) % n];
            }
            else
            {
                y1 = (pref[(r + r1) % n] - pref[r1 % n] + arr[r1 % n]);
            }
            ans += x1;
            ans1 += y1;

            cout << ans1 - ans << endl;
        }
    }
}
bool isPrime(int n)
{
    if (n <= 1)
    {
        return false; // Numbers less than or equal to 1 are not prime
    }
    for (int i = 2; i <= std::sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false; // If n is divisible by any number other than 1 and itself, it's not prime
        }
    }
    return true; // If no divisors are found, n is prime
}
int rec(int i, int n, int k)
{
    if (i == n)
    {
        return 1;
    }
    if (i > n)
    {
        return 0;
    }
    int one = 0;
    int two = 0;
    one = rec(i + 1, n, k);
    if (isPrime(i))
    {
        two = rec(i + k, n, k);
    }

    return one + two;
}
void solve17()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        cout << rec(1, n, k) << endl;
    }
}
void solve18()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr.begin(), arr.end());
        vector<int> mp(n);
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < n)
                mp[arr[i]]++;
        }
        int check = 0;
        int maxelement = arr[n - 1];
        for (int i = 0; i <= maxelement; i++)
        {
            if (mp[i] == 0)
            {
                cout << i << endl;
                check++;
                break;
            }
            else if (mp[i] > 1)
            {
                if (i + x < n)
                {
                    mp[i + x] += (mp[i] - 1);
                    if ((i + x) > maxelement)
                    {
                        maxelement = i + x;
                    }
                    mp[i] = 1;
                }
            }
        }
        if (check == 0)
        {
            cout << maxelement + 1 << endl;
        }
    }
}
vector<int> constructArray(int n)
{
    vector<int> array;
    array.push_back(1); // Initial element A1 = 1

    for (int i = 2; i <= n; i++)
    {
        array.push_back(i - 1); // Append i-1 for elements from A2 to An
    }

    return array;
}
void solve19()
{
    string t;
    cin >> t;
    int n = t.length();
    // if(n%2==0){
    //     cout<<"NO"<<endl;
    //     return;
    //     // }
    //     set<string>s;
    //    for (int i = 1; i <= n / 2; i++) {
    //         int l = n - i;
    //         if(l-1>=i){
    //         string x=t.substr(i);
    //         s.insert(x);
    //         }
    //         // Check if the length `l` is valid and if the substrings match.
    //         // if (l - 1 >= i && t.compare(0, l, t, i, l) == 0) {
    //         //     cout << "YES" << endl;
    //         //     cout << t.substr(0, l) << endl;
    //         //     return;
    //         // }
    //         // int j=0;
    // int k=i;
    // int c=0;
    // while(l--){
    //     if(t[j]!=t[k]){
    //         c++;
    //     }
    //     j++;
    //     k++;
    // }
    // if(c==0){
    //     cout<<"YES"<<endl;
    //     cout<<t.substr(0, l)<<endl;
    //     return;
    // }
    //}
    // set<string>s1;
    // for(int i=n-1;i>=(n-n/2);i--){
    //     string x=t.substr(0,i);
    //     s1.insert(x);
    // }
    // vector<string> ans;

    // // Find the intersection.
    // set_intersection(s.begin(), s.end(),
    //                  s1.begin(), s1.end(),
    //                  back_inserter(ans));
    // //acacacaca
    // if(ans.size()){
    //     cout<<"YES"<<endl;
    //     cout<<ans[0]<<endl;
    //     return;
    // }

    // int l=n/2;
    // string x=t.substr(0,l+1);
    // string y=t.substr(l,l+1);
    // if(x==y){
    //     cout<<"YES"<<endl;
    //     cout<<x<<endl;
    //     return;
    // // }
    // cout<<"NO"<<endl;
    int i = 0;
    int j = 1;
    string ans1 = "";
    string ans2 = "";
    while (i <= j && j < n)
    {
        if (t[i] == t[j] && t[n - i - 1] == t[n - j - 1])
        {
            ans1 += t[i];
            ans2 += t[n - i - 1];
            i++;
            j++;
        }
        else
        {
            ans1.clear();
            ans2.clear();
            i = 0;
            j++;
        }
    }

    if (i > 0)
    {
        cout << "YES" << endl;
        reverse(ans2.begin(), ans2.end());
        cout << ans1 + ans2 << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
void solve20()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b, c;
        cin >> a >> b >> c;
        map<char, int> mp;
        for (int i = 0; i < c.length(); i++)
            mp[c[i]]++;

        int al = a.length();
        int bl = b.length();
        int n = c.length();
        int i = 0;
        int j = 0;
        int k = 0;
        int cn = 0;
        while (k < n)
        {
            if (i < al && c[k] == a[i])
            {
                mp[a[i]]--;
                i++;
                k++;
            }
            else if (j < bl && c[k] == b[j])
            {
                mp[b[j]]--;
                j++;
                k++;
            }
            else
            {
                cn++;
                if (i < al && mp[a[i]] == 0)
                {
                    i++;
                }
                else if (j < al && mp[a[j]] == 0)
                {
                    j++;
                }
                else
                {
                    k++;
                }
            }
        }
        cout << cn << endl;
    }
}

string getBinaryString(long long number)
{
    if (number == 0)
    {
        return "0"; // Special case for 0
    }

    string binaryStr = "";
    while (number > 0)
    {
        binaryStr += (number % 2 == 0) ? '0' : '1';
        number /= 2;
    }

    // The binary string is in reverse order, so reverse it before returning
    reverse(binaryStr.begin(), binaryStr.end());
    return binaryStr;
}
void solve21()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        string s = getBinaryString(a);
        string t = getBinaryString(b);
        int zero = 0;
        if (t.length() >= s.length())
        {

            for (int i = 0; i < s.length(); i++)
            {
                if (s[i] == '0')
                {
                    zero++;
                }
            }
            ll ans = 1 << zero;
            // cout<<ans<<endl;

            ans--;

            int one = 0;
            for (int i = 0; i < s.length(); i++)
            {
                if (s[i] == '1')
                {
                    one++;
                }
            }
            ans += (1 << one);
            int i = 0;
            while (s[i] == '1')
            {
                ans -= 2;
                i++;
            }
            ans--;
            cout << ans << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
}

void solve22()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int index = -1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != -1 && arr[i] != 1)
            {
                index = i;
                break;
            }
        }
        ll mini = LLONG_MAX;
        ll maxi = LLONG_MIN;
        ll sum = 0;
        mini = min(mini, sum);
        maxi = max(maxi, sum);
        for (int i = 0; i < index; i++)
        {
            sum += arr[i];
            mini = min(mini, sum);
            maxi = max(maxi, sum);
        }
        set<ll> s;
        for (ll i = mini; i < maxi; i++)
        {
            s.insert(i);
        }
        sum = 0;
        mini = LLONG_MAX;
        maxi = LLONG_MIN;
        mini = min(mini, sum);
        maxi = max(maxi, sum);
        for (ll i = index + 1; i < n; i++)
        {
            sum += arr[i];
            mini = min(mini, sum);
            maxi = max(maxi, sum);
        }
        for (ll i = mini; i < maxi; i++)
        {
            s.insert(i);
        }
        if (index != n)
        {
        }
    }
}

void solve23()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll l, r;
        cin >> l >> r;

        string s = getBinaryString(r);
        string t = "", k = getBinaryString(l);

        while (k.length() < s.length())
        {
            k = "0" + k;
        }

        int c = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == k[i] && c == 0)
            {
                t += s[i];
                continue;
            }
            if (s[i] != t[i] && c == 0)
            {
                t += k[i];
                c = 1;
                continue;
            }
            t += (s[i] == '1') ? '0' : '1';
        }

        string h = t;
        ll num = bitset<64>(s).to_ullong();
        ll num2 = bitset<64>(t).to_ullong();
        cout << "hello" + t << endl;
        cout << "hello" + k << endl;
        cout << "hello" + s << endl;
        int i = 0;
        while (i < t.length() && num2 < l)
        {
            if (k[i] == '1' && t[i] == '0')
            {
                t[i] = '1';
            }
            num2 = bitset<64>(t).to_ullong();
            i++;
        }
        ll num1 = l;
        if (num2 + 1 < r)
        {
            num1 = num2 + 1;
        }
        else if (num2 - 1 >= l)
        {
            num1 = num2 - 1;
        }

        cout << num << " " << num1 << " " << num2 << endl;

        ll ans = (num ^ num1) + (num ^ num2) + (num2 ^ num1);
        cout << ans << endl;
    }
}
#include <chrono>

using namespace std;
using namespace chrono;

class DisjointSet
{
    vector<int> rank, parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

void solve24()
{
    ll t;
    cin >> t;
    while (t--)
    {
        int n, m1, m2;
        cin >> n >> m1 >> m2;
        set<pair<int, int>> a1;
        set<pair<int, int>> b1;
        DisjointSet ds(n);
        for (int i = 0; i < m1; i++)
        {
            int a, b;
            cin >> a >> b;
            a1.insert({a, b});
        }

        for (int i = 0; i < m2; i++)
        {
            int a, b;
            cin >> a >> b;
            b1.insert({a, b});
        }
        DisjointSet ds1(n);

        for (auto x : b1)
        {
            ds1.unionByRank(x.first, x.second);
        }
        int count = 0;
        for (auto x : a1)
        {
            if (ds1.findUPar(x.first) != ds1.findUPar(x.second))
            {
                count++;
            }
            else
            {
                ds.unionByRank(x.first, x.second);
            }
        }
        cout << count << endl;
        for (auto x : b1)
        {
            if (ds.findUPar(x.first) != ds.findUPar(x.second))
            {
                count++;
            }
        }
        cout << count << endl;
    }
}
/*
20 19 6
5 7
9 2
6 8
4 1
6 3
14 3
8 10
4 11
1 5
3 1
11 17
15 11
7 18
2 13
2 1
12 7
19 7
20 7
16 4

19 6
15 7
6 10
1 20
3 10
12 15
*/
using ull = unsigned long long;
// int gcd(int a, int b) {
//     while (b != 0) {
//         int temp = b;
//         b = a % b;
//         a = temp;
//     }
//     return a;
// }

bool areCoprime(int a, int b)
{
    return gcd(a, b) == 1;
}
void solve25()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> adj[n + 1];

        for (ll i = 0; i < n - 1; i++)
        {
            ll a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<pair<ll, ll>> ans;
        for (ll i = 1; i <= n; i++)
        {
            ans.push_back({i, adj[i].size()});
        }
        sort(ans.begin(), ans.end(), [](const pair<ll, ll> &a, const pair<ll, ll> &b)
             { return a.second > b.second; });
        bool check = false;
        for (auto x : adj[ans[0].first])
        {
            for (auto &l : ans)
            {
                if (x == l.first)
                {
                    l.second = l.second - 1;
                }
            }
        }
        sort(ans.begin(), ans.end(), [](const pair<ll, ll> &a, const pair<ll, ll> &b)
             { return a.second > b.second; });
        // ll l=adj[ans[1].second].size();
        // ll i=1;
        // while(check&&adj[ans[i].second].size()==l){
        //     i++;
        //     if(i==ans.size()) break;
        //     bool check1=true;
        //     for(auto x:adj[ans[i].second]){
        //         if(x==ans[0].second){
        //             check=true;
        //             check1=false;
        //             break;
        //         }
        //     }
        //     if(check1){
        //         check=false;
        //         break;
        //     }
        // }
        ll ans1 = ans[0].second + ans[1].second;
        ans1--;
        cout << ans1 << endl;
    }
}

void solve26()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n,m;
        cin >> n >> m;
        vector<ll>a(n);
        unordered_map<ll, ll>mp1;
        for (ll i = 0; i < n; i++){
            cin >> a[i];
            mp1[a[i]]++;
        }
        vector<ll>b(m);
        multiset<ll>mp;
        for (ll i = 0; i < m; i++){
            cin>>b[i];
            if(mp1[b[i]]){
                mp.insert(b[i]);
                mp1[b[i]]--;
            }
        }
        multiset<ll>mp2;
        for(auto x:mp){
            while(mp1[x]){
                mp2.insert(x);
                mp1[x]--;
            }
        }
        
    }
}
void solve28(){
    ll n;
    cin>>n;
    vector<pair<ll,ll>>a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(a.begin(),a.end());
    map<ll,ll>mp;
    vector<ll>ans;
    for(ll i=0;i<n;i++){
        mp[a[i].first]++;
        mp[a[i].second+1]--;
        ans.push_back(mp[a[i].second+1]);
        ans.push_back(mp[a[i].second]);
        ans.push_back(mp[a[i].first]);
    }
    sort(ans.begin(),ans.end());
    vector<ll>pref(ans.size(),0);
    pref[0]=ans[0];
    for(ll i=1;i<ans.size();i++){
        pref[i]=pref[i-1]+ans[i];
    }
    map<ll,ll>res;
    for(ll i=0;i<ans.size();i++){
        res[ans[i]]=pref[i];
    }
    bool check = true;
    for(ll i=0;i<n;i++){
        if(res[a[i].second]>2||pref[a[i].first]>2){
            check=false;
            break;
        }
    }
    if(check){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }

}

int main()
{

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve28();
}