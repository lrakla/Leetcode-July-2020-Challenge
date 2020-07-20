/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        auto node = head;
        ListNode* prev = NULL;
        while(node){
            if(node->val==val){
                if(prev!=NULL){
                    prev->next = node ->next;
                    node = node->next;
                }
                else{ //case where first node is val
                    head = head->next;
                    node = node->next;
                }
            }
            else{
                prev = node;
                node = node->next;
            }
            
        }
        return head;
        
    }
};