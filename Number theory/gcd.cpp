int gcd(int a,int b){  //a>b
    if(b==0) return a;

    return gcd(b,a%b);
}

// to solve ax+by=g  g=gcd(a,b)

int solve(int a,int b,int &x,int &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }

    int x1,y1;
    int d=solve(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);

    return d;
}

// imp point to remember ->  a%b <= a/2