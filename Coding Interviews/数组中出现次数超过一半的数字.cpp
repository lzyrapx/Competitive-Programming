class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.size() == 0) return 0;
        map<int,int>mp;
        for(int i = 0; i < numbers.size(); i++)
        {
            mp[numbers[i]]++;
        }
        for(int i = 0; i < numbers.size(); i++)
        {
            if(mp[numbers[i]]>numbers.size() / 2) return numbers[i];
        }
        return 0;
    }
};