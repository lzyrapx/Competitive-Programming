class Solution {
public:
     int  NumberOf1(int n) {
         return __builtin_popcount(n);
     }
};