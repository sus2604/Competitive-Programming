vector<int> add(vector<int> x,vector<int> y){
    int len=min(x.size(),y.size());
    reverse(x.begin(),x.end());
    reverse(y.begin(),y.end());
    vector<int> ans;
    int carry=0;
    for(int i=0;i<len;i++){
        int val=x[i]+y[i]+carry;
        carry=val/10;
        ans.push_back(val%10);
    }
    if(x.size()>len){
        for(int i=len;i<x.size();i++){
            int val=x[i]+carry;
            carry=val/10;
            ans.push_back(val%10);
        }
    }
    if(y.size()>len){
        for(int i=len;i<y.size();i++){
            int val=y[i]+carry;
            carry=val/10;
            ans.push_back(val%10);
        }
    }
    while(carry){
        ans.push_back(carry%10);
        carry/=10;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}