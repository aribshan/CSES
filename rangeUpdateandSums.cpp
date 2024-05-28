#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 200005;
const int MAXN4 = 800100;

int tree[MAXN4];
int lazy[MAXN4];
int lazy2[MAXN4];
int arr[MAXN];
int lrr[MAXN4];
int rrr[MAXN4];

void lazypush(int idx, int l, int r){
    if(lazy2[idx] > 0) tree[idx] = (r-l+1)*lazy2[idx];
    tree[idx] += (r-l+1)*lazy[idx];   

    if(l != r){
        if(lazy2[idx]){
            lazy[2*idx+1] = 0;
            lazy[2*idx] = 0;
            lazy2[2*idx+1] = lazy2[idx];
            lazy2[2*idx] = lazy2[idx];
        }
        lazy[2*idx+1] += lazy[idx];
        lazy[2*idx] += lazy[idx];
    }
    
    lazy[idx] = 0;
    lazy2[idx] = 0;
}

void build(int idx, int l, int r){
    lrr[idx] = l;
    rrr[idx] = r;
    if(l == r){
        tree[idx] = arr[l];
        return;
    }

    int mid = (l + r) / 2;
    build(2*idx, l, mid);
    build(2*idx+1, mid+1, r);
    tree[idx] = tree[2*idx] + tree[2*idx+1];
}

void update(int idx, int l, int r, int lq, int rq, int val){
    if(l > rq || r < lq) return;
    if(l >= lq && r <= rq){
        lazy[idx] += val;
        return;
    }

    int mid = (l+r)/2;
    lazypush(idx, l, r);
    update(2*idx, l, mid, lq, rq, val);
    update(2*idx+1, mid+1, r, lq, rq, val);
    lazypush(2*idx, l, mid);
    lazypush(2*idx+1, mid+1, r);
    tree[idx] = tree[2*idx] + tree[2*idx+1];
}

void update2(int idx, int l, int r, int lq, int rq, int val){
    if(l > rq || r < lq) return;
    if(l >= lq && r <= rq){
        lazy2[idx] = val;
        lazy[idx] = 0;
        return;
    }

    int mid = (l+r)/2;
    lazypush(idx, l, r);
    update2(2*idx, l, mid, lq, rq, val);
    update2(2*idx+1, mid+1, r, lq, rq, val);
    lazypush(2*idx, l, mid);
    lazypush(2*idx+1, mid+1, r);
    tree[idx] = tree[2*idx] + tree[2*idx+1];
}

int query(int idx, int l, int r, int lq, int rq){
    lazypush(idx, l, r);
    if(l > rq || r < lq) return 0;
    if(l >= lq && r <= rq){
        return tree[idx];
    }

    int mid = (l+r)/2;
    return (query(2*idx, l, mid, lq, rq) + query(2*idx+1, mid+1, r, lq, rq));
}

void solve(){
    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> arr[i];
        // cout << i << ' ' << arr[i] << '\n';
    }

    build(1, 0, n-1);

    // for(int i=0; i<=4*n; i++){
    //     cout << i << ' ' << tree[i] << '\n';
    // }

    while(m--){
        int type;
        cin >> type;

        if(type == 1){
            int l, r, val;
            cin >> l >> r >> val;
            l--;
            r--;
            update(1, 0, n-1, l, r, val);

        }
        else if(type == 2){
            int l, r, val;
            cin >> l >> r >> val;
            l--;
            r--;
            
            update2(1, 0, n-1, l, r, val); 
        }
        else{
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            int val = query(1, 0, n-1, l, r);
            cout << val << '\n';
        }
    }

    // for(int i=0; i<=4*n; i++){
    //     cout << i << ' ' << lrr[i] << ' ' << rrr[i] << ' ' << tree[i] << ' ' << lazy[i] << ' ' << lazy2[i] << '\n';
    // }
}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
 
    solve();

    return 0;
}