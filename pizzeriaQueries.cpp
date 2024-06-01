#include <bits/stdc++.h>
#define int long long
using namespace std;

int tree1[800005];
int tree2[800005];
int arr[200005];

void build(int idx, int l, int r){
    if(l == r){
        tree1[idx] = arr[l] - l;
        tree2[idx] = arr[l] + l;
        return;
    }

    int mid = (l + r) / 2;
    build(2*idx, l, mid);
    build(2*idx+1, mid+1, r);
    tree1[idx] = min(tree1[2*idx], tree1[2*idx+1]);
    tree2[idx] = min(tree2[2*idx], tree2[2*idx+1]);
}

void update(int idx, int l, int r, int pos, int val){
    if(l > pos || r < pos) return;
    if(l == r){
        tree1[idx] = val - l;
        tree2[idx] = val + l;
        return;
    }

    int mid = (l + r) / 2;
    update(2*idx, l, mid, pos, val);
    update(2*idx+1, mid+1, r, pos, val);
    tree1[idx] = min(tree1[2*idx], tree1[2*idx+1]);
    tree2[idx] = min(tree2[2*idx], tree2[2*idx+1]);
}

int query1(int idx, int l, int r, int lq, int rq){
    if(l > rq || r < lq) return 1e15;
    if(l >= lq && r <= rq) return tree1[idx];

    int mid = (l + r) / 2;
    return min(query1(2*idx, l, mid, lq, rq), query1(2*idx+1, mid+1, r, lq, rq));
}

int query2(int idx, int l, int r, int lq, int rq){
    if(l > rq || r < lq) return 1e15;
    if(l >= lq && r <= rq) return tree2[idx];

    int mid = (l + r) / 2;
    return min(query2(2*idx, l, mid, lq, rq), query2(2*idx+1, mid+1, r, lq, rq));
}

void solve(){
    int n, q;
    cin >> n >> q;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    build(1, 0, n-1);

    while(q--){
        int x;
        cin >> x;

        if(x == 1){
            int k, v;
            cin >> k >> v;
            k--;

            update(1, 0, n-1, k, v);
        }
        else{
            int k;
            cin >> k;
            k--;

            int v1 = k + query1(1, 0, n-1, 0, k);
            int v2 = query2(1, 0, n-1, k, n-1) - k;

            cout << min(v1, v2) << '\n';
        }
    }
}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();

    return 0;
}