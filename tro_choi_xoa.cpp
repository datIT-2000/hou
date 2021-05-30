#include <bits/stdc++.h>
using namespace std;

int n;
int64_t dp[5001][5001];

int main()
{
    cin >> n;
    vector<int64_t> a(n), pre(n+1,0);
    for(auto &i:a) cin >> i;
    for(int i=1; i<=n; ++i)
    {
        pre[i]=pre[i-1]+a[i-1];
        dp[i][i]=a[i-1];
    }
    for(int i=1; i<n; ++i)
    {
        for(int j=1; j<=n; ++j)
        {
            if(i+j>n)break;
            dp[j][i+j] = max(pre[i+j]-pre[j-1]-dp[j][i+j-1],
                             pre[i+j]-pre[j-1]-dp[j+1][i+j]);
        }
    }
    cout << dp[1][n];
    return 0;
}
