class Solution {
public:
    // 滑动窗口
    int expressiveWords(string S, vector<string>& words) {
        int cnt = 0;
        if(words.size() == 0) return 0;
        for(auto word: words)
        {
            if(word.size() > S.size()) continue; // words不可能大于S
            int i = 0, j = 0;
            while(i < S.size() && S[i] == word[j])
            {
                int p = i, q = j;
                while(i + 1 < S.size() && S[i] == S[i + 1]) i++; // S
                while(j + 1 < word.size() && word[j] == word[j + 1]) j++; // word
                int repeat_i = i - p + 1; // S
                int repeat_j = j - q + 1;// word
                // 以下条件满足其中一个，就不用break
                if(!(repeat_i == repeat_j || (repeat_i > repeat_j && repeat_i > 2))) break;
                i++;
                j++;
            }
            if(i == S.size() && j == word.size()) cnt++;
        }
        return cnt;
    }
};