#include <bits/stdc++.h>
using namespace std;

long long power(long long base, long long exp)
{
    // base case
    if(exp == 0) return 1;

    // recursive call
    long long ans = power(base, exp / 2);
    if(exp & 1)
    {
        ans *= ans * base;
    }
    else ans *= ans;
    return ans;
}

int main()
{
    cout<<power(4, 2)<<endl;
    return 0;
}