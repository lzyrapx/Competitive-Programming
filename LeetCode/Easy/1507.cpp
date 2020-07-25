/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-07-25 12:06:14
 */ 
class Solution {
public:
    string reformatDate(string date) {
        unordered_map<string, string>mp = {{"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"}, 
                                           {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"}, 
                                           {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}};
        string out = "", temp;
        stringstream ss(date);
        ss >> temp;
        if(temp.length()==3)
            out+="0";
        out += temp.substr(0, temp.length()-2);
            
        ss >> temp;
        out = mp[temp] + "-" + out;
        
        ss >> temp;
        out = temp + "-" + out;
        return out;       
    }
};