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
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        priority_queue<int, vector<int>, greater<int>> minh;

        for (auto &it : lists)
        {

            ListNode *node = it;
            while (node)
            {
                minh.push(node->val);
                node = node->next;
            }
        }

        ListNode *ans = new ListNode(0);
        ListNode *cur = ans;

        while (minh.size() > 0)
        {
            cur->next = new ListNode(minh.top());
            cur = cur->next;
            minh.pop();
        }
        return ans->next;
    }
};