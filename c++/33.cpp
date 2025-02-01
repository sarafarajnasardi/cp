#include<bits/stdc++.h>
using namespace std;

int main(){
    string para;
    getline(cin,para);
    int size=para.size();
    int word=0;
    string x="";
    int punt;
    set<char>a={'.',','};
    map<string ,int>uni;
    for (int i=0;i<size;i++){
        if (para[i]==' '){
            word++;
            uni[x]++;
            x="";
        }
        else if (a.find(para[i])!=a.end()){
            punt++;
        }
        else{
            x+=tolower(para[i]);
        }
    }
    cout<<"the nos of unique words are "<<word<<endl;
    cout<<"the total nos of unique words with its frequency is "<<endl;
    for (auto i:uni){
        cout<<i.first<<" : "<<i.second<<endl;
    }
    cout<<punt;
}
