#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<long long>> Matrix;

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

// Use case 1: Finding n-th Fibonacci number in the sequence
// TimeComplexity : O(logn)
Matrix multiply(Matrix &a, Matrix &b) 
{
    int n = a.size();
    Matrix res(n, vector<long long>(n, 0));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < n; k++)
            {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return res;
}

Matrix matrixExponentiation(Matrix base, int exp) 
{
    int n = base.size();
    Matrix res(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++) res[i][i] = 1;
    while (exp) 
    {
        if (exp & 1) res = multiply(res, base);
        base = multiply(base, base);
        exp /= 2;
    }
    return res;
}

int main()
{
    // cout<<power(4, 2)<<endl;
    int n;
    cin >> n;
    if(n == 0) 
    {
        cout << 0 << endl;
        return 0;
    }
    Matrix mat = {{1, 1},{1, 0}};
    Matrix res = matrixExponentiation(mat, n - 1);
    cout << res[0][0] << endl;
    return 0;
}