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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
       
        int n = 0;
        ListNode* curr = head;
        while (curr) {
            n++;  
            curr = curr->next;
        }
        
      
        int base = n / k;  
        int extra = n % k; 
  
        vector<ListNode*> res;
        curr = head;
        for (int i = 0; i < k; i++) {
            ListNode* part_head = curr; 
            int part_size = base + (extra > 0 ? 1 : 0);  
            extra--;  
            
            
            for (int j = 0; j < part_size - 1 && curr; j++) {
                curr = curr->next;
            }
            
            if (curr) {
                ListNode* next_part = curr->next; 
                curr->next = nullptr; 
                curr = next_part;  
            }
            
            res.push_back(part_head); 
        }
        
        return res;
    }
};