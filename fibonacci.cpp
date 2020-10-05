#include <bits/stdc++.h>

using namespace std;

//Recursive Solution O(2^n)
int fib(int n)
{
    if (n == 1 || n == 0)
        return n;

    int f1 = fib(n - 1);
    int f2 = fib(n - 2);

    return f1 + f2;
}

//Top Down approach - Memoization

int memo[1000];

int fib1(int n)
{
    if (memo[n] != -1)
        return memo[n];

    int f1 = fib(n - 1);
    int f2 = fib(n - 2);
    memo[n] = f1 + f2;

    return memo[n];
}

//Bottom up approach DP
int fib2(int n)
{
    int dp[1000] = {0};

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
}

int main()
{
    memset(memo, -1, sizeof memo);
    memo[0] = 0;
    memo[1] = 1;
    int n = 45;

    cout << fib2(n) << endl;
    return 0;
}
