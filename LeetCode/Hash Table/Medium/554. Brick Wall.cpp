class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();
        int m = 0;
        map<int,int>mp;
        for(auto &row : wall) {
            for(int i = 1; i < row.size() - 1; i ++) {
                row[i] += row[i - 1];
            }
        }
        for(auto &row : wall) {
            for(int i = 0; i < row.size() - 1; i ++) {
                mp[row[i]] += 1;
            }
        }
        int maxx = 0;
        for(auto x : mp) {
            cout << x.second << endl;
            maxx = max(maxx, x.second);
        }
        // cout << n << " " << maxx << endl;
        return n - maxx;
    }
};