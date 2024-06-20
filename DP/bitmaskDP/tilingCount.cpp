// CSES count tilings


dp(i,mask) -> number of ways to fill the grid from ith col to mth col given that some positions are already filled

int dp[1001][1<<11];

void generate_next_masks(int current_mask, int i, int next_mask, int n, vector<int>& next_masks){
      if(i == n + 1){
        next_masks.push_back(next_mask);
        return;
      }
      
      if((current_mask & (1 << i)) != 0)
          generate_next_masks(current_mask, i + 1, next_mask, n, next_masks);
      
      if(i != n)
        if((current_mask & (1 << i)) == 0 && (current_mask & (1 << (i+1))) == 0)
          generate_next_masks(current_mask, i + 2, next_mask, n, next_masks);       // vertical 
      
      if((current_mask & (1 << i)) == 0)
          generate_next_masks(current_mask, i + 1, next_mask + (1 << i), n, next_masks);     // horizontal
}


int solve(int col,int mask,const int m,int n){
    if(col==m+1){
        if(mask==0) return 1;
        return 0;
    }

    if(dp[col][mask]!=-1) return dp[col][mask];
    int ans=0;

    vector<int> next_masks;

    generate_next_masks(mask,1,0,n,next_masks);

    for(int next_mask:next_masks){
        ans+=solve(col+1,next_mask,m,n);
    }

    return dp[col][mask]=ans;
}

memset(dp,-1,sizeof(dp));

solve(1,0,m,n);



