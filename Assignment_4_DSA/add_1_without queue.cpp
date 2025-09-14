#include <iostream>
#include <queue>
using namespace std;

void binarysequence(int n)
{

    for (int i = 1; i <= n; i++)
    {
        int quotient = i, rem = 0, bin = 0, fac = 1;
        while (quotient != 0)
        {
            rem = quotient % 2;
            bin += rem * fac;
            fac *= 10;
            quotient = quotient / 2;
        }
        cout << bin << " , ";
    }
}

int main()
{
    binarysequence(5);
    return 0;
}