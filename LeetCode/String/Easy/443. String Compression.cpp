class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size() == 1) return 1;
        int cur = 0;
        int cnt = 0, num = 0;
        for(int i = 0; i < chars.size();) {
            chars[cur] = chars[i];
            cur++;
            cnt = 0;
            while(i < chars.size() && chars[i] == chars[cur - 1]) {
                i++;
                cnt++;
            }
            if(cnt == 1) continue;
            num = cur;
            while(cnt > 0) {
                chars[cur] = (cnt % 10) + '0';
                cur++;
                cnt /= 10;
            }
            reverse(chars.begin() + num, chars.begin() + cur);
        }
        return cur;
    }
};