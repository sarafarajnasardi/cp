#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

class Timer{
    private:
        double start, end;

    public:
    void start(){
        start = high_resolution_clock::now();
    }

    void stop(){
        end = high_resolution_clock::now();
    }

    double time(){
        double time = duration_cast<microseconds>double(start-end)
    }
};

int main(){
    string timestamp="2025-04-08T10:22:18";
    replace(timestamp.begin(),timestamp.end(),'T',' ');

    tm t={

    };
    istringstream ss(timestamp);
    ss>>get_time(&t,"%Y-%m-%d %H:%M:%S");
    time_t seconds=mktime(&t);
    cout<<seconds<<endl;
}