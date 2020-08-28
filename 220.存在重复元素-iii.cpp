/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        //multiset  存储 下标 i - k 到 i - 1的值
        //multiset 底层是红黑树，故插入查找都是O(logk)
        //lower_bound(x)函数用来找某个已排序容器内第一个大于等于x的迭代器
        multiset<long long> hash;
        for(int i = 0; i < nums.size(); i++){
            if(hash.lower_bound((long long) (nums[i]) - t) != hash.end())
                if(*hash.lower_bound((long long )(nums[i]) - t) <= (long long) (nums[i]) + t) return true;
            hash.insert((long long)nums[i]);
            if(i >= k){
                hash.erase(hash.find((long long)nums[i - k]));
            }
        }
        return false;
    }
};

// @lc code=end

