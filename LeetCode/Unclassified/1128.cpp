/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-11-17 22:18:20
 */
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int,int>, int>mp;
        int ans = 0;
        for(int i = 0; i < dominoes.size(); i++) {
            int x = min(dominoes[i][0],dominoes[i][1]);
            int y = max(dominoes[i][0],dominoes[i][1]);
            
            if(mp[{x, y}] > 0) {
                ans += mp[{x,y}];
                mp[{x, y}] += 1;
            } else {
                mp[{x, y}] += 1;
            }
        }
        return ans;
    }
};