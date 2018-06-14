class Solution {
public:
    bool judgeCircle(string moves) {
        if(moves.size() % 2 == 1) return false;
        if(moves.size() == 0) return true;
        map<char, int> mp;
        for(int i = 0; i < moves.size(); i++) {
            mp[moves[i]]++;
        }
        if(mp['U']==mp['D'] && mp['R'] == mp['L']) return true;
        else return false;
    }
};