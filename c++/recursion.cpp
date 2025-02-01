#include<iostream>
#include<limits.h>
#include<vector>
#include<algorithm>
#include<string.h>
#include<map>
using namespace std;

// Function to print numbers from n down to 1
void printcounting(int n){
    // Base case
    if (n == 0) {
        return;
    }
    // Processing
    cout << n << endl;
    // Recursive call
    printcounting(n - 1);
}

// Function to calculate the nth Fibonacci number
int fib(int n) {
    // Base cases
    if (n == 1) {
        return 1;
    } else if (n == 0) {
        return 0;
    }
    // Recursive relation
    int fibn = fib(n - 1) + fib(n - 2);
    return fibn;
}

// Function to find the number of ways to reach the nth stair
int stairs(int n) {
    // Base cases
    if (n == 0 || n == 1) {
        return 1;
    }
    // Recursive relation
    int ans = stairs(n - 1) + stairs(n - 2);
    return ans;
}

// Function to print elements of an array using recursion
void print(int arr[], int n, int i) {
    if (i >= n) {
        return;
    }
    cout << arr[i] << endl;
    print(arr, n, i + 1);
    // To print in reverse order, swap the two lines above
}

// Function to find the maximum value in an array using recursion
void maxi(int arr[], int n, int i, int& l) {
    if (i >= n) {
        return;
    }
    if (arr[i] > l) {
        l = arr[i];
    }
    maxi(arr, n, i + 1, l);
}

// Function to find the minimum value in an array using recursion
void minn(int arr[], int n, int i, int& l) {
    if (i >= n) {
        return;
    }
    if (arr[i] < l) {
        l = arr[i];
    }
    minn(arr, n, i + 1, l);
}

// Function to check if a character exists in a string using recursion
bool check(string str, int l, char k, int i) {
    if (i >= l) {
        return false;
    }
    if (str[i] == k) {
        return true;
    }
    return check(str, l, k, i + 1);
}

// Function to print digits of a number using recursion
void digits(int n) {
    if (n == 0) {
        return;
    }
    cout << n % 10 << endl;
    n = n / 10;
    digits(n);
}

// Function to check if an array is sorted using recursion
bool sorted(int arr[], int n, int i) {
    if (i + 1 >= n) {
        return true;
    }
    if (arr[i] > arr[i + 1]) {
        return false;
    }
    return sorted(arr, n, i + 1);
}

// Function to perform binary search using recursion
int binarysearch(vector<int> v, int n, int s, int e, int target) {
    if (s > e) {
        return -1;
    }
    int mid = (s + e) / 2;
    if (v[mid] == target) {
        return mid;
    }
    if (v[mid] > target) {
        return binarysearch(v, n, s, mid - 1, target);
    }
    if (v[mid] < target) {
        return binarysearch(v, n, mid + 1, e, target);
    }
}

// Function to find all subsequences of a string using recursion
void subse(string s, string ans, int i) {
    if (i >= s.length()) {
        cout << ans << " ";
        return;
    }
    // Include current character
    ans.push_back(s[i]);
    subse(s, ans, i + 1);
    // Exclude current character
    ans.pop_back();
    subse(s, ans, i + 1);
}

// Function to find the minimum number of coins needed to make a target amount using recursion
int minnum(vector<int> arr, int target) {
    if (target < 0) {
        return INT_MAX;
    }
    if (target == 0) {
        return 0;
    }
    int mini = INT_MAX;
    for (int i = 0; i < arr.size(); i++) {
        int ans = minnum(arr, target - arr[i]);
        if (ans != INT_MAX)
            mini = min(mini, ans + 1);
    }
    return mini;
}

// Alternative function to find the minimum number of coins needed to make a target amount using recursion
int min2(vector<int> arr, int target, int output) {
    if (target == output) {
        return 0;
    }
    if (output > target) {
        return INT_MAX;
    }
    int mini = INT_MAX;
    for (int i = 0; i < arr.size(); i++) {
        int ans = min2(arr, target, output + arr[i]);
        if (ans != INT_MAX)
            mini = min(mini, ans + 1);
    }
    return mini;
}

// Function to find the last occurrence of a character in a string using recursion
int findlast(string s, int i, char d) {
    if (i < 0) {
        return -1;
    }
    if (s[i] == d) {
        return i + 1;
    }
    return findlast(s, --i, d);
}

// Function to find the maximum number of segments a rod can be cut into using recursion
int rodseg(vector<int> arr, int target) {
    if (target == 0) {
        return 0;
    }
    if (target < 0) {
        return INT_MIN;
    }
    int maxi = INT_MIN;
    for (int i = 0; i < arr.size(); i++) {
        int ans = rodseg(arr, target - arr[i]);
        if (ans != INT_MIN) {
            maxi = max(maxi, ans + 1);
        }
    }
    return maxi;
}

// Function to find the maximum sum of non-adjacent elements in an array using recursion
void maxisum(vector<int> arr, int i, int ans, int &maxi) {
    if (i >= arr.size()) {
        maxi = max(ans, maxi);
        return;
    }
    // Exclude current element
    maxisum(arr, i + 1, ans, maxi);
    // Include current element
    maxisum(arr, i + 2, ans + arr[i], maxi);
}

// Function to reverse a string using recursion
void reversestr(string &s, int i) {
    if (i > s.length() / 2) {
        return;
    }
    swap(s[i], s[s.length() - i - 1]);
    reversestr(s, i + 1);
}

// Function to add two numbers represented as strings using recursion
string sum(string a, string b, int i, int j, int cary) {
    if (i < 0 && j < 0) {
        if (cary != 0) {
            return string(1, cary + '0');
        }
        return "";
    }
    int n1 = 0, n2 = 0;
    if (i >= 0) {
        n1 = a[i] - '0';
    }
    if (j >= 0) {
        n2 = b[j] - '0';
    }
    int m = cary + n1 + n2;
    if (m >= 10) {
        cary = m / 10;
    }
    string ans = "";
    ans.push_back(m % 10 + '0');
    ans += sum(a, b, i - 1, j - 1, cary);
    return ans;
}

// Function to check if a string is a palindrome using recursion
bool palindrome(string s, int i) {
    if (i > s.length() / 2) {
        return true;
    }
    if (s[i] != s[s.length() - i - 1]) {
        return false;
    }
    return palindrome(s, i + 1);
}

// Function to print all subarrays of an array using recursion
void printarray(vector<int> arr, int strt, int end) {
    if (strt >= end) {
        strt++;
        end = arr.size();
    }
    if (strt >= arr.size()) {
        return;
    }
    printarray(arr, strt, end - 1);
    for (int i = strt; i < end; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to find the maximum profit from buying and selling stocks using recursion
int maxpro(vector<int> arr, int strt, int end) {
    if (strt >= end) {
        strt++;
        end = arr.size();
    }
    if (strt >= arr.size()) {
        return 0;
    }
    int ans = max(arr[end] - arr[strt], maxpro(arr, strt, end - 1));
    return ans;
}

// Function to find the minimum cost for tickets using recursion
int mincos(vector<int> arr, int a, int b, int c, int i) {
    if (i >= arr.size()) {
        return 0;
    }
    // One-day pass
    int a1 = a + mincos(arr, a, b, c, i + 1);
    // Seven-day pass
    int maxday = arr[i] + 6;
    int j = i;
    while (j < arr.size() && arr[j] <= maxday) {
        j++;
    }
    int a2 = b + mincos(arr, a, b, c, j);
    // Thirty-day pass
    int max2day = arr[i] + 29;
    int k = i;
    while (k < arr.size() && arr[k] <= maxday) {
        k++;
    }
    int a3 = c + mincos(arr, a, b, c, k);
    return min(a1, min(a2, a3));
}

// Main function
int main() {
    // Code to test the functions

    // Example usage for printing numbers from n to 1
    // int n;
    // cin >> n;
    // printcounting(n);

    // Example usage for finding the nth Fibonacci number
    // int n;
    // cin >> n;
    // cout << fib(n) << endl;

    // Example usage for finding the number of ways to reach the nth stair
    // int n;
    // cin >> n;
    // cout << stairs(n) << endl;

    // Example usage for printing elements of an array
    // int arr[5] = {10, 20, 30, 40, 50};
    // int n = 5;
    // int i = 0;
    // print(arr, n, i);

    // Example usage for finding the maximum value in an array
    // int arr[5] = {10, 20, 30, 40, 50};
    // int n = 5;
    // int i = 0;
    // int max = 0;
    // maxi(arr, n, i, max);
    // cout << max;

    // Example usage for finding the minimum value in an array
    // int arr[5] = {10, 20, 30, 40, 50};
    // int n = 5;
    // int i = 0;
    // int mini = 100;
    // minn(arr, n, i, mini);
    // cout << mini;

    // Example usage for checking if a character exists in a string
    // string str = "lovebabbar";
    // int l = str.length();
    // char k = 'p';
    // int i = 0;
    // if (check(str, l, k, i)) {
    //     cout << "YES" << endl;
    // } else {
    //     cout << "NO" << endl;
    // }

    // Example usage for printing digits of a number
    // int n;
    // cin >> n;
    // digits(n);

    // Example usage for checking if an array is sorted
    // int arr[5] = {1, 2, 2, 3, 5};
    // int n = 5;
    // int i = 0;
    // if (sorted(arr, n, i)) {
    //     cout << "YES" << endl;
    // } else {
    //     cout << "NO" << endl;
    // }

    // Example usage for binary search
    // vector<int> v {10, 20, 40, 60, 70, 90, 9};
    // int target = 99;
    // int n = v.size();
    // int s = 0;
    // int e = n - 1;
    // int ans = binarysearch(v, n, s, e, target);
    // cout << ans;

    // Example usage for finding all subsequences of a string
    // string s = "abc";
    // string ans = "";
    // int i = 0;
    // subse(s, ans, i);

    // Example usage for finding the minimum number of coins needed to make a target amount
    // vector<int> arr {1, 2};
    // int target = 5;
    // int output = 0;
    // cout << min2(arr, target, output) << endl;

    // Example usage for finding the last occurrence of a character in a string
    // string s = "sarafaraj";
    // char d = 'a';
    // cout << findlast(s, s.length() - 1, d) << endl;

    // Example usage for cutting a rod into segments
    // int target = 7;
    // vector<int> arr {5, 2, 2};
    // cout << rodseg(arr, target) << endl;

    // Example usage for finding the maximum sum of non-adjacent elements in an array
    // vector<int> arr {2, 1, 4, 9};
    // int i = 0;
    // int ans = 0;
    // int maxi = INT_MIN;
    // maxisum(arr, i, ans, maxi);
    // cout << maxi << endl;

    // Example usage for reversing a string
    // string s = "sarafaraj";
    // int i = 0;
    // reversestr(s, i);
    // cout << s << endl;

    // Example usage for adding two numbers represented as strings
    // string a = "11";
    // string b = "123";
    // int cary = 0;
    // int i = a.length() - 1;
    // int j = b.length() - 1;
    // cout << sum(a, b, i, j, cary) << endl;

    // Example usage for checking if a string is a palindrome
    // string a = "mvbvm";
    // int i = 0;
    // if (palindrome(a, i)) {
    //     cout << "YES" << endl;
    // } else {
    //     cout << "NO" << endl;
    // }

    // Example usage for printing all subarrays of an array
    // vector<int> arr {1, 2, 3, 4, 5};
    // int strt = 0;
    // int end = 5;
    // printarray(arr, strt, end);

    // Example usage for finding the maximum profit from buying and selling stocks
    // vector<int> arr {7, 1, 5, 3, 6, 4};
    // int strt = 0;
    // int end = arr.size();
    // cout << maxpro(arr, strt, end) << endl;

    // Example usage for finding the minimum cost for tickets
    // vector<int> arr {1, 4, 6, 7, 8, 20};
    // int a = 2;
    // int b = 4;
    // int c = 25;
    // int i = 0;
    // cout << mincos(arr, a, b, c, i) << endl;

    // Example usage for finding the minimum number of perfect squares that sum to n
    int n = 12;
    // Implement the function perfecsq here

    return 0;
}
