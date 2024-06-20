manhattan distance = abs(x-xi)+abs(y-yi);

1) given a set of points find the max/min manhattan distance between any two points

abs(xi-xj)+abs(yi-yj) = (xi+yi)-(yi+yj)
                        (xj+yj)-(xi+yi)
                        (xi-yi)-(xj-yj)
                        (xj-yj)-(xi-yi)

=> just make two arrays for sum and diff and sort it and find the diff between first and last elements


2) find the point to meet such that it cost least number of operations and find the number of such points
-> operations -> l,r,u,d

let the point be (X,Y)

sum(abs(X-xi)+abs(Y-yi)) = sum(abs(X-xi))+sum(abs(Y-yi))

// draw mod graph to justify (the slope changes by 2 after each intersection point)
if N -> odd we will find only one point where min will occur
else N -> even we will find multiple points

make 2 arrays for x and y coordinates and sort the arrays
if odd -> find the median(mid element) from both the arrays -> that is the reqd point
else even -> find the two mid points for both the arrays combination for any points in between gives the reqd point


3) given a query find the sum manhattan distance for each query

-> use binary search and prefix sums to get the answer in log(N) time.

4) given N points and q queries(point (x,y)) for which tell the point (out of N points) with the shortest manhattan distance

-> similar to first problem by making two arrays of diff and sum