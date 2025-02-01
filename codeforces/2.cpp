#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int c = 0;
        bool check = false;

        for (int i = 0; i < n; i++) {
            if (s[i] == '_' && c == 0) {
                s[i] = '(';
                check = true;
                c = 1;
            } else if (s[i] == ')') {
                check = false;
            } else if (s[i] == '(') {
                check = true;
            }

            if (s[i] == '_' && check == true) {
                s[i] = ')'; 
            } else if (s[i] == '_' && check == false) {
                s[i] = '('; 
                check = true;
            }
        }
       

        int i = 0;
        int j = 0;
        int sum = 0;
        while (i < n) {
            if (s[i] == '(') {
                j = i;
                int balance = 0;
                int k=0;
                while (j < n && (balance > 0||k==0)) {
                    if (s[j] == '(') {
                        balance++;
                    } else if (s[j] == ')') {
                        balance--;
                    }
                    j++;
                    k=1;
                }
                if (balance == 0) {
                    sum += (j - i-1);
                }
            }
            i++;
        }

        cout << sum << endl;
    }

    return 0;
}
