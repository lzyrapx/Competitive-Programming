class Solution {
public:
    // invail : "1 1", 0x23, "." , 2e3.1, 2e , 1a , ++1, 1++, "6e6.5" , 2e+1.3 , 2.3e+1.5 
    // vail : 2e+12 , 1e-23, " 0.1 "
    // e后面不可能同时有点
    bool isNumber(string s) {
        if(s.size() == 0) return false;
        int i = 0;
        int num_cnt = 0;
        int point_cnt = 0;
        while(s[i]==' ') i++;
        if(s[i] == '+' || s[i] == '-') i++;
        while(isdigit(s[i]) || s[i] == '.')
        {
            if(s[i] == '.') point_cnt++;
            else num_cnt++;
            if(point_cnt > 1) return false;
            i++;
        }
        if(point_cnt > 1) return false;
        if(num_cnt == 0) return false; 
        
        if(s[i] == 'e') 
        {
            i++;
            num_cnt = 0;
            point_cnt = 0;
            if(s[i] == '.') return false;
            if(s[i] == '+' || s[i] == '-') i++;
            while(isdigit(s[i]) || s[i] == '.') 
            {
                if(s[i] == '.') point_cnt++;
                else num_cnt++;
                if(point_cnt > 0) return false;
                i++;
            }
            if(point_cnt > 0) return false;
            if(num_cnt == 0) return false; 
        }
        // cout << i << " " << s.size() << endl;
        while(s[i] == ' ') i++;
        if(i == s.size()) return true;
        else return false;
    }
};