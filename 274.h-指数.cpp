/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
 */

// @lc code=start
class Solution {
public:
    /*int hIndex(vector<int>& citations) {
        //每一次循环减少一次计数，统计当前是否满足条件
        //O(n^2)
        int ans = 0;
        int cnt = citations.size();
        for(int i = 1; i <= citations.size(); i++){
            for(int j = 0; j < citations.size(); j++){
                --citations[j];
                if(citations[j] == -1) cnt--;
            }
            if(cnt >= i) ans = max(ans, i);
        }
        return ans;
    }*/
    int hIndex(vector<int>& citations) {
        //考虑先进行排序，后进行遍历
        //O(nlogn)
        //找到第一个size() - i <= nums的值即可
        //[0,1,3,5,6]
        //{5,4,3,2,1}

        int ans = 0;
        sort(citations.begin(), citations.end());

        for(int i = 0; i < citations.size(); i++){
            if(citations.size() - i <= citations[i]){
                ans = citations.size() - i;
                break;
            }
        }
        return ans;
    }
};

// @lc code=end

