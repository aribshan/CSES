#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
vector<int> graph[N];
vector<vector<int>> cycles;

void dfs_cycle(int u, int p, int color[], int par[], int& cyclenumber)
{
    if(cycles.size()) return;
    if (color[u] == 2) {
        return;
    }

    if (color[u] == 1) {
        vector<int> v;
        cyclenumber++;
           
        int cur = p;
          v.push_back(cur);

        while (cur != u) {
            cur = par[cur];
              v.push_back(cur);
        }
          cycles.push_back(v);
        return;
    }
    par[u] = p;

    color[u] = 1;

    for (int v : graph[u]) {

        if (v == par[u]) {
            continue;
        }
        dfs_cycle(v, u, color, par, cyclenumber);
    }

    color[u] = 2;
}

void addEdge(int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}

int main()
{
 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        addEdge(a,b);
    }

    int color[N];
    int par[N];

    int cyclenumber = 0;
    int edges = 6;

    for(int i=1; i<=n; i++){
        if(color[i] == 0 && (cycles.size()==0)){
            dfs_cycle(i, 0, color, par, cyclenumber);
        }
    }

    if(cycles.size() == 0){
        cout << "IMPOSSIBLE" <<'\n';
    }
    else{
        int k = cycles[0].size();
        cout << k+1 << '\n';
        for(auto x : cycles[0]){
            cout << x << ' ';
        }
        cout << cycles[0][0] << ' ';
        cout << '\n';
    }
}