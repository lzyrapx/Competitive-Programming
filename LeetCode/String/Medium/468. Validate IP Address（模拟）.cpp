class Solution {
public:
    // 172.16.254.1
    // 2001:0db8:85a3:0000:0000:8a2e:0370:7334
    bool isipv4(string ip)
    {
        if(ip.size()==0) return false;
        if(ip.front() == '0') return false;
        int num = 0;
        int cnt = 0; // 段数
        int pcnt = 0; // 符号'.'前数字个数
        for(char c : ip) {
            if(c != '.' && (c < '0' || c > '9')) return false;
            if(num > 255) return false;
            if(c == '.')
            {
                cnt++;
                if(pcnt == 0) return false;
                if(cnt > 3) return false;
                if(num > 255) return false;
                num = 0;
                pcnt = 0;
                continue;
            }
            if(num == 0 && pcnt > 0) return false;
            num = num * 10 + c - '0';
            pcnt++;
        }
        cnt++; //最后一段
        if(cnt == 4 && ((num == 0 && ip.back() == '0') || (num > 0 && num < 256)) ){
            return 1;
        }
        else return 0;
    }
     bool is16(char c)
     {
         return ((c>='0' && c<='9') || (c >='A' && c<='F') || (c >= 'a' && c <= 'f'));
     }
    bool isipv6(string ip)
    {
        if(ip.size()==0) return false;
        if(ip.front() == '0') return false;
        int cnt = 0;  // 段数
        int pcnt = 0; // 符号'.'前数字个数
        for(char c : ip) {
            
            if(c != ':' && is16(c) == false) return false;
            if(c != ':' && (++pcnt) > 4) return false;
            if(c == ':' && (++cnt) >= 8) return false;
            if(c == ':' && pcnt == 0) return false;
            if(c == ':') pcnt = 0;
        }
        cnt++; //最后一段
        if(cnt == 8 && pcnt > 0) return true;
        else return false;
    }
    string validIPAddress(string IP) {
        if(isipv4(IP)) return "IPv4";
        if(isipv6(IP)) return "IPv6";
        else return "Neither";
    }
};