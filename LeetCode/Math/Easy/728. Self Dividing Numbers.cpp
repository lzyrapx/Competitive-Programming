class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>ans;
        for(int i = left; i <= right; i++) {
            if(check(i)) ans.push_back(i);
        }
        return ans;
    }
    bool check(int n)
    {
        if(n < 10) return true;
        int p = n;
        while(p > 0){
            int tmp = p % 10;
            if(tmp == 0) return false; // a self-dividing number is not allowed to contain the digit zero.
            if(n % tmp != 0) return false;
            p /= 10;
        }
        return true;
    }
};