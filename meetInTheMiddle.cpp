#include <bits/stdc++.h>
#define int long long
using namespace std;

int X[2000005],Y[2000005];

void calcsubarray(vector<int>& a, int x[], int n, int c)
{
    for (int i=0; i<(1<<n); i++)
    {
        int s = 0;
        for (int j=0; j<n; j++)
            if (i & (1<<j))
                s += a[j+c];
        x[i] = s;
    }
}

void solve(){
    int n, sum;
    cin >> n >> sum;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    calcsubarray(arr, X, n/2, 0);
    calcsubarray(arr, Y, n-n/2, n/2);

    int sx = 1<<(n/2);
    int sy = 1<<(n-n/2);

    sort(Y, Y+sy);

    int count = 0;

    for(int i=0; i<sx; i++){
        if(X[i] <= sum){
            int a = lower_bound(Y, Y+sy, sum-X[i])-Y;
            int b = upper_bound(Y, Y+sy, sum-X[i])-Y;

            count += b-a;
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
