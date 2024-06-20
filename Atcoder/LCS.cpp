#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s, t;
    cin >> s >> t;

    int m = s.size();
    int n = t.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    string ans;
    int i = m, j = n;
    while(i > 0 && j > 0){
        if(s[i - 1] == t[j - 1]){
            ans.push_back(s[i - 1]);
            i--;
            j--;
        } else {
            if(dp[i - 1][j] > dp[i][j - 1]) i--;
            else j--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto begin = chrono::high_resolution_clock::now();

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    cerr << elapsed.count() * 1e-9 << " seconds" << endl;
    return 0;
}
