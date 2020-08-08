class Solution {
public:
    int monotoneIncreasingDigits(int N) {
       if(N == 0){
           return 0;
       }
        string num = to_string(N);
        int id = num.size();
        for(int i = num.size() - 1; i >= 1; --i) {
            if(num[i] < num[i - 1]) { // 不符合
                num[i - 1]--;
                id = i;
            }
        }
        for(int i = id; i < num.size(); i++){
            num[i] = '9';
        }
        return stoi(num);
    }
};