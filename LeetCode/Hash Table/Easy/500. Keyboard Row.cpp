class Solution {
 public:
  vector<string> findWords(vector<string>& words) {
    unordered_set<char> dict1 = {'q', 'Q', 'w', 'W', 'e', 'E', 'r',
                                 'R', 't', 'T', 'y', 'Y', 'u', 'U',
                                 'i', 'I', 'o', 'O', 'p', 'P'};
    unordered_set<char> dict2 = {'a', 'A', 's', 'S', 'd', 'D', 'f', 'F', 'g',
                                 'G', 'h', 'H', 'j', 'J', 'k', 'K', 'l', 'L'};
    unordered_set<char> dict3 = {'z', 'Z', 'x', 'X', 'c', 'C', 'v',
                                 'V', 'b', 'B', 'n', 'N', 'm', 'M'};
    vector<string> ans;
    for (auto& word : words) {
      bool f1 = true, f2 = true, f3 = true;
      for (auto& ch : word) {
        if (f1 == true) {
          if (dict1.find(ch) == dict1.end()) f1 = false;
        }
        if (f2 == true) {
          if (dict2.find(ch) == dict2.end()) f2 = false;
        }
        if (f3 == true) {
          if (dict3.find(ch) == dict3.end()) f3 = false;
        }
      }
      if (f1 == true || f2 == true || f3 == true) {
        ans.push_back(word);
      }
    }
    return ans;
  }
};