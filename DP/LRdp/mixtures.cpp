// SPOJ

-> for any DP problem look at how the answer is created for the first or last element


// look at the final state at last we have a single container -> comes from two other containers


int solve(int i,int j){
    if(i>=j) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int smoke=1e9;

    for(int k=i;k<=j;k++){
        smoke=min(smoke,solve(i,k)+solve(k+1,j)+sum(i,k)+sum(k+1,j));
    }
    return dp[i][j]=smoke;
}

    vector<int> pre(n);
    pre[0]=ar[0];
    for(int i=1;i<N;i++) pre[i]=pre[i-1]+a[i];

    vector<vector<int>> dp(n,vector<int>(n,0));

    for(int m=0;m<n;m++){
        for(int i=0,j=m+i;i<n and j<n;i++,j++){
            if(i==j) dp[i][j]=a[i];
            else if(i+1==j) dp[i][j]=a[i]+a[j];
            else{
                for(int k=i;k<j;k++){
                    int cost=sum(i,k)+sum(k+1,j);
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+cost);
                }
            }
        }
    }







