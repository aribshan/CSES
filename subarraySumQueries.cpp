#include <bits/stdc++.h>
#define int long long
using namespace std;

int mx[800005];
int sum[800005];
int prefix[800005];
int suffix[800005];
int arr[200005];

void merge(int idx, int l, int r){
    if(l == r) return;
    prefix[idx] = max(prefix[2*idx], sum[2*idx] + prefix[2*idx+1]);
    suffix[idx] = max(suffix[2*idx+1], sum[2*idx+1] + suffix[2*idx]);
    sum[idx] = sum[2*idx] + sum[2*idx+1];
    mx[idx] = max({mx[2*idx], mx[2*idx+1], prefix[2*idx+1] + suffix[2*idx], prefix[2*idx], prefix[2*idx+1], suffix[2*idx], suffix[2*idx+1]});
}

void build(int idx, int l, int r){
    if(l == r){
        mx[idx] = arr[l];
        sum[idx] = arr[l];
        prefix[idx] = arr[l];
        suffix[idx] = arr[l];
        return;
    }

    int mid = (l + r) / 2;
    build(2*idx, l, mid);
    build(2*idx+1, mid+1, r);
    merge(idx, l, r);
}

void update(int idx, int l, int r, int pos, int val){
    if(l > pos || r < pos) return;
    if(l == r){
        mx[idx] = val;
        sum[idx] = val;
        prefix[idx] = val;
        suffix[idx] = val;
        return;
    }

    int mid = (l + r) / 2;
    update(2*idx, l, mid, pos, val);
    update(2*idx+1, mid+1, r, pos, val);
    merge(idx, l, r);
}

int query(int idx, int l, int r, int lq, int rq){
    if(l > rq || r < lq) return 0;
    if(l >= lq && r <= rq) return max(0ll, mx[idx]);

    int mid = (l + r) / 2;
    return max(query(2*idx, l, mid, lq, rq), query(2*idx+1, mid+1, r, lq, rq));
}

void solve(){
    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    build(1, 0, n-1);

    // for(int i=0; i<4*n; i++){
    //     cout << i << ' ' << sum[i] << ' ' << prefix[i] << ' ' << suffix[i] << ' ' << mx[i] << '\n';
    // }

    while(m--){
        int k, x;
        cin >> k >> x;
        k--;
        update(1, 0, n-1, k, x);

        int ans = query(1, 0, n-1, 0, n-1);

        cout << ans << '\n';
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