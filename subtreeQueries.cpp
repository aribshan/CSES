#include <bits/stdc++.h>
#define int long long
using namespace std;
int arr[200005];
int brr[200005];
int mp[200005];
int nodeCount[200005];
vector<int> adj[200005];
int tree[800200];
int cnt;

int dfs(int node, int parent){
    cnt++;
    mp[node] = cnt;
    int vals = 1;

    for(int x : adj[node]){
        if(x != parent){
            vals += dfs(x, node);
        }
    }

    nodeCount[mp[node]] = vals;
    arr[mp[node]] = brr[node];

    return vals;
}

void build(int idx, int l, int r){
    if(l == r){
        tree[idx] = arr[l];
        return;
    }
    int mid = (l+r)/2;

    build(2*idx, l, mid);
    build(2*idx+1, mid+1, r);
    tree[idx] = (tree[2*idx] + tree[2*idx+1]);
}

void update(int idx, int l, int r, int pos, int val){
    if(l>pos || r<pos) return;

    if(l == r){
        tree[idx] = val;
        return;
    }
    int mid = (l+r)/2;

    update(2*idx,  l, mid, pos, val);
    update(2*idx+1, mid+1, r, pos, val);
    tree[idx] = (tree[2*idx] + tree[2*idx+1]);
}

int query(int idx, int l, int r, int lq, int rq){
    if(l>rq || r<lq) return 0;
    if(l>=lq && r<=rq){
        return tree[idx];
    }

    int mid = (l+r)/2;
    return (query(2*idx, l, mid, lq, rq) + query(2*idx+1, mid+1, r, lq, rq));
}


void solve(){
    int n, q;
    cin >> n >> q;
    cnt = 0;

    for(int i=1; i<=n; i++){
        cin >> brr[i];
    }

    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1);
    build(1, 0, cnt);

    // for(int i=1; i<=n; i++){
    //     cout << i << ' ' << mp[i] << '\n';
    // }

    // for(int i=1; i<=n; i++){
    //     cout << i << ' ' << mp[i] << ' ' << arr[mp[i]] << ' ' << nodeCount[mp[i]] << '\n';
    // }

    while(q--){
        int a;
        cin >> a;

        if(a == 1){
            int s, x;
            cin >> s >> x;
            arr[mp[s]] = x;
            update(1, 0, cnt, mp[s], x);
        }
        else{
            int s;
            cin >> s;
            // cout << s << ' ' << mp[s] << ' ' << nodeCount[mp[s]] << '\n';
            int ans = query(1, 0, cnt, mp[s], mp[s] + nodeCount[mp[s]] - 1);
            cout << ans << '\n';
        }
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

