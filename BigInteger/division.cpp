vector<int> divide(vector<int> x,int d){
    vector<int> ans;
    long long rem=0;
    for(int i=0;i<s.size();i++){
        if(rem){
            rem=rem*10+x[i];
            ans.push_back(rem/d);
            rem=rem%d;
        }
        else{
            if(x[i]<d){
                rem+=x[i];
                ans.push_back(0);
            }
            else{
                rem=x[i]%d;
                ans.push_back(x[i]/d);
            }
        }
    }
    vector<int> result;
    int i=0;
    while(ans[i]==0){
        i++;
    }
    for(;i<ans.size();i++){
        result.push_back(ans[i]);
    }
    return result;
}