// delete a palindrome substring from the string


int dp[101][101];
int rec(int l, int r){
    if(l>r)return 0;
    if(l==r)return 1;

    if(dp[l][r]!=-1)return dp[l][r];
    int ans=1+rec(l+1,r);
    if(a[l+1]==a[l])ans=min(ans,1+rec(l+2,r));
    for(int mid=l+2; mid<=r; mid++){
        if(a[mid]==a[l]){
            ans=min(ans,rec(l+1,mid-1)+rec(mid+1,r));
        }
    }
    return dp[l][r]=ans;
}