// all digits distinct

class Solution {
public:
    int dp[20][2][2][1<<10];
    int solve(vector<int>& digits,int pos,int tight,int lz,int mask){
        if(pos==digits.size()) return 1;

        if(dp[pos][tight][lz][mask]!=-1) return dp[pos][tight][lz][mask];

        int ans=0;

        int ub=(tight)?digits[pos]:9;

        if(tight==1){
            if(lz){
                for(int i=0;i<=digits[pos];i++){
                    if(i==0) ans+=solve(digits,pos+1,0,1,mask);
                    else if(i<digits[pos]){
                        ans+=solve(digits,pos+1,0,0,mask|(1<<i));
                    }
                    else if(i==digits[pos]){
                        ans+=solve(digits,pos+1,1,0,mask|(1<<i));
                    }
                }
            }
            else{
                for(int i=0;i<=digits[pos];i++){
                    if(mask&(1<<i)) continue;
                    if(i<digits[pos]){
                        ans+=solve(digits,pos+1,0,0,mask|(1<<i));
                    }
                    else if(i==digits[pos]){
                        ans+=solve(digits,pos+1,1,0,mask|(1<<i));
                    }
                }
            } 
        }
        else{
            if(lz){
                for(int i=0;i<=9;i++){
                    if(i==0) ans+=solve(digits,pos+1,0,1,mask);
                    else {
                        ans+=solve(digits,pos+1,0,0,mask|(1<<i));
                    }
                }
            }
            else{
                for(int i=0;i<=9;i++){
                    if(mask&(1<<i)) continue;
                    ans+=solve(digits,pos+1,0,0,mask|(1<<i));
                }
            }
        }

        

        return dp[pos][tight][lz][mask]=ans;
    }
    int countSpecialNumbers(int n) {
        // bitmasking

        vector<int> digits;

        while(n){
            digits.push_back(n%10);
            n/=10;
        }
        reverse(digits.begin(),digits.end());

        memset(dp,-1,sizeof(dp));


        return solve(digits,0,1,1,0)-1;  // excluding zero

    }
};

// leading zero and add 0 ko bahar rakho dig vale loop se

// aur dig vale mein bas chcek rakho ki lz==0 aur (lz==1 and dig!=0)

int dp[20][2][2][1<<10];
    int solve(vector<int>& digits,int pos,int tight,int lz,int mask){
        if(pos==digits.size()) return 1;

        if(dp[pos][tight][lz][mask]!=-1) return dp[pos][tight][lz][mask];

        int ans=0;

        int ub=(tight)?digits[pos]:9;

        if(lz) ans+=solve(digits,pos+1,0,lz,mask);

        for(int dig=0;dig<=ub;dig++){
            if(lz and dig!=0){
                ans+=solve(digits,pos+1,tight&(dig==ub),lz&(dig==0),mask|(1<<dig));
            }
            else if(lz==0){
                if(mask&(1<<dig)) continue;
                ans+=solve(digits,pos+1,tight&(dig==ub),lz&(dig==0),mask|(1<<dig));
            }
        }

        return dp[pos][tight][lz][mask]=ans;
    }