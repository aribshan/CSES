#include <bits/stdc++.h>
#define int long long
using namespace std;

int tree[1600000];
map<int, int> mp;

void update(int idx, int l, int r, int pos, int val){
    if(l>pos || r<pos) return;

    if(l == r){
        tree[idx] = max(tree[idx], val);
        return;
    }
    int mid = (l+r)/2;

    update(2*idx,  l, mid, pos, val);
    update(2*idx+1, mid+1, r, pos, val);
    tree[idx] = max(tree[2*idx], tree[2*idx+1]);
}

int query(int idx, int l, int r, int lq, int rq){
    if(l>rq || r<lq) return 0;
    if(l>=lq && r<=rq){
        return tree[idx];
    }

    int mid = (l+r)/2;
    return max(query(2*idx, l, mid, lq, rq), query(2*idx+1, mid+1, r, lq, rq));
}

void solve(){
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(3));
    for(int i=0; i<n; i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
        mp[arr[i][0]];
        mp[arr[i][1]];
    }

    int cnt = 0;
    for(auto &x : mp){
        x.second = cnt;
        cnt++;
    }

    sort(arr.begin(), arr.end(), [&](const vector<int>&a,const vector<int>&b){
        if(a[1] == b[1]){
            return a[0] < b[0];
        }
        return a[1] < b[1];
    });

    int ans = 0;
    int val;
    for(int i=0; i<n; i++){
        int mx = query(1, 0, cnt, 0, mp[arr[i][0]]-1);
        val = mx + arr[i][2];
        update(1, 0, cnt, mp[arr[i][1]], val);
        ans = max(ans, val);
    }

    cout << ans << '\n';
}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
    ios::sync_with_stdio(false); cin.tie(NULL);
    solve();

    return 0;
}

