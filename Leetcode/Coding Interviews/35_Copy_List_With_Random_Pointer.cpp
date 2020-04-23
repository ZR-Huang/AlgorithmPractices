/*
注意：本题与主站 138 题相同：https://leetcode-cn.com/problems/copy-list-with-random-pointer/

请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，
还有一个 random 指针指向链表中的任意节点或者 null。

示例 1：
输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]

示例 2：
输入：head = [[1,1],[2,1]]
输出：[[1,1],[2,1]]

示例 3：
输入：head = [[3,null],[3,0],[3,null]]
输出：[[3,null],[3,0],[3,null]]

示例 4：
输入：head = []
输出：[]
解释：给定的链表为空（空指针），因此返回 null。

提示：
    -10000 <= Node.val <= 10000
    Node.random 为空（null）或指向链表中的节点。
    节点数目不超过 1000 。
*/
#include <iostream>
#include <unordered_map>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
private:
    unordered_map<Node*, Node*> hash_map;
public:
    Node* copyRandomList(Node* head) {
        Node* new_head = new Node(0);
        if (head==NULL) return new_head->next;
        Node* new_p = new_head;
        Node* p = head;
        while(p!=NULL){
            Node* node = new Node(p->val);
            new_p->next = node;
            hash_map.insert({p, node});
            new_p = new_p->next;
            p = p->next;
        }
        new_p = new_head->next;
        p = head;
        while(p!=NULL){
            Node* random = p->random;
            if (random!=NULL)
                new_p->random = hash_map.at(random);
            p = p->next;
            new_p = new_p->next;
        }
        return new_head->next;
    }
};