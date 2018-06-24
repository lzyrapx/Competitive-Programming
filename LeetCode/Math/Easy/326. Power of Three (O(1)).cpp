class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 0) return false;
        if( fmod( log10(n) / log10(3), 1) == 0) return true;
        else return false;
    }
};