/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-08-02 21:32:44
 */
class Solution {
public:
    // 题意：判断是否是前序遍历
    bool isValidSerialization(string preorder) {
        int slots = 1;
        vector<string>nodes;
        string num = "";
        for(int i = 0; i < preorder.size(); i++) {
            if(preorder[i] == ',') {
                nodes.push_back(num);
                num = "";
            }
            else {
                num = num + preorder[i];
            }
        }
        nodes.push_back(num);
        for(int i = 0; i < nodes.size(); i++) {
            slots -= 1;
            if(slots < 0) {
                return false;
            }
            if(nodes[i] != "#") {
                slots += 2;
            }
        }
        if(slots == 0) {
            return true;
        }
        return false;
    }
};