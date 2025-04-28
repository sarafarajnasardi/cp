#include <bits/stdc++.h>
using namespace std;

// int main(){
//     string s;
//     getline(cin,s);
//     string mode;
//     cin>>mode;
//     if(mode=="lower"){
//         transform(s.begin(),s.end(),s.begin(),::tolower);
//     }else{
//         transform(s.begin(),s.end(),s.begin(),::toupper);
//     }
//     cout<<s<<endl;
// }


// int gcd(int a,int b){
//     return (b==0)?a:gcd(b,a%b);
// }
// int main(){
//     cout<<gcd(10,15)<<endl;
// }

// int main(){
//     string a,b;
//     getline(cin,a);
//     getline(cin,b);
//     int n=a.length();
//     int m=b.length();
//     int cnt=0;
//     for(int i=0;i<=n-m;i++){
//         int j=0;
//         while(j<m&&b[j]==a[i+j]){
//             j++;
//         }
//         if(j==m){
//             cnt++;
//         }
//     }
//     cout<<cnt<<endl;
// }

// struct Item{
//     int value,weight;
// };

// bool cmp(Item a,Item b){
//     double r1=(double) a.value/a.weight;
//     double r2=(double) b.value/b.weight;
//     return r1>r2;
// }

// int main(){
//     int w;
//     cin>>w;
//     Item arr[3];
//     for(int i=0;i<3;i++){
//         cin >> arr[i].value >> arr[i].weight;
//     }
//     sort(arr,arr+3,cmp);
//     int ans=0;
//     for(int i=0;i<3;i++){
//         if(w>=arr[i].weight){
//             ans+=(arr[i].value);
//             w-=arr[i].weight;
//         }else{
//             ans+=(arr[i].value)*((double) w/arr[i].weight);
//             w=0;
//         }
//     }
//     cout<<ans<<endl;
// }

// int main(){
//     int n,m;
//     cin>>n>>m;
//     vector<vector<pair<int,int>>>adj(n);
//     for(int i=0;i<m;i++){
//         int a,b,w;
//         cin>>a>>b>>w;
//         adj[a].push_back({b,w});
//         adj[b].push_back({a,w});
//     }
//     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
//     pq.push({0,0});
//     vector<int>dist(n+1,INT_MAX);
//     dist[0]=0;
//     while(!pq.empty()){
//         auto it=pq.top();pq.pop();
//         int node=it.first;int depth=it.second;
//         for(auto x:adj[node]){
//             if(depth+x.second<dist[x.first]){
//                 dist[x.first]=depth+x.second;
//                 pq.push({x.first,dist[x.first]});
//             }
//         }
//     }
//     cout<<dist[n-1]<<endl;
// }

class DSU{
    public:
    vector<int>parent;
    DSU(int n){
        parent.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findUpar(int node){
        if(node==parent[node])return node;
        return parent[node]=findUpar(parent[node]);
    }
    void uni(int u,int v){
        parent[findUpar(u)]=findUpar(v);
    }
};

// int main(){
//     int n=4;
//     vector<tuple<int,int,int>> edges = {
//         {2,0,1},{1,0,2},{1,1,2},{2,2,3},{1,3,4},{2,4,2}
//     };
//     sort(edges.begin(), edges.end());
//     DSU obj(n);
//     int mst=0;
//     for(auto x:edges){
//         int w=get<0>(x);
//         int u=get<1>(x);
//         int v=get<2>(x);
//         if(obj.findUpar(u)!=obj.findUpar(v)){
//             mst+=w;
//             obj.uni(u,v);
//         }
//     }
//     cout<<mst<<endl;
// }

int main(){
    int n=4;
    vector<vector<pair<int,int>>>adj(n+1);
    adj[0].push_back({1,2}); adj[0].push_back({2,4});
    adj[1].push_back({2,1}); adj[1].push_back({3,7});
    adj[2].push_back({4,3});
    adj[3].push_back({4,1});
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,0});
    vector<int>visited(n+1,0);
    int mst=0;
    while(!pq.empty()){
        auto it=pq.top();pq.pop();
        int wt=it.second;
        int node=it.first;
        if(visited[node]){
            continue;
        }
        mst+=wt;
        visited[node]=1;
        for(auto x:adj[node]){
            pq.push({x.first,x.second});
        }
    }
    cout<<mst<<endl;
}