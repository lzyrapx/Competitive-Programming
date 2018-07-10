class Solution {
public:
    const int wide=26;  //每个节点的最大子节点数
    struct Node
    {
        Node(){
            memset(ch,0,sizeof(ch));
            val=0;
        }
        Node *ch[26];
        int val;
    };
    Node *head;

    void init(){

        head=new Node;
    }
    inline int idx(char c)
    {
        return c-'a';
    }
    void insert(string s,int v) //插入, v 从 1 开始标号
    {   
        cout << "ss = " << s << endl;
        int i,len=s.size(),c;
        Node *p=head,*q;
        for(i = 0;i < len;i++)
        {
            c=idx(s[i]);   //求对应编号
            if(!p->ch[c])
            {
                q = new Node;
                p->ch[c]=q;
            }
            p = p->ch[c];
        }
        p->val = v;
    }
    string find(string s) //查找
    {    
        int i,len=s.size(),c;
        Node *p=head;
        string res;
        for(i = 0;i < len;i++)
        {
            c = idx(s[i]);
           if(p->val || !p->ch[c]) break;
            p = p -> ch[c];
            res += s[i]; // s的前缀
        }
        cout << "res =" << res << endl;
        if(p -> val) return res;
        else return s;
    }
    void free(Node *p) //释放内存
    {   
        int i;
        for(i = 0;i < 26;i++){
            if(p->ch[i]){
            	free(p->ch[i]);
            }
        }
        delete p;
    }
    string replaceWords(vector<string>& dict, string sentence) {
        string ans;
        if(dict.size() == 0) return sentence;
        init();
        for(int i = 1; i <= (int)dict.size(); i++){
            insert(dict[i-1],i);
        }
        stringstream ss(sentence);
        string s;
        while(getline(ss,s,' ')) {
            ans += find(s) + " ";
        }
        free(head);
        return ans.substr(0,(int)ans.size()-1);
    }
};