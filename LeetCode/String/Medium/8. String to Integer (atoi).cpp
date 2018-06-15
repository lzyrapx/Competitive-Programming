class Solution {
public:
    int myAtoi(string str) {
        long long ans = 0;
        int i = 0;
        while(i  < str.size() && str[i] == ' '){
            i++;
        }
        int flag = 0;
        if(str[i] == '-') {
            flag = 1;
            i++;
        }
        else if(str[i] == '+')i++;
        while(i < str.size() && isdigit(str[i])) {
            ans = ans * 10 + str[i] - '0';
            i++;
            if(ans > INT_MAX) return flag ? INT_MIN: INT_MAX;;
        }
        return flag ? -ans : ans;
    }
};