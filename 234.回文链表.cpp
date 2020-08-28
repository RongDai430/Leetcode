/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //如果使用O(n)时间复杂度和O(1)空间复杂度，那么必须要翻转链表
        if(head == NULL) return true;

        int len = 0;
        ListNode* t = head;
        while(t->next!=NULL){
            t = t->next;
            len++;
        }
        if(len == 0) return true;

        //找到第一个开始翻转的节点
        int mid = len / 2 + 1;
        ListNode* a = head;
        for(int i = 1; i <= mid; i++) a = a->next; 

        //此时a指向中间的节点
        //进行翻转
        ListNode* midp = a;
        ListNode* b = a->next;
        while(b != nullptr){
            ListNode* c = b->next;
            b->next = a;
            a = b;
            b = c;
        }
        midp->next = NULL;

        //判断回文，尾端节点是a
        ListNode* h = head;
        t = a;
        for(int i = 1; i <= (len + 1) / 2; i++){
            if(t->val != h->val) return false;
            t = t -> next; h = h -> next;
        }
        return true;

    }
};

// @lc code=end

