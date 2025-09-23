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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        ListNode*front=head;
        ListNode*back=head;
        int n=1;
        while(front->next!=NULL){
            front=front->next;
            n++;
        }
        int iterations=1;
        while(iterations!=n-(k%n)){
            back=back->next;
            iterations++;
        }
        front->next=head;
        head=back->next;
        back->next=NULL;

        return head;
    }
};