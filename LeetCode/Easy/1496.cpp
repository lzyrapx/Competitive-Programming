/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-07-07 13:45:26
 */ 
class Solution {
public:
    bool isPathCrossing(string path) {
        if(path.size() == 0){
            return false;
        }
        int res = false;
        set<pair<int,int>>se;
        pair<int,int>pi = {0, 0};
        se.insert({0, 0});
        for(int i = 0; i < path.size(); i++){
            if(path[i] == 'N') {
                pi.second += 1;
            }
            if(path[i] == 'S'){
                pi.second -= 1;
            }
            if(path[i] == 'E') {
                pi.first += 1;
            }
            if(path[i] == 'W') {
                pi.first -= 1;
            }
            if(se.count(pi)) {
                return true;
            }
            se.insert(pi);
        }
        return false;
    }
};