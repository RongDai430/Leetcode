/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //维护一个长度为2的priority_queue
        //priority_queue底层是由vector+堆算法实现的
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i = 0; i < k; i++){
            pq.push(nums[i]);
        }
        for(int i = k; i < nums.size(); i++){
            if(nums[i] > pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};
// @lc code=end

