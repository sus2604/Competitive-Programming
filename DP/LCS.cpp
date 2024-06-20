int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>> dp(n1+1,vector<int> (n2+1));

        dp[0][0]=0;
        for(int i=1;i<=n1;i++) dp[i][0]=0;
        for(int j=1;j<=n2;j++) dp[0][j]=0;

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(text1[i-1]==text2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else{
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[n1][n2];
}

// print

int len=dp[m][n];

string str="";

int i=m,j=n;

while(i>0 and j>0){
    if(text1[i-1]==text2[j-1]){
        str.push_back(text1[i-1]);
        i--;
        j--;
    }
    else if(dp[i-1][j]>dp[i][j-1]) i--;
    else j--;
}

reverse(str.begin(),str.end());