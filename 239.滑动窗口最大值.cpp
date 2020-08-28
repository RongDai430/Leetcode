/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //经典的单调队列的题
        //单调队列用来求区间的最值
        //把一定不可能是答案的值删除
        //保持单调下降
        //在队尾插入时，把队列中所有比他小的值删除
        //保持队列的单调性（队头最大）
        deque<int> q;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            if(q.front() == i - k) q.pop_front();
            while(!q.empty() && nums[q.back()] < nums[i]) q.pop_back();
            q.push_back(i);
            if(i >= k - 1) ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};

// @lc code=end

