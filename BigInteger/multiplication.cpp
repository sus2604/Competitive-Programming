vector<int> multiply(vector<int> x,vector<int> y){
    reverse(x.begin(),x.end());
    reverse(y.begin(),y.end());
    vector<int> ans(x.size()+y.size(),0);
    int s=0;
    int k=s;
    for(int i=0;i<y.size();i++){
        int carry=0;
        for(int j=0;j<x.size();j++){
            int prod=y[i]*x[j]+carry+ans[k];
            carry=prod/10;
            ans[k]=(prod%10);
            k++;
        }
        while(carry){
            ans[k]=carry%10;
            carry/=10;
            k++;
        }
        s++;
        k=s;
    }

    reverse(ans.begin(),ans.end());
    vector<int> result;
    int i=0;
    while(ans[i]==0)i++;
    for(;i<ans.size();i++){
        result.push_back(ans[i]);
    }
    return result;
}