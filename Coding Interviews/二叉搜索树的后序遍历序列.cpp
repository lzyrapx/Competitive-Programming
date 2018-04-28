class Solution {
public:
    // 二叉搜索树的左子树的值一定比右子树的值小
    /*
    BST的后序序列的合法序列是，对于一个序列S，最后一个元素是x （也就是根），如果去掉最后一个元素的序列为T，
    那么T满足：T可以分成两段，前一段（左子树）小于x，后一段（右子树）大于x，且这两段（子树）都是合法的后序序列。
    */
    bool dfs(vector<int>&sequence, int l, int r)
    {
        if(l >= r) return true;
        
        int mid = r;
        // 找到mid，满足前面的值 不大于 后面的值
        while(mid > l && sequence[mid - 1] > sequence[r]) --mid;
        
        for(int i = mid - 1; i >= l; --i) {
            if(sequence[i] > sequence[r]) return false;
        }
        return dfs(sequence, l, mid - 1) && dfs(sequence, mid ,r - 1);
    }
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size() == 0) return false;
        return dfs(sequence , 0, sequence.size() - 1);
    }
};