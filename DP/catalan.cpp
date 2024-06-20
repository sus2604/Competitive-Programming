// variations

C(n) = C(0)*C(n-1) + C(1)*C(n-2) + C(2)*C(n-3) + ....... + C(n-1)*C(0)

int findCatalan(int n) {
    vector<int> ans(n + 1);
    ans[0] = 1;
    ans[1] = 1;

    for (int i = 2; i <= n; ++i) {
        ans[i] = 0;
        for (int j = 0; j < i; ++j) {
            ans[i] = (ans[i]+(ans[j]*ans[i - j - 1]));
        }
    }

    return ans[n];
}

nth Catalan number = 2nCn/(n+1);


applications of Catalan numbers :-
-> # of BST -> C(n)
-> # of balanced parenthesis  -> C(n)
-> # of triangulations of convex polygon  -> C(n-2)
-> # of non intersecting chords in a circle with 2*n points  -> C(n)






