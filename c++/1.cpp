#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace chrono;


int main() {
    string s;
    getline(cin,s);
    set<char>st={'.','?','!'};
    int sent=0;
    int spac=0;
    map<string,int>mp;
    string x="";
    for(int i=0; i<s.length();i++){
        if(st.count(s[i])){
            sent++;
        }
        if(s[i]==' '){
            if(x.length()){
                transform(x.begin(),x.end(),x.begin(),::tolower);
                mp[x]++;
            }
            x="";
            spac++;
            continue;
        }
        x+=s[i];
    }
    cout<<"Number of Sentences: "<<sent<<endl;
    cout<<"Number of Spaces: "<<spac<<endl;
    cout<<"Frequency of each word: "<<endl;
    for(auto p:mp){
        cout<<p.first<<": "<<p.second<<endl;
    }
    cout<<"Number of unique words: "<<mp.size()<<endl;
    cout<<"Number of words: "<<spac+1<<endl;
    cout<<"Number of Punctuations: "<<sent<<endl;



}