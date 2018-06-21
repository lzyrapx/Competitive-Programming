class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        if(maxWidth == 0) return ans;
        int i = 0, j = 0;
        while(j != words.size())
        {
            int len = 0;
            while(j < words.size() && len + words[j].size() + j - i <= maxWidth)
            {
                len += words[j].size();
                j++;
            }
            cout << len << endl;
            int space = maxWidth - len;
            cout << "space = " << space << endl;
            int k = i;
            // 分配每一行的空格
            while(space)
            {
                words[k] += " ";
                k++;
                space--;
                if(j != words.size() && (k == j - 1 || k == j)) k = i;
                if(j == words.size() && k == j) k = j - 1;
            }
            string line;
            for(int l = i; l < j; l++) {
                line += words[l];
            }
            ans.push_back(line);
            i = j;
        }
        return ans;
    }
};