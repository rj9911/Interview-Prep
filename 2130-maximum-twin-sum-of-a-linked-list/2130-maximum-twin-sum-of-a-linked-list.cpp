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
    ListNode *reverseLL(ListNode *head,ListNode *prev){
       if(head==NULL) return prev;

       ListNode *temp = head->next;
       head->next=prev;
       return reverseLL(temp,head);
   } // Recursive way to reverse LL.
   int pairSum(ListNode* head) {
        //find the mid of the LL:
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
       
        //slow is my mid value:
        ListNode *dummy = reverseLL(slow,NULL);
        
        ListNode *start = head;
        int maxx = 0;
        while(dummy!=NULL){
            int val1 = start->val;
            int val2 = dummy->val;
            int total = val1+val2;
            maxx = max(maxx,total);
            start=start->next;
            dummy=dummy->next;
        }
       return maxx;
    }
};