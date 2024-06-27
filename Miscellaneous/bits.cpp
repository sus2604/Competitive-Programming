AND - any 0 -> 0
      else -> 1

OR - any 1 -> 1
     else -> 0

XOR - even 1 -> 0
      odd 1 -> 1

//  XOR PROPERTIES

a^a=0
a^0=a
a^b=b^a 


for consecutive xor

1^2^3^4^5^6^...........^n = for no = 4n+1 -> 1
                                     4n+2 -> no+1
                                     4n+3 -> 0
                                     4n   -> no

xor of all subsets of a set is always = 0

for range query
l^l+1^l+2^............^r-1^r  // l and r inclusive

ans= xor(r)^xor(l-1)

where xor(i)=1^2^3^4^.......^i

xor swapping

a=a^b;
b=a^b;
a=a^b; 

xor applications
-> find missing nummber
-> find duplicate number


a^b=c this implies  a^b^c=0 and a^c=b and b^c=a

min no of flips required to convert a to b =  no of set bits in a^b

a<=b<=c   ->  either a^b < a^c  or b^c < a^c 
=> a^c cannot be less then both a^b and b^c

GENERAL PROPERTIES

(a+b)=(a^b)+2*(a&b)    // (a+b) = (a^b) + (a&b)<<1
 a+b = a|b + a&b
 a | b = a^b + a&b

 distributive property -> a&(b|c) = (a&b)|(a&c)
                       -> a&(b^c) = (a&b)^(a&c)
                       -> a|(b&c) = (a|b)&(a|c)

a^(a&b) = (a|b)^b
b^(a&b) = (a|b)^a
(a&b)^(a|b) = a^b

a-b = (a^(a&b))-((a|b)^a)
a-b = ((a|b)^b)-((a|b)^a)
a-b = (a^(a&b))-(b^(a&b))
a-b = ((a|b)^b)-(b^(a&b))

// int rangeBitwiseAnd(int left, int right) {
//         int count = 0;

//         int ans = right;

//         while(left!=right){
//             left>>=1;
//             right>>=1;

//             count++;
//         }

//         return right<<count;
//     }