//starting from any node travel each node only once and return to the starting node at the end. find the min cost for this trip

// given a complete graph in the form of a adj matrix

int dp[20][1<<20]

int solve(int city,int mask,int start){
    if(mask==(1<<N)-1){
        return dis[city][start];
    }

    if(dp[city][mask]!=-1) return dp[city][mask];

    int ans=1e9;

    for(int i=0;i<N;i++){
        if(mask&(1<<i)) continue;
        ans=min(ans,dis[city][i]+solve(i,mask|(1<<i),start));
    }

    return dp[city][mask]=ans;
}

// only one call is needed as it is circular


// Print TSP Path / Permutation


