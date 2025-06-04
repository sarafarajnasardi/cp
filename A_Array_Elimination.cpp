#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegTree {
    int N;
    vector<ll> st;
    SegTree(int n): N(n), st(4*n,0) {}

    void build(int p, int l, int r, const vector<ll>& base) {
        if(l==r) {
            st[p]=base[l];
        } else {
            int m=(l+r)>>1;
            build(p<<1,l,m,base);
            build(p<<1|1,m+1,r,base);
            st[p]=st[p<<1]+st[p<<1|1];
        }
    }
    ll query(int p,int l,int r,int i,int j){
        if(j<l||r<i) return 0;
        if(i<=l&&r<=j) return st[p];
        int m=(l+r)>>1;
        return query(p<<1,l,m,i,j)
             + query(p<<1|1,m+1,r,i,j);
    }
    void update(int p,int l,int r,int idx,ll val){
        if(l==r){
            st[p]=val;
        } else {
            int m=(l+r)>>1;
            if(idx<=m) update(p<<1,l,m,idx,val);
            else        update(p<<1|1,m+1,r,idx,val);
            st[p]=st[p<<1]+st[p<<1|1];
        }
    }
};

int N, R;
vector<vector<pair<int,int>>> adj; 
// adj[u]: list of (v, edge_id)

vector<int> parent, depth, heavy, sz;
vector<ll> edge_w;       // edge_w[eid] = weight of that edge
vector<int> parent_eid;  // parent_eid[u] = id of edge (parent[u],u)

int dfs(int u){
    sz[u]=1;
    int maxSub=0;
    for(auto [v,eid]: adj[u]){
        if(v==parent[u]) continue;
        parent[v]=u;
        parent_eid[v]=eid;
        depth[v]=depth[u]+1;
        int s = dfs(v);
        sz[u]+=s;
        if(s>maxSub){
            maxSub=s;
            heavy[u]=v;
        }
    }
    return sz[u];
}

vector<int> head, pos;
int curPos;
void decomp(int u,int h){
    head[u]=h;
    pos[u]=curPos++;
    if(heavy[u]!=-1){
        decomp(heavy[u],h);
    }
    for(auto [v,eid]: adj[u]){
        if(v==parent[u]||v==heavy[u]) continue;
        decomp(v,v);
    }
}

ll queryPath(int u,int v, SegTree &st){
    ll res=0;
    while(head[u]!=head[v]){
        if(depth[head[u]] > depth[head[v]]){
            res += st.query(1,0,N-1,pos[head[u]],pos[u]);
            u = parent[head[u]];
        } else {
            res += st.query(1,0,N-1,pos[head[v]],pos[v]);
            v = parent[head[v]];
        }
    }
    // now in same chain
    if(u==v) return res;
    if(depth[u] > depth[v]){
        // sum edges from v+1 ... u
        res += st.query(1,0,N-1,pos[v]+1,pos[u]);
    } else {
        res += st.query(1,0,N-1,pos[u]+1,pos[v]);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M;
    cin >> N >> R >> M;
    adj.assign(N+1,{});
    edge_w.assign(M,0);
    vector<pair<int,int>> E(M);
    for(int i=0;i<M;i++){
        int x,y; ll z;
        cin>>x>>y>>z;
        E[i]={x,y};
        edge_w[i]=z;
        adj[x].push_back({y,i});
        adj[y].push_back({x,i});
    }

    parent.assign(N+1,0);
    depth.assign(N+1,0);
    heavy.assign(N+1,-1);
    sz.assign(N+1,0);
    parent_eid.assign(N+1,-1);

    // build HLD
    parent[R]=0;
    depth[R]=0;
    dfs(R);
    head.assign(N+1,0);
    pos.assign(N+1,0);
    curPos=0;
    decomp(R,R);

    // build base array for segtree: base[pos[u]] = weight of edge(parent[u],u)
    vector<ll> base(N,0);
    for(int u=1;u<=N;u++){
        if(u==R) continue;
        int eid = parent_eid[u];
        base[pos[u]] = edge_w[eid];
    }

    SegTree st(N);
    st.build(1,0,N-1,base);

    int Q; 
    cin >> Q;
    ll answerSum=0;
    while(Q--){
        int t; 
        cin>>t;
        if(t==1){
            int A,B;
            cin>>A>>B;
            answerSum += queryPath(A,B,st);
        } else {
            int X,Y; ll Z;
            cin>>X>>Y>>Z;
            // find which is deeper: that's the child
            int child = (parent[X]==Y? X : Y);
            // update that node's pos
            st.update(1,0,N-1,pos[child],Z);
        }
    }

    cout << answerSum << "\n";
    return 0;
}
