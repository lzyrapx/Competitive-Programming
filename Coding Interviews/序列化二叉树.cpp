/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
/*
         1
        / \
       2    3
      / \  / \
     4   5 6  7
(前序遍历) 序列化 1,2,4,#,#,5,#,#,3,6,#,#,7,#,#
*/
class Solution {
public:
    // 序列化就是按前序遍历返回一个带有#和逗号的字符串,空节点用 “#”
    void dfs(TreeNode* root, string &str) // 按前序DFS序列化
    {
        if(root == NULL) {
            str = str + "#,"; 
            return;
        }
        str = str + to_string(root -> val);
        str = str + ",";
        dfs(root -> left, str);
        dfs(root -> right, str);
    }
    TreeNode* dfs(string &str) //反序列化
    {
        if(str.size() == 0) return NULL;
        if(str[0] == '#') { // 当前字符对应空结点，跳过
            str = str.substr(2); //跳过当前'#'和','开始截取
            return NULL; //返回空子树
        }
        //stoi:string 转int，后面出现逗号被截断，只转换当前数字字符
        TreeNode* root = new TreeNode(stoi(str));
        str = str.substr(str.find_first_of(',') + 1);//跳过下一个逗号截取
        root -> left = dfs(str); //重建左子树
        root -> right = dfs(str); //重建右子树
        return root;
    }
    
    // 序列化指的是遍历二叉树为字符串
    char* Serialize(TreeNode *root) {
        if(root == NULL) return NULL;
        string str("");
        dfs(root, str);
        char* ans = new char[str.size() + 1];
        strcpy(ans, str.c_str());
        return ans;
    }
    // 所谓反序列化指的是依据字符串重新构造成二叉树
    TreeNode* Deserialize(char *str) {
        if(str == NULL) return NULL;
        string s(str);
        return dfs(s);
    }
};