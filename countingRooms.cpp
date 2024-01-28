#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<string> arr(n); 
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    vector<int> h = {-1,1,0,0};
    vector<int> v = {0,0,-1,1};
    int count = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == '.'){
                count++;
                queue<pair<int,int>> q;
                q.push({i, j});
                arr[i][j] = '#';
                while(!q.empty()){
                    auto node = q.front();
                    q.pop();
                    for(int k=0; k<4; k++){
                        int ni = node.first+h[k], nj = node.second+v[k];
                        if(ni>=0 && nj>=0 && ni<n && nj<m && arr[ni][nj]=='.'){
                            q.push({ni,nj});
                            arr[ni][nj] = '#';
                        }
                    }
                }
            }
        }
    }

    cout << count << '\n';
}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
 
    solve();

    return 0;
}
