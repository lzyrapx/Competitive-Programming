class Solution {
public:
    string validIPAddress(string IP) {
        switch(checkip(IP)){
        case 4: return "IPv4";
        case 6: return "IPv6";
        default:return "Neither";
        }
    }
    bool isdigit(char ch) {
        return (ch >= '0' && ch <= '9');
    }
    bool ishex(char ch) {
        return isdigit(ch) || (ch >= 'a' && ch <= 'f') || (ch >= 'A' && ch <= 'F');
    }
    int checkip(string IP)
    {
        // 172.16.254.1
        // 2001:0db8:85a3:0000:0000:8a2e:0370:7334
        enum{
            s_init = 0, 
            s_zero = 1, 
            s_digit = 2, 
            s_v6 = 3, 
            
            s_zero4 = 4, 
            s_init4 = 5, 
            s_init6 = 6, 
            s_v4 = 7
                
        }
        s = s_init; // 初始化
    
        int digit = 0;
        int g = 0;
        int n = 0;
        for(char ch : IP) 
        {
            cout << "ch=" << ch << endl;
            cout << "s=" << s << endl; 
            switch(s) 
            {
                case s_init:
                    if(ch == '0') {
                        s = s_zero;
                    }
                    else if(isdigit(ch)) { 
                        digit = ch - '0';
                        s = s_digit;
                        n = 1;
                    }
                    else if(ishex(ch)) { // A-F , a-f ,ipv6
                        s = s_v6;
                        n = 1;
                    }
                    else { // 啥都不是
                        return 0;
                    }
                    break;
                    
                case s_zero:
                    if(ishex(ch)) { // 有前缀0的只可能是IPv6
                        s = s_v6;
                        n = 2;
                    }
                    else if(ch == '.') { // 0.
                        s = s_init4;
                        g = 1;
                    }
                    else if(ch == ':') { // 0:
                        s = s_init6;
                        g = 1;
                    }
                    else{ 
                        return 0; 
                    }
                    break;
                    
                case s_digit:
                    if(isdigit(ch)) {
                        digit = digit * 10 + (ch - '0');
                        n++;
                        if(n > 3 || digit > 255){ // 超过3个数，或255的只能是IPv6
                            s = s_v6;
                        }
                    }
                    else if(ishex(ch)) {
                        n++;
                        s = s_v6;
                    }
                    else if(ch == '.') { // for example, 123.
                        s = s_init4;
                        g = 1;
                    }
                    else if(ch == ':') { // 0:
                        if(n > 4){
                            return 0;
                        }
                        s = s_init6;
                        g = 1;
                    }
                    else { 
                        return 0; 
                    }
                    break;
                    
             case s_v6:
                    if(ishex(ch)) {
                        n++;
                        if(n > 4) { return 0; }
                    }
                    else if(ch == ':') {
                        s = s_init6;
                        g++;
                        if(g > 7){ return 0; }
                    }
                    else{ 
                        return 0; 
                    }
                    break;
                    
              case s_init4:
                    if(ch == '0') {
                        s = s_zero4;
                    }
                    else if(isdigit(ch)) {
                        digit = ch - '0';
                        s = s_v4;
                    }
                    else { 
                        return 0; 
                    }
                    break;
                    
             case s_init6:
                    if(ishex(ch)) {
                        s = s_v6;
                        n = 1;
                    }
                    else{ return 0; }
                break;
                    
             case s_zero4:
                if(ch == '.') { // 0.
                    s = s_init4;
                    g++;
                    if(g > 4) { 
                        return 0; 
                    }
                }
                else { 
                    return 0; 
                }
                break;
                    
             case s_v4:
                if(isdigit(ch)) {
                    digit = digit * 10 + (ch - '0');
                    if(digit > 255) {
                        return 0;
                    }
                }
                else if(ch == '.') {
                    s = s_init4;
                    g++;
                    if(g > 3){ return 0; }
                }
                else { 
                    return 0; 
                }
                break;
                    
            default:
                return 0;
          }
        }
        if((s == s_v4 || s == s_zero4) && g == 3){
            return 4; // IPv4
        }
        if(s == s_v6 && g == 7){
            return 6; // IPv6
        }
        return 0; // neither
    }
    
    
};