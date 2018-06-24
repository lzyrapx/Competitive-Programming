class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 0) return true;
        if(num == INT_MAX) return false;
        if((int)sqrt(num) * (int)sqrt(num) == num) return true;
        else return false;
    }
};