class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int ans = 0;
        for (auto &p : points) 
        {
            unordered_map<int, int> mp(points.size());
            for (auto &q : points) {
                 ans += ( mp[ pow((p.first - q.first), 2) + pow((p.second - q.second),2)]++ );
             }    
        }
        return 2 * ans;
    }
};