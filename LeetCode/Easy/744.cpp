/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-05 22:55:33
 */
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for(int i = 0; i < letters.size(); i++) {
            if(letters[i] - target > 0) {
                return letters[i];
            }
        }
        return letters[0];
    }
};