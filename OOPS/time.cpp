#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int main(){

    auto start = high_resolution_clock::now();
    sort(s.begin(), s.end());
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(end - start);

    cout << duration.count() << endl;

    return 0;
}
