/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-29 16:44:15
 */
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        if(rectangles.size() == 0) {
            return false;
        }
        set<vector<int>>se;
        for(auto rect: rectangles) {
            se.insert(rect);
        }
        if(rectangles.size() != se.size()) {
            return false;
        }
        // 除了大矩形四个点以外，其他所有顶点出现的次数都应该是2或4次。
        map<pair<int,int>,int>mp;
        int mxa = 1e9, mxb = 1e9, mxc = -1, mxd = -1;
        int area = 0, cur_area = 0;
        for(int i = 0; i < rectangles.size(); i++) {
            mxa = min(rectangles[i][0], mxa);
            mxb = min(rectangles[i][1], mxb);
            mxc = max(rectangles[i][2], mxc);
            mxd = max(rectangles[i][3], mxd);
            
            mp[{rectangles[i][0],rectangles[i][1]}] += 1;
            mp[{rectangles[i][2],rectangles[i][3]}] += 1;
            mp[{rectangles[i][0],rectangles[i][3]}] += 1;
            mp[{rectangles[i][2],rectangles[i][1]}] += 1;
            
            cur_area += abs(rectangles[i][2] - rectangles[i][0]) * abs(rectangles[i][3] - rectangles[i][1]);
        }
        area = abs(mxc - mxa) * abs(mxd - mxb);
        if(cur_area != area) {
            return false;
        }
        
        map<pair<int,int>,int>tmp;
        tmp[{mxa, mxb}] += 1;
        tmp[{mxc, mxd}] += 1;
        tmp[{mxa, mxd}] += 1;
        tmp[{mxc, mxb}] += 1;
        for(auto point: mp) {
            // cout << point.first.first << " " << point.first.second << " " << point.second << endl;
            if(tmp[{point.first.first,point.first.second}] == 0 && point.second != 2 && point.second != 4) {
                return false;
            }
        }
        return true;
    }
};