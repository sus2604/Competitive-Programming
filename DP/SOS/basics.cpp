// ek mask se related saare subsets ka sum nikal na

// eg -> given a array of integers of size 2^N N<=18. find for all i, i&j=j and add arr[j].

// brute force

for(int mask = 0;mask < (1<<N); ++mask){            // O(4^N)
	for(int i = 0;i < (1<<N); ++i){
		if((mask&i) == i){
			F[mask] += A[i];
		}
	}
}

// better approach 


for (int mask = 0; mask < (1<<n); mask++){            // O(3^N)
	F[mask] = A[0];
    for(int i = mask; i > 0; i = (i-1) & mask){
    	F[mask] += A[i];
    }
}


// optimal approach

dp[i][mask] -> sum of all subsets of mask such that we can change only first i bits

(11101,3) -> (00001,01001,10001,11001) (00101,01101,10101,11101)
=>  (11101,3) -> (11001,2) + (11101,2)  
-> if ith bit is set -> (mask,i) = (mask,i-1)+(mask^(1<<i),i-1)

-> if ith bit is unset ->  (mask,i) = (mask,i-1)


// O(N*2^N)

(mask,0) -> arr[mask]

// iterative

int dp[(1<<N)][N+1];
for(int mask=0;mask<(1<<N);mask++){
    dp[mask][0]=arr[mask];
}

for(int mask=0;mask<(1<<N);mask++){
    for(int i=1;i<=N;i++){
        if(mask&(1<<(i-1))){
            dp[mask][i]=dp[mask][i-1]+dp[mask^(1<<(i-1))][i-1];
        }
        else dp[mask][i]=dp[mask][i-1];
    }
}



for(int mask=0;mask<(1<<N);mask++){
    cout<<dp[mask][N]<<" ";
}

// memory optimized code

for(int i = 0; i<(1<<N); i++) F[i] = A[i];
	
for(int bit=0;bit<N;bit++){
    for(int mask=0;mask<(1<<N);mask++){             // sum over subsets
        if(mask & (1<<bit)){
            F[mask] += F[mask^(1<<bit)];
        }
    }
} 


// think it as prefix, you fix a bit to flip and add answer for the flipped mask

for(int i=0;i<(1<<N);i++) F[i]=A[i];
for(int i=0;i<N;i++){
    for(int mask=(1<<N)-1;i>=0;i--){              // sum over super-sets
        if(mask&(1<<bit)){
            F[mask^(1<<bit)]+=F[mask];
        }
    }
}

// 1) har ek mask ke liye jo bhi array ka index mask ka subset ho usks sum nikal na h
// 2) har ek mask/query ke liye find number of elements in the array that are subsets of the mask -> for this we create a freq array and do the same



// bit problem CSES
// atcoder 349f similar to AND = k problem


// for AND -> supersets
// for OR -> subsets
