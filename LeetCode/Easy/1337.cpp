/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-02-16 19:10:35
 */
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>>ve;
        vector<int>ans;
        if(k == 0) {
            return ans;
        }
        for(int i = 0; i < mat.size(); i++) {
            int sum = 0;
            for(int j = 0; j < mat[0].size(); j++) {
                sum += mat[i][j];
            }
            ve.push_back({i, sum});
        }
        sort(ve.begin(), ve.end(), [&](pair<int,int>a, pair<int,int>b) -> bool {
            if(a.second < b.second) return true;
            if(a.second > b.second) return false;
            return a.first < b.first; 
        });
        for(int i = 0; i < k; i++) {
            ans.push_back(ve[i].first);
        }
        return ans;
    }
};