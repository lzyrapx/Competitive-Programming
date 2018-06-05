class Solution {
public:
    int numSquares(int n)
    {
        while (n %4 == 0) {
            n /= 4;
        }
        if(n % 8 == 7) return 4;
        for(int a = 0; a * a <= n; a++) {
            int b = sqrt(n - a * a);
            if(a * a + b * b == n) {
                if(a > 0) return 2;
                else return 1;
            }
        }
        return 3;
    }
};

/*
1. a square if and only if each prime factor occurs to an even power in the number’s prime factorization.
2. a sum of two squares if and only if each prime factor that’s 3 modulo 4 occurs to an even power in the number’s prime factorization.
3.a sum of three squares if and only if it’s not of the form 4a(8b+7) with integers a and b.
4. a sum of four squares. Period. No condition. You never need more than four.
*/