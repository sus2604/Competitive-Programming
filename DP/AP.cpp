long long int countOfAPSubsequence(int N, int a[]){
        vector<map<int, int>> dp(N);
        for(int i=1; i<N; i++){
            for(int j=0; j<i; j++){
                int diff = a[i] - a[j]; 
                
                dp[i][diff] +=  1;
                if(dp[j].count(diff))
                    dp[i][diff] += dp[j][diff];
            }
        }
        long long ans  = 0;
        for(int i=0; i<N; i++){
            for(auto ele: dp[i])
                ans += ele.second;
            
        }
        return ans+N;    
    }
    int longestArithSeqLength(vector<int>& nums) {
        int len=nums.size();
        if(len==2) return 2;
        vector<unordered_map<int,int>> dp(len);
        int max_ans=0;
        for(int i=1;i<len;i++){
            for(int j=0;j<i;j++){
                int diff=nums[i]-nums[j];

                if(dp[j].find(diff)!=dp[j].end()){
                    dp[i][diff]=dp[j][diff]+1;
                }
                else{
                    dp[i][diff]=2;
                }
                max_ans=max(max_ans,dp[i][diff]);
            }
        }
        return max_ans;
    }


    void solve() {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<vector<map<int,int>>> dp(n,vector<map<int,int>>(n+1));    // dp[i][j] -> map of cd -> # of sequences ending at i of length j
        
        for(int i=0;i<n;i++){
            dp[i][1][0] ++;
        }

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int d = a[j] - a[i];
                dp[j][2][d] ++;
            }
        }

        for(int i=1;i<n;i++){
            for(int j=3;j<=n;j++){
                for(int k=0;k<i;k++){
                    if(dp[k][j-1].find(a[i]-a[k]) != dp[k][j-1].end()){
                        dp[i][j][a[i]-a[k]] += dp[k][j-1][a[i]-a[k]];
                        dp[i][j][a[i]-a[k]] %= mod;
                    }
                }
            }
        }

        vector<int> ans(n+1,0);

        for(int i=0;i<n;i++){
            for(int j=1;j<=n;j++){
                for(auto itr = dp[i][j].begin(); itr!=dp[i][j].end();itr++){
                    ans[j] += itr->second;
                    ans[j] %= mod;
                }
            }
        }

        for(int i=1;i<=n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }


int memo[MxN][MxN][MxN][MxN];

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x : a)
        cin >> x;   

    memset(memo, -1, sizeof(memo));
    auto dfs = [&] (auto &&self, int i, int one, int two, int k) ->int {
        if (k <= 0)
            return 1;

        if (i >= n) 
            return 0;

        if (memo[i][one][two][k] != -1)
            return memo[i][one][two][k];

        int ways = 0;
        if (a[i] - a[one] == a[one] - a[two]) {
            ways += self(self, i + 1, i, one, k - 1);
            ways %= mod;
        }
        
        ways += self(self, i + 1, one, two, k);
        ways %= mod;

        return memo[i][one][two][k] = ways;
    };

    for (int k = 1; k <= n; ++k) {
        int ways = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ways += dfs(dfs, j + 1, j, i, k - 2);
                ways %= mod;
            }
        }
        cout << (k == 1 ? n : ways) << " ";
    }
} 

