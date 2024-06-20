#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pp pair<int,int>
#define pl pair<ll,ll>
#define F first
#define S second
int mod = 1e9 + 7;

void print(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ld dp[3005][3005];

// ld compute(int coin, vector<ld>& pr, int n) {
//     if (coin >= pr.size()){
//         if(n==0) return 1.0;
//         else return 0.0;
//     }
//     if (dp[coin][n] != -1.00) return dp[coin][n];

//     ld head=0.0;

//     if(n>=1) head = pr[coin] * compute(coin + 1, pr, n - 1);
//     ld tail = (1.0 - pr[coin]) * compute(coin + 1, pr, n);

//     return dp[coin][n] = head + tail;
// }

void solve() {
    int n;
    cin >> n;

    vector<ld> pr(n);
    for (int i = 0; i < n; i++) cin >> pr[i];

    vector<vector<ld>> dp(n+1,vector<ld>(n+1,0.0));

    dp[0][0]=1.00;
    dp[1][0]=1.00-pr[0];
    for(int i=2;i<=n;i++){
        dp[i][0]=dp[i-1][0]*(1.0-pr[i-1]);
    }

    

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j>i) dp[i][j]=0.0;
            else{
                dp[i][j]+=dp[i-1][j-1]*(pr[i-1]);
                dp[i][j]+=dp[i-1][j]*(1.00-pr[i-1]);
            }
        }
    }
    int N = (n / 2) + 1;
    ld ans = 0.0;
    for (int i = N; i <= n; i++) {
        ans += dp[n][i];
    }

    cout <<fixed<<setprecision(10)<< ans << endl;  // Set precision for output
}

int main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << elapsed.count() * 1e-9 << " seconds" << endl;

    return 0;
}

// Don't make it complex, make it simple
// Look for extremities
// Generalize the approach
// Reverse Engineering
// Elimination
// Imaginative
// Think Opposite
// Diagram
// Observation
