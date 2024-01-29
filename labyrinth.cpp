#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, m, sx, sy, ex, ey;
    cin >> n >> m;
    vector<string> grid(n);
    for(int i=0; i<n; i++){
        cin >> grid[i];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 'A'){
                sx = i, sy = j;
                grid[i][j] = '#';
            }
            if(grid[i][j] == 'B'){
                ex = i, ey = j;
                grid[i][j] = '.';
            }
        }
    }

    queue<pair<int,int>> q;
    q.push({sx, sy});

    vector<int> h = {-1,1,0,0};
    vector<int> v = {0,0,-1,1};
    vector<char> c = {'U','D','L','R'};

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x+h[i];
            int ny = y+v[i];
            if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]=='.'){
                grid[nx][ny] = c[i];
                q.push({nx, ny});
            }
        }
    }

    // for(int i=0; i<n; i++){
    //     cout << grid[i] << '\n';
    // }
    string ans;
    map<int, pair<int,int>> mp;
    mp['L'] = {0,1};
    mp['R'] = {0,-1};
    mp['D'] = {-1,0};
    mp['U'] = {1,0};
    //cout << sx << ' ' << sy << '\n';

    if(grid[ex][ey]=='.'){
        cout << "NO" << '\n';
    }
    else{
        while(true){
            if(sx == ex && sy == ey) break;
            ans += grid[ex][ey];
            char ch = grid[ex][ey];
            
            //cout << ex << ' ' << ey << ' ';
            ex += mp[ch].first;
            ey += mp[ch].second;
            //cout << ex << ' ' << ey << '\n';
            //if(ch == '#') break;
        }

        reverse(ans.begin(), ans.end());
        cout << "YES" << '\n';
        cout << ans.length() << '\n';
        cout << ans << '\n';
    }
}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
 
    solve();

    return 0;
}
