/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-22 13:00:42
 */
class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>>vex,veo;
        for(int i = 0; i < moves.size(); i++) {
            if(i % 2 == 0) { // X
                vex.push_back(moves[i]);
            }
            else { // O
                veo.push_back(moves[i]);
            }
        }
        auto check = [&](vector<vector<int>>&ve, int x, int y) {
            for(int i = 0; i < ve.size(); i++) {
                if(ve[i][0] == x && ve[i][1] == y) {
                    return true;
                }
            }
            return false;
        };
        // check vex
        for(int i = 0; i <= 2; i++) {
            if(check(vex, i, 0) && check(vex, i, 1) && check(vex, i, 2)) {
                return "A";
            }            
        }
        for(int i = 0; i <= 2; i++) {
            if(check(vex, 0, i) && check(vex, 1, i) && check(vex, 2, i)) {
                return "A";
            }         
        }
        if(check(vex, 0, 2) && check(vex, 1, 1) && check(vex, 2, 0)) {
                return "A";
        }
        if(check(vex, 0, 0) && check(vex, 1, 1) && check(vex, 2, 2)) {
                return "A";
        } 
        // check veo
        for(int i = 0; i <= 2; i++) {
            if(check(veo, i, 0) && check(veo, i, 1) && check(veo, i, 2)) {
                return "B";
            }            
        }
        for(int i = 0; i <= 2; i++) {
            if(check(veo, 0, i) && check(veo, 1, i) && check(veo, 2, i)) {
                return "B";
            }            
        }
        if(check(veo, 0, 2) && check(veo, 1, 1) && check(veo, 2, 0)) {
            return "B";
        }
        if(check(veo, 0, 0)&& check(veo, 1, 1) && check(veo, 2, 2)) {
            return "B";
        }
           
        if(moves.size() == 9) {
            return "Draw";
        }
        return "Pending";
    }
};