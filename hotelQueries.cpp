#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> tree;
vector<int> arr;
int n;

void build(int idx, int l, int r){
    if(l == r){
        tree[idx] = arr[l];
        return;
    }
    int mid = (l+r)/2;
    build(2*idx, l, mid);
    build(2*idx+1, mid+1, r);
    tree[idx] = max(tree[2*idx], tree[2*idx+1]);
}

void update(int idx, int l, int r, int pos, int val){
    if(l>pos || r<pos) return;
    if(l == r){
        tree[idx] -= val;
        arr[pos] -= val;
        return;
    }

    int mid = (l+r)/2;

    update(2*idx, l, mid, pos, val);
    update(2*idx+1, mid+1, r, pos, val);
    tree[idx] = max(tree[2*idx], tree[2*idx+1]);
}

int query(int idx, int l, int r, int val){
    if(tree[idx] < val) return n+2;

    if(l == r){
        if(tree[idx] >= val) return l;
        else{
            return n+2;
        }
    }

    int mid = (l+r)/2;
    if(tree[2*idx] >= val) return query(2*idx, l, mid, val);
    else{
        return query(2*idx+1, mid+1, r, val);
    }
}

void solve(){
    tree.clear();
    arr.clear();
    int q;
    cin >> n >> q;

    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }

    tree.resize(4*n);
    build(1, 0, n-1);

    while(q--){
        int a;
        cin >> a;

        int ans = query(1, 0, n-1, a);
        if(ans < n){
            cout << ans+1 << ' ';
            update(1, 0, n-1, ans, a);
        }
        else{
            cout << 0 << ' ';
        }
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

