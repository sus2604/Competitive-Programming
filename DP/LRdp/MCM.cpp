// look at the last state to merge

int matrixMultiplication(int n, int arr[])
    {
        vector<vector<int>> mat;
        for(int i=0;i<n-1;i++){
            mat.push_back({arr[i],arr[i+1]});
        }
        int size=mat.size();
        
        vector<vector<int>> dp(size,vector<int>(size,1e9));
        
        for(int m=0;m<size;m++){
            for(int i=0,j=m+i;i<size and j<size;i++,j++){
                if(i==j) dp[i][j]=0;
                else if(i+1==j) dp[i][j]=mat[i][0]*mat[i][1]*mat[j][1];
                
                else{
                    for(int k=i;k<j;k++){
                        int cost=mat[i][0]*mat[k][1]*mat[j][1];
                        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+cost);
                    }
                }
            }
        }
        
        return dp[0][size-1];
        
        
    }