class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        map<char,string> mp;
        mp['a']=".-";
        mp['b']="-...";
        mp['c']= "-.-.";
        mp['d']= "-..";
        mp['e']= ".";
        mp['f']= "..-.";
        mp['g']= "--.";
        mp['h']= "....";
        mp['i']= "..";
        mp['j']= ".---";
        mp['k']= "-.-";
        mp['l']= ".-..";
        mp['m']= "--";
        mp['n']= "-.";
        mp['o']= "---";
        mp['p']= ".--.";
        mp['q']= "--.-";
        mp['r']= ".-.";
        mp['s']= "...";
        mp['t']= "-";
        mp['u']= "..-";
        mp['v']= "...-";
        mp['w']= ".--";
        mp['x']= "-..-";
        mp['y']= "-.--";
        mp['z']= "--..";
        string str;
        set<string>se;
        for(int i = 0; i < words.size(); i++) {
            str = "";
            for(int j = 0; j < words[i].size(); j++) {
                str = str + mp[words[i][j]];
            }
            se.insert(str);
        }
        return se.size();
    }
};