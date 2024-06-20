#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<long long> dp(k+1,0);
    vector<long long> pre(k+1,1);

    // dp[i][j] -> # of ways to give j presents to i kids

    dp[0]=1;
    for(int i = 1; i <= n; i++) {
        vector<long long> ndp(k+1);
        vector<long long> npre(k+1);
        ndp[0]=1;
        npre[0]=1;
        for(int j = 1; j <= k; j++) {
            int l = max(0,j-a[i - 1]);
            ndp[j] = ((pre[j] - (l > 0 ? pre[l - 1] : 0)+mod))%mod;

            npre[j] = (npre[j - 1] + ndp[j])%mod;
        }
        dp=ndp;
        pre=npre;
    }

    cout << dp[k] << endl;
    return 0;
}
