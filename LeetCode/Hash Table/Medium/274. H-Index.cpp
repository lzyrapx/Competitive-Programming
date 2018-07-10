class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size() == 0) return 0;
        sort(citations.begin(),citations.end());
        int i = 0; 
        int j = citations.size() - 1;
        while(j >= 0 && citations[j] > i) i++,j--;
        return i;
    }
};