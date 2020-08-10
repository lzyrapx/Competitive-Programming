class Solution {
public:
    vector<int>disvor(int num) {
        for(int i = sqrt(num); i >= 2; --i){
            if(num % i == 0) {
                return {i, num / i};
            }
        }
        return {1, num};
    }
    vector<int> closestDivisors(int num) {
        if(num == 0) {
            return {1,1};
        }
        vector<int>ans;
        long long plus1 = num + 1;
        long long plus2 = num + 2;
        vector<int>res1 = disvor(plus1);
        vector<int>res2 = disvor(plus2);
        if(abs(res1[0] - res1[1]) > abs(res2[0] - res2[1])) {
            return res2;
        }
        return res1;
        
    }
};