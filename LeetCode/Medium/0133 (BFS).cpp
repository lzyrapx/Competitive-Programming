/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-06-06 21:59:40
 */ 
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) {
            return nullptr;
        }
        unordered_map<Node*, Node*>mp;
        queue<Node*>que({node});
        Node* newNode = new Node(node -> val);
        mp[node] = newNode;
        while(!que.empty()) {
            auto tmp = que.front();
            que.pop();
            for(const auto& edge: tmp -> neighbors) {
                if(!mp.count(edge)) {
                    que.push(edge);
                    mp[edge] = new Node(edge -> val);
                }
                mp[tmp] -> neighbors.push_back(mp[edge]);
            }
        }
        return mp[node];
    }
};