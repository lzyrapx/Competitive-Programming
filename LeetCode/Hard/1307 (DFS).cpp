/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-24 14:56:04
 */
class Solution {
public:
    int letter[27];
    int digit[11];
    vector<string>w;
    string res;
    bool dfs(int num, int len, int sum) {
        if(len == res.size()) {
            if(sum == 0) {
                return true;
            }
            else{
                return false;
            }
        }
        // 处理完所有的words
        if(num == w.size()) {
            if(letter[res[len] -'A'] != -1) { // 字母处理过
                if(letter[res[len] - 'A'] == sum % 10) {
                    return dfs(0, len + 1, sum / 10);
                }
            }
            else if(digit[sum % 10] == -1) { // 数字没使用过
                if(len == (int)res.size() - 1 && sum % 10 == 0) { // 首位为 0
                    return false;
                }
                letter[res[len] -'A'] = sum % 10;
                digit[sum % 10] = res[len] - 'A';
                bool tmp = dfs(0, len + 1, sum / 10);
                letter[res[len] - 'A'] = -1;
                digit[sum % 10] = -1;
                return tmp;
            }
            return false;
        }
        
        if(len >= w[num].size()) {
            return dfs(num + 1, len, sum);
        }
        if(letter[w[num][len] -'A'] != -1) { //字母处理过
            if(len != (int)w[num].size() - 1 || letter[w[num][len] - 'A'] != 0) { // 首位数字不为0
                return dfs(num + 1, len, sum + letter[w[num][len] - 'A']);
            }
        } 
        for(int i = 0; i <= 9; i++) {
            if(digit[i] != -1) {
                continue;
            }
            if(i == 0 && w[num].size() - 1 == len) {
                continue;
            }
            letter[w[num][len] - 'A'] = i;
            digit[i] = w[num][len] - 'A';
            bool tmp = dfs(num + 1, len, sum + i);
            letter[w[num][len] - 'A'] = -1;
            digit[i] = -1;
            if(tmp == true) return tmp;
        }
        return false;
    }
    bool isSolvable(vector<string>& words, string result) {
        for(int i = 0; i < words.size(); i++) {
            if(words[i].size() > result.size()) {
                return false;
            }
        }
        memset(letter, -1, sizeof(letter));
        memset(digit, -1, sizeof(digit));
        w = words;
        res = result;
        cout << result << endl;
        for(int i = 0; i < w.size(); i++) {
            reverse(w[i].begin(), w[i].end());
        }
        reverse(res.begin(), res.end());
        return dfs(0, 0, 0);
    }
};