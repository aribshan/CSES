#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define EB emplace_back
#define MP make_pair
#define int long long
#define all(o) (o).begin(), (o).end()
#define mset(m,v) memset(m,v,sizeof(m))
#define fr(i,n) for(lli i=0;i<n;++i)
#define rep(i,a,b) for(lli i=a;i<=b;++i)
#define pb push_back
#define ppb pop_back
#define mkp make_pair
#define remin(a,b) (a=min((a),(b)))
#define remax(a,b) (a=max((a),(b)))
#define endl '\n'
typedef long long lli;        typedef long double ld;
typedef pair<lli,lli> ii;     typedef vector<lli> vi;
typedef vector<ii> vii;       typedef vector<vi> graph;
long long MOD=1e9+7;     long double EPS=1e-9;
#define debarr(a,n) cout<<#a<<" : ";for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debmat(mat,row,col) cout<<#mat<<" :\n";for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const unordered_set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}template <class S, class T>ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}template <class T>ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}
lli binpow(lli b,lli p,lli mod){lli ans=1;for(;p;p>>=1){if(p&1)ans=ans*b%mod;b=b*b%mod;}return ans;}
lli mod_mul(lli a, lli b) {a = a % MOD; b = b % MOD; return (((a * b) % MOD) + MOD) % MOD;}
lli pwr(lli a, lli b) {a %= MOD; lli res = 1; while (b > 0) {if (b & 1) res = res * a % MOD; a = a * a % MOD; b >>= 1;} return res;}


vi fact(200005, 1);
lli ncr(lli n , lli r)
{
    lli ans = 1;
    ans = fact[n];
    ans = mod_mul(ans, pwr(fact[r], MOD - 2));
    ans = mod_mul(ans, pwr(fact[n - r], MOD - 2));
    return ans;
}

void solve(){
    int a, b;
    cin >> a >> b;

    int ans = pwr(a, b);
    cout << ans << '\n';
}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
 
    rep(i, 2, 200000){
        fact[i] = mod_mul(fact[i - 1], i);
    }
    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}

