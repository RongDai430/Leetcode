/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
//这里填你的代码^^
//注意代码要放在两组三个点之间，才可以正确显示代码高亮哦~
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map <char, char> hash;
        set<char> myset;
        for(int i = 0; i < s.size(); i++){
            if(hash.find(s[i]) == hash.end()){
                hash[s[i]] = t[i];
                if(myset.find(t[i]) != myset.end())
                    return false;
                myset.insert(t[i]);
            }
            else{
                if(hash[s[i]] != t[i]) return false;
            }
        }
        return true;
    }
};
// @lc code=end

