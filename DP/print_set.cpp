
bool solve(vector<int>& arr,int idx,int left){
    if(left==0) return true;

    if(idx>=arr.size()) return false;

    if(dp[idx][left]!=-1) return dp[idx][left];

    bool ans = solve(arr,idx+1,left) || solve(arr,idx+1,left-arr[idx]);

    return dp[idx][left]=ans;
}

void print(vector<int>& arr,int idx,int left){           // printing using recheck
    if(idx>=arr.size()){
        return;
    }

    if(solve(arr,idx+1,left)){
        print(arr,idx+1,left);
    }
    else if(solve(arr,idx+1,left-arr[idx])){
        cout<<arr[idx]<<" ";
        print(arr,idx+1,left-arr[idx]);
    }
}


// using back pointers


vector<int> dp(sum+1,0);   // 0-> for not possible


for(int i=0;i<n;i++){
    for(int j=sum;j>=arr[i];j--){
        if(dp[j]) continue;
        if(dp[j-arr[i]]!=0){
            dp[j]=arr[i];
        }
    }
}

if(dp[sum]==0) cout<<-1<<endl;
else{
    int i=sum;
    while(i>0){
        cout<<dp[i]<<" ";
        i-=dp[sum];
    }
}
