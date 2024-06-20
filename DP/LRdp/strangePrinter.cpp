class Solution {
public:
    #define F first
    #define S second
    int dp[105][105][105];
    int solve(int l,int r,int extra,vector<pair<char,int>>& groups){
        if(l>r) return 0;
        if(dp[l][r][extra]!=-1) return dp[l][r][extra];


        int ans=1+solve(l+1,r,0,groups);
        for(int i=l+2;i<=r;i++){
            if(groups[i].F==groups[l].F){
                ans=min(ans,solve(l+1,i-1,0,groups)+solve(i,r,groups[l].S+extra,groups));
            }
        }

        return dp[l][r][extra]=ans;
    }
    int strangePrinter(string s) {
        int n=s.size();

        vector<pair<char,int>> groups;
        for(int i=0;i<n;i++){
            int size=1;
            char val=s[i];
            while(i+1<n and s[i]==s[i+1]){
                size++;
                i++;
            }
            groups.push_back({val,size});
        }

        memset(dp,-1,sizeof(dp));

        return solve(0,groups.size()-1,0,groups);
    }
};