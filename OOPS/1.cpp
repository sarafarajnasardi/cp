#include <bits/stdc++.h>
#define ll long long
const int M = 1e9 + 7;
using namespace std;

string defSub[] = {};
class Result
{
private:
    map<string, int> result;

public:
    void addSubject(const string &sub, const int &marks)
    {
        result[sub] = marks;
    }

    void editMarks(const string &sub, const int &edit)
    {
        if (result.find(sub) != result.end())
            result[sub] += edit;
        else
        {
            cout << "This subject is not present in this result" << endl;
        }
    }

    void grade()
    {
        cout << "Subject" << " : " << "Marks" << " " << "grade" << endl;
        for (auto &sub : result)
        {
            string grade;
            if (sub.second >= 90)
                grade = "EX";
            else if (sub.second >= 80)
                grade = "A";
            else if (sub.second >= 70)
                grade = "B";
            else if (sub.second >= 60)
                grade = "C";
            else if (sub.second >= 50)
                grade = "D";
            else
                grade = "F";
            cout << sub.first << " : " << sub.second << " : " << grade << endl;
        }
    }
    Result()
    {
        for (auto &subject : defSub)
        {
            result[subject] = 0;
        }
    };
};

int32_t main()
{
    Result r1;
    int n;
    cin >> n;
    while (n--)
    {
        string sub;
        int marks;
        cin >> sub >> marks;
        r1.addSubject(sub, marks);
    }
    r1.grade();
    return 0;
}