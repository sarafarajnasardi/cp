#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max();

int main() {
    vector<string>ans={"xbc","pcxbcf","xb","cxbc","pcxbc"};
    sort(ans.begin(), ans.end(), [](const string &a, const string &b) {
        return a.length() < b.length();
    });
    for(auto x:ans){
        cout<<x<<endl;
    }
}
