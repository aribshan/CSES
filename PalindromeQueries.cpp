#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;

const int MOD = 1e9 + 9;
int p = 37;

int brr[200005], crr[200005];
int tree2[800005], tree3[800005];

ll exp(ll x, ll n, ll m){  // {number, power, mod}
    x %= m;
    ll res = 1;

    while(n > 0){
        if(n % 2 == 1) res = res * x % m;
        x = x * x % m;
        n /= 2;
    }

    return res;
}

ll inverse(int x, int m){ // {number, mod}
    return exp(x, MOD - 2, MOD);
}

void build(int idx, int l, int r){
    if(l == r){
        tree2[idx] = brr[l];
        tree3[idx] = crr[l];
        return;
    }

    int mid = (l + r) / 2;
    build(2*idx, l, mid);
    build(2*idx+1, mid+1, r);
    tree2[idx] = (tree2[2*idx] + tree2[2*idx+1]) % MOD;
    tree3[idx] = (tree3[2*idx] + tree3[2*idx+1]) % MOD;
}

void update(int idx, int l, int r, int pos){
    if(l > pos || r < pos) return;
    if(l == r){
        tree2[idx] = brr[l];
        tree3[idx] = crr[l];
        return;
    }

    int mid = (l + r) / 2;
    update(2*idx, l, mid, pos);
    update(2*idx+1, mid+1, r, pos);
    tree2[idx] = (tree2[2*idx] + tree2[2*idx+1]) % MOD;
    tree3[idx] = (tree3[2*idx] + tree3[2*idx+1]) % MOD;
}

int query2(int idx, int l, int r, int lq, int rq){
    if(l > rq || r < lq) return 0;
    if(l >= lq && r <= rq) return tree2[idx];

    int mid = (l + r) / 2;
    return (query2(2*idx, l, mid, lq, rq) + query2(2*idx+1, mid+1, r, lq, rq)) % MOD;
}
int query3(int idx, int l, int r, int lq, int rq){
    if(l > rq || r < lq) return 0;
    if(l >= lq && r <= rq) return tree3[idx];

    int mid = (l + r) / 2;
    return (query3(2*idx, l, mid, lq, rq) + query3(2*idx+1, mid+1, r, lq, rq)) % MOD;
}

void solve(){
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    int prr[n+5];
    prr[0] = 1;
    for(int i=1; i<=n; i++){
        prr[i] = prr[i-1] * p % MOD;
    }

    for(int i=0; i<n; i++){
        brr[i] = (s[i] - 'a' + 1) * prr[i+1] % MOD;
        crr[i] = (s[i] - 'a' + 1) * prr[n-i] % MOD;
    }

    build(1, 0, n-1);

    while(m--){
        int k;
        cin >> k;

        if(k == 1){
            int i;
            char ch;
            cin >> i >> ch;
            i--;

            brr[i] = (ch - 'a' + 1) * prr[i+1] % MOD;
            crr[i] = (ch - 'a' + 1) * prr[n-i] % MOD;

            update(1, 0, n-1, i);
        }
        else{
            int l, r;
            cin >> l >> r;
            l--;
            r--;

            int sz = (r - l + 1);
            if(sz % 2){
                int mid = (l + r) / 2;
                int left = query3(1, 0, n-1, l, mid) * inverse(prr[n - mid - 1] , MOD) % MOD;
                int right = query2(1, 0, n-1, mid, r) * inverse(prr[mid], MOD) % MOD;
                if(left < 0) left += MOD;
                if(right < 0) right += MOD;

                if(left == right){
                    cout << "YES" << '\n';
                }
                else{
                    cout << "NO" << '\n';
                }
            }
            else{
                int mid = (l + r) / 2;
                int left = query3(1, 0, n-1, l, mid) * inverse(prr[n - mid - 1] , MOD) % MOD;
                int right = query2(1, 0, n-1, mid + 1, r) * inverse(prr[mid + 1], MOD) % MOD;
                if(left < 0) left += MOD;
                if(right < 0) right += MOD;
                if(left == right){
                    cout << "YES" << '\n';
                }
                else{
                    cout << "NO" << '\n';
                }
            }
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