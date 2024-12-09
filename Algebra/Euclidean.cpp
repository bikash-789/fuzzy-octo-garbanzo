#include <bits/stdc++.h>
using namespace std;

// Euclidean algorithm for computing the greatest common divisor
class GCDAlgorithm 
{
public:
    virtual int gcd(int a, int b) = 0;
    virtual ~GCDAlgorithm() {}
};

class IterativeGCD : public GCDAlgorithm {
public:
    int gcd(int a, int b) override 
    {
        while (b) 
        {
            a %= b;
            swap(a, b);
        }
        return a;
    }
};

class RecursiveGCD : public GCDAlgorithm 
{
public:
    int gcd(int a, int b) override
    {
        // base case
        if (b == 0) return a;
        // recursive call
        return gcd(b, a % b);
    }
};

int main() 
{
    GCDAlgorithm* algo;
    algo = new IterativeGCD();
    cout << "Iterative GCD: " << algo->gcd(16, 24) << endl;
    delete algo;
    algo = new RecursiveGCD();
    cout << "Recursive GCD: " << algo->gcd(16, 24) << endl;
    delete algo;
}