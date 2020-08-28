/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//迭代方法
/*
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return NULL;
        ListNode* i = head;
        ListNode* j = i->next;
        while(j != NULL){
            ListNode* t = j->next;
            j->next = i;
            i = j;
            j = t;
        }
        head->next = NULL;
        return i;
    }
};
*/

//递归方法，就是将给定的reverseList函数看成一个接口进行递归
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* tail = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return tail;
    }
};

// @lc code=end

