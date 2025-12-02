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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = nullptr;
        ListNode* it = nullptr;
        while(true){
            ListNode* node = nullptr;
            int selected = -1;
            for(int i=0; i<lists.size(); i++){
                ListNode* current = lists[i];
                if(current && !node){
                    selected = i;
                    node = current;
                }
                else if(current && node && current->val < node->val){
                    selected = i;
                    node = current;
                }
            }
            if(selected != -1) lists[selected] = lists[selected] -> next;
            if(node){
                if (!ans){
                    ans = node;
                    it = ans;
                }
                else{
                    it -> next = node;
                    it = it -> next;
                    it -> next = nullptr;
                }
            }
            if(!node) break;
        }
        return ans;
    }
};