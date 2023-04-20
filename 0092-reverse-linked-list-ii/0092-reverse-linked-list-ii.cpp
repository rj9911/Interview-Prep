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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL) return NULL;
        
        vector<int> a1,a2;
        ListNode* temp=head;
        while(temp){
            a1.push_back(temp->val);
            temp=temp->next;
        }
        
        int l=left-1,r=right-1;
        while(l<r){
            swap(a1[l],a1[r]);
            l++; r--;
        }
        
        ListNode* temp1=head;
        int i=0;
        while(temp1&&i<a1.size()){
            temp1->val=a1[i++];
            temp1=temp1->next;
        }
        
        return head;
    }
};