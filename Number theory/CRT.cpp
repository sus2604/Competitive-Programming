// chinese remainder theorem

find the least number such it gives remainder r1 and r2 with p1 and p2 respectively

let x be the number

-> 0 <= x < p1*p2


for(int i=0;i<p1*p2;i++){
    if(i%p1==r1 and i%p2==0){
        cout<<i<<endl;
    }
}

// x = r1+m*p1  and x = r2+n*p2 and also x<p1*p2

-> we iterate on m

for(int m=0;r1+p1*m<p1*p2;m++){
    if((r1+p1*m)%p2==r2){
        cout<<r1+p1*m<<endl;
    }
}

// r1 + k*p1 = r2 mod p2;

// k*p1 = (r2-r1) mod p2;

// k = (r2-r1)p1^-1 mod p2;

// k = (r2-r1) inv(p1) mod p2  inv(p1) = p1 ^ p2-2 mod p2

ll k = ((r2-r1)*inverse(p1,p2))%p2;

if(k<p2) k+=p2;

cout<<r1+k*p1<<endl;


find x such that a^x mod p = b given a b and p p<=1e9
1<=a<p 1<=b<p

using cyclicity in fermats theorem 

int current=1;
for(int x=0;x<=p-2;x++){
    if(current==b){
        cout<<x<<endl;
    }
    current=(current*a)%p;
}

// optimized using square root decomposition

x can be represented as r*root(p)+q
root(p) -> number of blocks
r -> block number ->   0<=r<=floor(p/root(p))
q -> number of items inside each box  0<=q<=root(p)

unordered_map<ll,ll> r_value;

ll Z=floor(sqrt(p));

for(int r=0;r<=p/Z;r++){
    r_value[power(a,r*Z)]=r;
}
ll X=-1;                             // O(root(p)*log(p))
for(int q=0;q<Z;q++){
    ll e=power(inverse(a),q);
    ll lhs=(b*e)%p;
    if(r_value.find(lhs)!=r_value.end()){
        X=r_value[lhs]+Z+q;
        break;
    }
}

if(X==-1) cout<<"not Found"
else cout<<X;

//can be further optimized by storing power in advance to reduce log(p)



