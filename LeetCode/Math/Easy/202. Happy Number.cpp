class Solution {
public:
    bool isHappy(int n) {
        map<int,int>mp;
        while(n > 0)
        {
            if(mp[n] > 0) return false;
            if(n == 1) return true;
            mp[n]++;
            int sum = 0;
            while(n > 0)
            {
                sum += pow(n % 10, 2);
                n /= 10;
            }
            n = sum;
        }
    }
};