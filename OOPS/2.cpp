#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
using namespace std;

class NumberProcessor {
private:
    vector<int> fixedNumbers = {10, 20, 30, 40, 50}; 
    vector<int> userNumbers; 

public:
    void setUserNumbers() {
        cout << "Enter 20 numbers:\n";
        set<int> uniqueNumbers; 
        int num;
        for (int i = 0; i < 20; ++i) {
            cin >> num;
            uniqueNumbers.insert(num);
        }

        userNumbers.assign(uniqueNumbers.begin(), uniqueNumbers.end()); 
        cout << "\nUnique user numbers (duplicates removed): ";
        for (int n : userNumbers) {
            cout << n << " ";
        }
        cout << endl;
    }

    void printNonMatchingNumbers() {
        vector<int> nonMatching;
        for (int n : userNumbers) {
            if (find(fixedNumbers.begin(), fixedNumbers.end(), n) == fixedNumbers.end()) {
                nonMatching.push_back(n);
            }
        }

        cout << "\nNumbers in user list not matching fixed set: ";
        for (int n : nonMatching) {
            cout << n << " ";
        }
        cout << endl;
    }

    void prepareIndexAndFrequency() {
        map<int, pair<vector<int>, int>> indexFrequency; 

        for (int i = 0; i < userNumbers.size(); ++i) {
            int num = userNumbers[i];
            if (find(fixedNumbers.begin(), fixedNumbers.end(), num) != fixedNumbers.end()) {
                indexFrequency[num].first.push_back(i);   
                indexFrequency[num].second++;           
            }
        }

        cout << "\nIndex and frequency of fixed numbers in the user list:\n";
        for (int num : fixedNumbers) {
            cout << "Number: " << num << ", Indices: ";
            if (indexFrequency[num].first.empty()) {
                cout << "None";
            } else {
                for (int idx : indexFrequency[num].first) {
                    cout << idx << " ";
                }
            }
            cout << ", Frequency: " << indexFrequency[num].second << endl;
        }
    }
};

int main() {
    NumberProcessor processor;
    processor.setUserNumbers();               
    processor.printNonMatchingNumbers();       
    processor.prepareIndexAndFrequency();    
    return 0;
}
