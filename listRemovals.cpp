#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> arr, tree; 
int n;

void build(int idx, int l, int r){
    if(l == r){
        tree[idx] = 1;
        return;
    }
    int mid = (l+r)/2;
    build(2*idx, l, mid);
    build(2*idx+1, mid+1, r);
    tree[idx] = tree[2*idx]+tree[2*idx+1];
}

int query(int idx, int l, int r, int val){
    if(l == r){
        tree[idx] = 0;
        //cout << val << ' ' << tree[idx] << ' ' << l << ' ' << r <<'\n';
        return l;
    }
    int mid = (l+r)/2;
    int v1 = tree[2*idx];
    int v2 = tree[2*idx+1];
    tree[idx]--;
    //cout << val << ' ' << v1 << ' ' << v2 << '\n';
    if(val > v1){
        return query(2*idx+1, mid+1, r, val-v1);
    }
    else{
        return query(2*idx, l, mid, val);
    }
    //tree[idx] = tree[2*idx]+tree[2*idx+1];
}

void solve(){
    cin >> n;

    tree.resize(4*n);
    arr.resize(n);

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    build(1, 0, n-1);

    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        //cout << '\n';

        int ans = query(1, 0, n-1, a);
        cout << arr[ans] << ' ';
        // for(int idx=0;idx<=3*n; idx++){
        //     cout << idx<< ' ' << tree[idx] << '\n';
        // }
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

