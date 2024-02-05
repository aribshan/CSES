#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> adj;
vector<vector<int>> revAdj;
vector<int> coins;
vector<int> comp;
vector<bool> vis;
stack<int> st;
int comps;

void dfs1(int node){
    vis[node] = true;

    for(auto x : adj[node]){
        if(!vis[x]) dfs1(x);
    }
    st.push(node);
}

void dfs2(int node){
    vis[node] = true;
    comp[node] = comps;

    for(auto x : revAdj[node]){
        if(!vis[x]){
            dfs2(x);
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;

    coins.resize(n+1);
    adj.resize(n+1);
    revAdj.resize(n+1);
    comp.resize(n+1);
    vis.resize(n+1, false);

    for(int i=1; i<=n; i++){
        cin >> coins[i];
    }
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

    vis.clear();
    vis.resize(n+1, false);

    comps = 0;
    while(!st.empty()){
        if(vis[st.top()] == false){
            comps++;
            dfs2(st.top());
        }
        st.pop();
    }

    vector<int> compCoins(comps+1, 0);
    for(int i=1; i<=n; i++){
        compCoins[comp[i]] += coins[i];
    }

    vector<set<int>> cAdj(comps+1);

    vector<int> idg(comps+1, 0);
    for(int i=1; i<=n; i++){
        for(auto y : adj[i]){
            if(comp[i] != comp[y]){
                if(cAdj[comp[i]].find(comp[y]) == cAdj[comp[i]].end()){
                    idg[comp[y]]++;
                }
                cAdj[comp[i]].insert(comp[y]);
            }
        }
    }

    queue<int> q;
    for(int i=1; i<=comps; i++){
        if(idg[i] == 0){
            q.push(i);
        }
    }

    // for(int i=1; i<=n; i++){
    //     cout << i << '-' << comp[i] << ' ';
    // }
    // cout << '\n';

    int ans = 0;
    // for(int i=1; i<=comps; i++){
    //     cout << compCoins[i] << '\n';
    // }
    vector<int> fin(comps+1, 0);
    while(!q.empty()){
        int node = q.front();
        fin[node] += compCoins[node];
        ans = max(ans, fin[node]);
        q.pop();

        for(auto x : cAdj[node]){
            fin[x] = max(fin[x], fin[node]);
            idg[x]--;
            if(idg[x] == 0){
                q.push(x);
            }
        }
    }

    // for(int i=1; i<=comps; i++){
    //     cout << i << '-' << fin[i] << '\n';
    // }



    cout << ans << '\n';


}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
 
    solve();

    return 0;
}

