// palindromic substring

vector<vector<bool>> dp(n,vector<bool>(n,false));

for(int k=0;k<n;k++){
    for(int i=0,j=i+k;i<n and j<n;i++,j++){
        if(i==j) dp[i][j]=true;
        else if(j=i+1) dp[i][j]=(str[i]==str[j]);
        else{
            dp[i][j]= (str[i]==str[j] and dp[i+1][j-1]);
        }
    }
}