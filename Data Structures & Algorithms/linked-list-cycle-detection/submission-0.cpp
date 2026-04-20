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
    bool hasCycle(ListNode* head) {
        ListNode* temp = head;
        unordered_map<ListNode*, int> mpp;
        while(temp!= nullptr){
            if(mpp.find(temp) != mpp.end()){
                return true;
                break;
            }
            mpp[temp]++;
            temp = temp->next;       
        }
        return false;
    }
};
