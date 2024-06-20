// number of distinct elements in the range [l,r]

get prev idx vector for the array and then 
 # of distinct in (l,r) = # of values<=l-1 in (l,r) for the prev array

 arr = {4,2,3,4,4,5,6,2,3,4}

 get_prev = {-1,-1,-1,0,3,-1,-1,1,2,4} apple <=li1 in this 


 // LIS type build 0,1 array from start and update as we travel

-> find longest subsequence with abs(ai-ai+1)<=d 
same as LIS


// storing in node

1) max sum subarray in range
2) longest consecutive subarray in range
