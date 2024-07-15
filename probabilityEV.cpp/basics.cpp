https://codeforces.com/blog/entry/62690
https://codeforces.com/blog/entry/62792
https://www.codechef.com/wiki/tutorial-expectation


E(X=x) = P(x)*x 

E(X) -> sum (P(x)*x)

linearity of expectation -> E(X+Y) = E(X)+E(Y)     // most important

-> hat problem
-> balls and bins problem
-> coupon collector problem

// use contribution technique

Problems -> 

// if a dice has m faces and probability of getting each face is 1/m. the dice is thrown n times find the EV of max number on the dice.

P(i) -> probability that i is max among all n throws -> (i^m - (i-1)^m) / m^n

E(X) ->  sum (i*P(i)) for i<=m 

//  You are given a sequence of N distinct numbers. We have to choose one of 2^N - 1 non-empty subsets, uniformly at random. Find EV of the difference between the maximum and minimum element in the subset.


Lets sort the given array.
After sorting,
A1, A2, …. Ai,......, An

for an element Ai.
If in some nonempty subset, Ai is the maximum element, then its contribution will be Ai.
If in some nonempty subset, Ai is the minimum element, then its contribution will be -Ai.

Next step is,
Finding the probability that Ai is the maximum (or minimum) element in some chosen subset.

P_max(i) = 2^(i-1)/(2^n -1)
Any element with index < i can be chosen in the subset


P_min(i) = 2^(n-i)/ (2^n - 1)
Any element with index > i can be chosen in the subset

for(int i=1;i<=n;i++)
{
    Ans += 2^(i-1)/(2^n -1)*A[i];
    Ans -= 2^(n-i)/ (2^n - 1)*A[i];
}


// You are given beads of m colours. For each colour, there are infinite number of beads for each colour . You have to make a necklace of n beads using these beads. Find the expected number of distinct colours in the necklace.

P(i) = Probability that colour i is present in the necklace
Xi = 0 if colour i is not present and 1 if colour i is present

E(X) = summation (P(i)*1)

P(i) = same for all i

E(X) = m*P(i)
        = m*(1- P’(i))

P’(i) = (m-1)^n / (m^n) // probability that colour i is not present

E(X) = m*(1- (m-1)^n / (m^n)) 


// You are given a random number generator that generates an integer from 1 to N uniformly at random at each turn. It will stop generating once k distinct elements have been generated. Find the expected number of turns. Let k<=105







