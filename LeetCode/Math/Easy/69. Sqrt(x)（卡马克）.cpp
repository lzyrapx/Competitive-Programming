class Solution {
public:
    // https://en.wikipedia.org/wiki/Fast_inverse_square_root
    int mySqrt(int x) {
        uint64_t i;
        double x2, y;
        x2 = x * 0.5;
        y = x;
        i = *(uint64_t *) &y;
        i = 0x5fe6eb50c7b537a9 - (i >> 1); // This magic number is taken from wikipedia.
        y = *(double *) &i; // initial guess of the inverse square root
        y = y * (1.5 - (x2 * y * y)); // Newton for inverse square root.
        y = y * (1.5 - (x2 * y * y));
        y = y * (1.5 - (x2 * y * y));
        y = y * (1.5 - (x2 * y * y)); // repeate 4 times to get enough precision.
        return x * y;
    }
};