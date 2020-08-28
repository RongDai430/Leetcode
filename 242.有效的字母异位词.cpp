/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        //哈希表即可
        if(s.size() != t.size()) return false;
        unordered_map<char,int> hash;
        for(int i = 0; i < s.size(); i++){
            hash[s[i]]++;
        }
        for(int j = 0; j < t.size(); j++){
            if(hash.find(t[j]) == hash.end()) return false;
            hash[t[j]]--;
            if(hash[t[j]] < 0) return false;
        }
        return true;
    }
};

// @lc code=end

