#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<bool> vis;
stack<int> st;
vector<vector<int>> adj;
vector<vector<int>> revAdj;
//vector<int> comp;
int comp = 0;

void dfs1(int node){
    vis[node] = true;
    
    for(auto x : adj[node]){
        if(vis[x] == false){
            dfs1(x);
        }
    }
    st.push(node);
}

void dfs2(int node){
    vis[node] = true;

    for(auto x : revAdj[node]){
        //cout <<node << '-' << x << ' ';
        if(vis[x] == false){
            dfs2(x);
        }
    }
}



void solve(){
    int n, m;
    cin >> n >> m;

    adj.resize(n+1);
    revAdj.resize(n+1);
    vis.resize(n+1, 0);

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        revAdj[b].push_back(a);
    }

    for(int i=1; i<=n; i++){
        if(vis[i] == false){
            dfs1(i);
        }
    }

    // cout << '\n';
    // while(!st.empty()){
    //     cout << st.top() << ' ';
    //     st.pop();
    // }

    vis.clear();
    vis.resize(n+1, false);
    vector<int> idk;
    while(!st.empty()){
        //cout << st.top() << '-' << vis[st.top()] << ' ';
        if(vis[st.top()] == false){
            //cout << st.top() << ' ';
            dfs2(st.top());
            idk.push_back(st.top());
            comp++;
        }
        st.pop();
    }

    //cout << comp << ' ';
    
    // for(auto x : idk){
    //     cout << x << '\n';
    // }

    if(idk.size() >= 2){
        cout<< "NO" << '\n';
        cout << idk[1] << ' ' <<idk[0] << '\n';
    }
    else{
        cout << "YES" <<'\n';
    }


}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
 
    solve();

    return 0;
}

