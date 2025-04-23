#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream file("Marks.csv");  // input file
    fstream outfile("FilteredMarks.txt",ios::out);  // output file

    if (!file.is_open()) {
        cout << "Error opening input file!" << endl;
        return 1;
    }

    string line;
    unordered_map<string, int> ans;

    while (getline(file, line)) {
        vector<string> c;
        string x = "";
        
        for (auto t : line) {
            if (t == ',') {
                c.push_back(x);
                x.clear();
            } else {
                x += t;
            }
        }
        c.push_back(x);

        if (c[0] == "Name") continue;

        try {
            throw "hello";
            ans[c[0]] = (stoi(c[1]) + stoi(c[2]) + stoi(c[3])) / 3;
        } catch (const exception& e) {
            cout << "Error parsing data for " << e << endl;
        }
    }

    for (auto x : ans) {
        if (x.second > 75)
            outfile << x.first << " " << x.second << endl;
    }

    file.close();
    outfile.close();
    return 0;
}
