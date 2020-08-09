class Solution {
public:
    // L 只能左移，R 只能右移, 并且只能和 X 进行交换
    bool canTransform(string start, string end) {
        int len = start.size();
        if(start.size() != end.size()) {
            return false;
        }
        int i = 0;
        int j = 0;
        while(true){
            while(i < len && start[i] == 'X') {
                i++;
            }
            while(j < len && end[j] == 'X') {
                j++;
            }
            if(i == len || j == len) {
                if(i == len && j == len) {
                    return true;
                }
                return false;
            }
            if(start[i] != end[j]) {
                return false;
            }
            else {
                // start 中 L 左边的 X 比 end 中 L 左边的 X 还少， 因为 L 左边的 X 只会减少
                if(start[i] == 'L' && i < j) {
                    return false;
                }
                // start 中 R 左边的 X 比 start 中 R 左边的 X 还多，因为 R 左边的 X 只会增多
                if(start[i] == 'R' && i > j) {
                    return false;
                }
            }
            i++;
            j++;
        }
        return true;
    }
};