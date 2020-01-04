/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-04 16:36:12
 */
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if(quadTree1 == NULL || quadTree2 == NULL) {
            return NULL;
        }
        if(quadTree1 -> isLeaf && quadTree1 -> val == true) {
            return quadTree1;
        }
        if(quadTree2 -> isLeaf && quadTree2 -> val == true) {
            return quadTree2;
        }
        if(quadTree1 -> isLeaf && quadTree2 -> isLeaf) {
            return quadTree1;
        }
        if(quadTree1 -> isLeaf) {
            return quadTree2;
        }
        if(quadTree2 -> isLeaf) {
            return quadTree1;
        }
        // both not leaves
        Node * res = new Node();
        res -> isLeaf = false;
        res -> val = false;
        res -> topLeft = intersect(quadTree1 -> topLeft, quadTree2 -> topLeft);
        res -> topRight = intersect(quadTree1 -> topRight, quadTree2 -> topRight);
        res -> bottomLeft = intersect(quadTree1 -> bottomLeft, quadTree2 -> bottomLeft);
        res -> bottomRight = intersect(quadTree1 -> bottomRight, quadTree2 -> bottomRight);
        if (res->topLeft->isLeaf && res->topRight->isLeaf && res->bottomLeft->isLeaf && res->bottomRight->isLeaf) {
            if(res->topLeft->val == res->topRight->val && res->topRight->val == res->bottomLeft->val && res->bottomLeft->val == res->bottomRight->val) {
                res -> isLeaf = true;
                res -> val = res->topLeft->val;
                res -> topLeft = NULL;
                res -> topRight = NULL;
                res -> bottomLeft = NULL;
                res -> bottomRight = NULL;
            }
        }
        return res;
    }
};