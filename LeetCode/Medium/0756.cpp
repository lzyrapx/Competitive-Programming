class Solution {
public:
    // 问能不能构成以bottom为最后一层的树
    unordered_map<string,vector<char>>mp;
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for(string str: allowed) {
            mp[str.substr(0, 2)].push_back(str.back());
        }
        string upper = ""; // 上一层
        // bottom 是当前层
        return dfs(bottom, upper, 0);
    }
    bool dfs(string bottom, string upper, int pos) {
        if(pos == bottom.size() - 1){
            if(upper.size() == 1) { // 最顶层只有一个就说明可以构成
                return true;
            }
            bottom = upper;
            upper = "",
            pos = 0;
        }
        vector<char>&ve = mp[bottom.substr(pos, 2)];
        if(ve.empty()) {
            return false;
        }
        for(int i = 0; i < ve.size(); i++){
            if(dfs(bottom, upper + ve[i], pos + 1)) {
                return true;
            }
        }
        return false;
    }
};