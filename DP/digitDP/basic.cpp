// given a range [l,r] find the sum of all digits between l and r
//l<=r<=10^18

G(x) = [1,x] gives the sum of all digits between 1 and x

therefore solution = G(r)-G(l-1)

-> tight=1(restriction)
-> tight=0(no restriction) (0-9)

-> sum -> sum till now    sum(n)=sum(n-1)+sum of digits(n)
-> pos -> curr index

tight=2;
pos=20 (as max digits can be 18)
sum=20*9=180 (max sum possible)   9 9 9 9 9 9 9 9 9 9 9 ....

// digit dp on sum

int dp[20][2][180];

int solve(vector<int> digits,int pos,int tight,int sum){
    if(pos==digits.size()){
        return sum;
    }
    else if(dp[pos][tight][sum]!=-1) return dp[pos][tight][sum];

    int ans=0;
    int ub=(tight)?digits[pos]:9;

    for(int dig=0;dig<=ub;dig++){
        ans+=solve(digits,pos+1,(tight&(dig==ub)),sum+dig);
    }
    return dp[pos][tight][sum]=ans;
}

int l,r;
cin>>l>>r;
vector<int> digits_l;
vector<int> digits_r;
l=l-1;
while(l){
    digits_l.push_back(l%10);
    l/=10;
}
while(r){
    digits_l.push_back(r%10);
    r/=10;
}
reverse(digits_l.begin(),digits_l.end());
reverse(digits_r.begin(),digits_r.end());

memset(dp,-1,sizeof(dp));

int ans1=solve(digits_r,0,1,0);

memset(dp,-1,sizeof(dp));

int ans2=solve(digits_l,0,1,0);

return ans1-ans2;


// in the state of the digit dp problems -> tight -> pos -> lz -> store string -> sum -> count -> prev_num





