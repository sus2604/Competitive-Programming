AP GP queries


// answer q queries of the form a[l]+2*a[l+1]+3*a[l+2]+........+(r-l+1)*a[r]  for q[l...r]
sum[l...r] (i-l+1)*a[i]

=>  sum[l...r] i*a[i]  + sum[l....r] (1-l)*a[i]

let b[i]=a[i]*i  therfore sum[l...r] i*a[i]  = sum[l...r] b[i] 


// answer q queries of the form a[l]+k*a[l+1]+k^2*a[l+2]+........+k^(r-l)*a[r]  for q[l...r]


sum k^(i-l)*a[i]

=>  k^(-l) sum k^i*a[i]

let b[i]=a[i]*k^i  same as above

// a[l]+=A
// a[l+1]+=A+D
// a[l+2]+=A+2*D
.
.
.
// a[r]+=A+(r-l)*D

// find the final array after all the operations

a[i] += A+(i-l)*D

a[i] += (A-l*D) + i*D     // b and c are copies of a

a[i] = b[i] + c[i]*i   -> add (A-L*D) in partial fashion to b and add D in partial fashion to c
                       -> now combine a[i] = b[i] + c[i]*i


// a[l]+=A
// a[l+1]+=A*k
// a[l+2]+=A*k^2
.
.
.
// a[r]+=A*k^(r-l)

// find the final array after all the operations


a[i] += A*k^(i-l)   //cannot seperate

// for this tweek prefix idea a bit 

vector<int> a(n,0);

a[1]=a;

for(int i=1;i<n;i++){
    a[i]+=a[i-1]*r;
}

// so just do this   add A to l  and subtract  a^(r-l+1) from a[r+1] 




for 2D partial sum just do this


// L R U D

p[U][l]+=X
p[U][R+1]-=X 
p[D+1][L]-=X 
p[D+1][R+1]+=X 


