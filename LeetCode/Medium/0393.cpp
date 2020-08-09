class Solution {
public:
    // 判断数组中的数能不能表示成数个合法的 UTF-8 字符
    bool validUtf8(vector<int>& data) {
        int n = 0;
        for(int i = 0; i < data.size(); i++) {
            if(n > 0)
            {
                if(data[i] >> 6 != 2) return false;
                n--;
            }
            else if(data[i] >> 7 == 0){
                n = 0;
            }
            else if(data[i] >> 5 == 0b110)
            {
                n = 1;
            }
            else if(data[i] >> 4 == 0b1110)
            {
                n = 2;
            }
            else if(data[i] >> 3 == 0b11110){
                n = 3;
            }
            else{
                return false;
            }
        }
        if(n == 0) {
            return true;
        }
        return false;
    }
};