/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-08-02 15:12:09
 */ 
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int>ans;
        for(int i = 0; i < input.size(); i++) {
            char c = input[i];
            if(c == '+' || c == '-' || c == '*') {
                vector<int>res1 = diffWaysToCompute(input.substr(0, i));
                vector<int>res2 = diffWaysToCompute(input.substr(i + 1));
                for(auto r1: res1) {
                    for(auto r2: res2) {
                        if(c == '+') {
                            ans.push_back(r1 + r2);
                        } else if(c == '-') {
                            ans.push_back(r1 - r2);
                        } else if(c == '*') {
                            ans.push_back(r1 * r2);
                        }
                    }
                }
            }
        }
        // 没有符号
        if(ans.empty()) {
            ans.push_back(stoi(input)); 
        }
        return ans;
    }
};