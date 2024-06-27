vector<int> subtract(vector<int>& x,vector<int>& y){          // x-y
    reverse(x.begin(),x.end());                             // x-> bigger string  y-> smaller string
    reverse(y.begin(),y.end());
    vector<int> ans;
    int len=y.size();

    for(int i=0;i<len;i++){
        if(x[i]<y[i]){
            x[i+1]--;
            ans.push_back(10+x[i]-y[i]);
        }
        else{
            ans.push_back(x[i]-y[i]);
        }
    }
    if(x.size()>len){
        for(int i=len;i<x.size();i++){
            if(x[i]<0){
                x[i+1]--;
                ans.push_back(10+x[i]);
            }
            else{
                ans.push_back(x[i]);
            }
        }
    }
    reverse(ans.begin(),ans.end());

    int i=0;
    vector<int> result;
    while(ans[i]==0){
        i++;
    }
    for(;i<ans.size();i++){
        result.push_back(ans[i]);
    }

    return result;
}

// bool isSmaller(string str1, string str2)
// {
//     // Calculate lengths of both string
//     int n1 = str1.length(), n2 = str2.length();
 
//     if (n1 < n2)
//         return true;
//     if (n2 < n1)
//         return false;
 
//     for (int i = 0; i < n1; i++)
//         if (str1[i] < str2[i])
//             return true;
//         else if (str1[i] > str2[i])
//             return false;
 
//     return false;
// }

// if (isSmaller(str1, str2))
//         swap(str1, str2);