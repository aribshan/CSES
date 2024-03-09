#include <bits/stdc++.h>
#define int long long
using namespace std;

int d1[200005];
int d2[200005];
vector<int> adj[200005];

void dfs1(int node, int parent){
    if(parent == -1) d1[node] = 0;
    else{
        d1[node] = 1+d1[parent];
    }
    for(int x : adj[node]){
        if(x != parent){
            dfs1(x, node);
        }
    }
}

void dfs2(int node, int parent){
    if(parent == -1) d2[node] = 0;
    else{
        d2[node] = 1 + d2[parent];
    }
    for(int x : adj[node]){
        if(x != parent){
            dfs2(x, node);
        }
    }
}

void solve(){
    int n;
    cin >> n;

    if(n == 1){
        cout << 0 << '\n';
        return;
    }

    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs1(1, -1);
    int mxval = 0, node = 0;
    for(int i=1; i<=n; i++){
        if(d1[i] > mxval){
            node = i;
            mxval = d1[node];
        }
    }

    // cout << node << '\n';

    dfs1(node, -1);
    mxval = 0, node = 0;
    for(int i=1; i<=n; i++){
        if(d1[i] > mxval){
            node = i;
            mxval = d1[node];
        }
    }

    // cout << node << '\n';

    dfs2(node, -1);

    for(int i=1; i<=n; i++){
        // cout << d1[i] << ' ' << d2[i] << '\n';
        cout << max(d1[i], d2[i]) << ' ';
    }
    cout << '\n';

}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
 
    solve();

    return 0;
}

