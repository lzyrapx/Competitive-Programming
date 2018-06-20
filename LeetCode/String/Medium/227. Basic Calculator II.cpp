class Solution {
public:
    int calculate(string s) {
        stack<int>sta;
        char sign = '+'; // 初始化
        int tmp = 0;
        for(int i = 0; i < s.size(); i++) {
            if(isdigit(s[i])) {
                tmp = 10 * tmp + s[i] - '0';
            }
            if((isdigit(s[i])==0 && isspace(s[i])==0) || i == s.size() - 1) {
                if(sign == '-') {
                    sta.push(-tmp);
                }
                else if(sign == '+') {
                    cout << tmp << endl;
                    sta.push(tmp);
                }
                else{
                    int num = 0;
                    if(sign == '*') {
                        num = sta.top() * tmp;
                    }
                    else if(sign == '/') {
                        num = sta.top() / tmp;
                    }
                    sta.pop();
                    sta.push(num);
                }
                sign = s[i];
                tmp = 0;
            }
        }
        int ans = 0;
        while(!sta.empty()){
            ans += sta.top();
            sta.pop();
        }
        return ans;
    }
};