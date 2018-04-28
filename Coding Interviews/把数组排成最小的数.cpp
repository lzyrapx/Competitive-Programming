
class Solution {
public:
    static bool cmp(int a,int b) // 注意要加static
    {
        string  A = to_string(a) + to_string(b);
        string  B = to_string(b) + to_string(a);
        return A < B;
    }
    string PrintMinNumber(vector<int> numbers) {
        string ans="";
        sort(numbers.begin(),numbers.end(),cmp);
        for(int i = 0; i < numbers.size(); i++)
        {
            ans = ans + to_string(numbers[i]);
        }
        return ans;
    }
};