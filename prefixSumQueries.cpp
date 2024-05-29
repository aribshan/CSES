#include <bits/stdc++.h>
#define int long long
using namespace std;

int tree[800005];
int prefix[800005];
int arr[200005];

void merge(int idx, int l, int r){
    if(l == r) return;

    prefix[idx] = max(prefix[2*idx], tree[2*idx] + prefix[2*idx+1]);
    tree[idx] = tree[2*idx] + tree[2*idx+1];
}

void build(int idx, int l, int r){
    if(l == r){
        tree[idx] = arr[l];
        prefix[idx] = max(0ll, arr[l]);
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
        tree[idx] = val;
        prefix[idx] = max(0ll, val);
        return;
    }

    int mid = (l + r) / 2;
    update(2*idx, l, mid, pos, val);
    update(2*idx+1, mid+1, r, pos, val);
    merge(idx, l, r);
}

vector<pair<int, pair<int,int>>> v;

void query(int idx, int l, int r, int lq, int rq){
    if(l > rq || r < lq) return;
    if(l >= lq && r <= rq){
        v.push_back({l, {prefix[idx], tree[idx]}});
        return;
    }

    int mid = (l + r) / 2;
    query(2*idx, l, mid, lq, rq);
    query(2*idx+1, mid+1, r, lq, rq);
}

void solve(){
    int n, q;
    cin >> n >> q;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    build(1, 0, n-1);

    while(q--){
        int a, b, c;
        cin >> a >> b >> c;

        if(a == 1){
            update(1, 0, n-1, b-1, c);
        }
        else{
            v = {};
            query(1, 0, n-1, b-1, c-1);
            sort(v.begin(), v.end());
            int ans = 0;
            int sum = 0;
            for(auto x : v){
                ans = max(ans, sum + x.second.first);
                sum += x.second.second;
            }

            cout << ans << '\n';
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