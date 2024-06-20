// need to go from city 1 to city n such that you cover every city once. find the number of ways

int solve(int city,int mask){
    if(mask==(1<<N)-1){
        if(city==N) return 1;
        else return 0;
    }
    if(dp[city][mask]!=-1) return dp[city][mask];

    int ans=0;
    for(int i=0;i<n;i++){
        if(mask&(1<<i)) continue;
        ans+=solve(i,mask|(1<<i));
    }

    return dp[city][mask]=ans;
}

// count of hamiltonian cycles

just change the base case if from the end we can reach the start ie there exist an edge between start and node -> 1


// given a directed graph with n nodes find minimum nodes to be deleted to form a DAG.

every DAG has atleast 1 topo order
in a topo order every edge is in a forward direction
create a topo order

deleting cycles = creating topo order (which is just a permutation with forward edges)

// arr[i][j] stores the number pf edges going from i->j


int solve(int pos,int mask){
    if(pos==n+1){
        return 0;
    }

    if(dp[pos][mask]!=-1) return dp[pos][mask];

    int ans=1e9;
    for(int i=0;i<n;i++){
        if(mask&(1<<i)) continue;

        int temp=0;

        for(int j=0;j<n;j++){
            if(mask&(1<<j)) temp+=arr[i][j];
        }

        ans=min(ans,solve(pos+1,mask|(1<<i))+temp);
    }

    return dp[pos][mask]=ans;
}

