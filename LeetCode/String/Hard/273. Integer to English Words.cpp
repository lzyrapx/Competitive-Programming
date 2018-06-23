class Solution {
public:
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        vector<string> units {"", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine "};
        vector<string> teens {"Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "};
        vector<string> tenths {"", "", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};
        vector<string> position {"", "", "Hundred ", "Thousand ", "", "Hundred ", "Million ", "", "Hundred ", "Billion "};
        
        string ans;
        if(num < 0) {
            ans += "Negative ";
            num = abs(num);
        }
        vector<int>digits;
        while(num)
        {
            digits.push_back(num % 10);
            num /= 10;
        }
        // 可以发现其实是按照每三位进行读的，比如1234567，最后567就是三位，然后是234，234读完后在后面加一个”Thousand”即可，
        // 同理对于”Million”,”Billion”都是这样的读法。 
        for(int i = digits.size(); i > 0; ){
            i--;
            int d = digits[i];
            if(i % 3 == 1) 
            {
                if(d == 1) 
                {
                    i--;
                    d = digits[i];
                    ans += teens[d];
                }
                else {
                    ans += tenths[d];
                }
            }
            else {
                ans += units[d];
            }
            if (d > 0 || (i % 3 == 0 && (digits[i + 1] > 0 || digits[i + 2] > 0)) ) {
                ans += position[i];
            }
        }
        ans.erase(ans.size()-1);
        return ans;
    }
};