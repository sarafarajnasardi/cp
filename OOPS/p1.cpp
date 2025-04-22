#include <bits/stdc++.h>

using namespace std;

int main(){
    int deck[52];
    string suit[4]={"spades","hearts","diamonds","clubs"};
    string rank[13]={"ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};
    for(int i=0;i<53;i++){
        deck[i]=i;
    }
    random_shuffle(deck,deck+52);
    for(int i=0;i<4;i++){
        int cardnumber=deck[i];
        string sui=suit[deck[i]/13];
        string ran=rank[cardnumber%13];
        cout<<"cardnumber:"<<cardnumber<<"sui:"<<sui<<"rank:"<<ran<<endl;
    }
    return 0;
}