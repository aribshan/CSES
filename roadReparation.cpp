#include <bits/stdc++.h>
#define int long long
using namespace std;


vector<int> parent;
int findPar(int a){
    if(parent[a] == a) return a;
    return parent[a] = findPar(parent[a]); 
}

void merge(int a, int b){
    int aa = findPar(a);
    int bb = findPar(b);

    if(aa == bb) return;
    parent[a] = bb;
    parent[aa] = bb;
}

void solve(){
    int n, m;
    cin >> n >> m;

    parent.resize(n+1);

    //vector<vector<pair<int,int>>> adj(n+1);
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

    for(int i=0; i<m; i++){
        int a, b ,c;
        cin >> a>>b>>c;

        // adj[a].push_back({b,c});
        // adj[b].push_back({a,c});
        pq.push({c, {a, b}});
    }

    for(int i=1; i<=n; i++) parent[i] = i;

    int cost = 0;


    while(!pq.empty()){
        int c = pq.top().first;
        int a = pq.top().second.first;
        int b = pq.top().second.second;
        pq.pop();

        if(findPar(a) != findPar(b)){
            cost += c;
            merge(a, b);
        }
    }

    int par = findPar(1);
    bool ok = true;
    for(int i=2; i<=n; i++){
        if(findPar(i) != par){
            ok = false;
            break;
        }
    }

    if(ok){
        cout << cost << '\n';
    }
    else{
        cout << "IMPOSSIBLE" << '\n';
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

