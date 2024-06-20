Given an array of digits which is sorted in non-decreasing order. You can write numbers using each digits[i] as many times as we want. For example, if digits = ['1','3','5'], we may write numbers such as '13', '551', and '1351315'.

Return the number of positive integers that can be generated that are less than or equal to a given integer n.

class Solution {
public:
    int dp[10][2][2];
    int solve(vector<int>& arr,vector<int>& num,int pos,int tight,int lz){
        int n=arr.size();
        if(pos==num.size()){
            return 1;
        }
        if(dp[pos][tight][lz]!=-1){
            return dp[pos][tight][lz];
        }

        int ans=0;

        if(tight==1){
            if(lz) ans+=solve(arr,num,pos+1,0,1);
            for(int i=0;i<n;i++){
                if(arr[i]<num[pos]){
                    ans+=solve(arr,num,pos+1,0,0);
                }
                else if(arr[i]==num[pos]){
                    ans+=solve(arr,num,pos+1,1,0);
                }
            }
        }
        else{
            if(lz==1) ans+=solve(arr,num,pos+1,0,1);
            for(int i=0;i<n;i++){
                ans+=solve(arr,num,pos+1,0,0);
            }
        }

        return dp[pos][tight][lz]=ans;
        
    }

    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        vector<int> arr;
        for(int i=0;i<digits.size();i++){
            arr.push_back(stoi(digits[i]));
            
        }
        vector<int> num;
        while(n){
            num.push_back(n%10);
            n/=10;
        }
        reverse(num.begin(),num.end());
        memset(dp,-1,sizeof(dp));
        return solve(arr,num,0,1,1)-1;     
                                           
    }
};