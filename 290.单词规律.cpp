/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */

// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        //先保存每一个单词
        //逐个进行匹配
        vector<string> words;
        unordered_map<char,string> map;//匹配用
        unordered_set<string> set; //判重复
        string temp = "";
        str += " ";
        for(auto x : str){
            if(x ==' ') {words.push_back(temp); temp = "";}
            else temp += x;
        }

        if(pattern.size() != words.size()) return false;

        for(int i = 0; i < pattern.size(); i++){
            if(map.find(pattern[i]) == map.end()){
                map[pattern[i]] = words[i];
                if(set.find(words[i]) != set.end()) return false;
                set.insert(words[i]);
            }
            else{
                if(map[pattern[i]] != words[i]) return false;
            }
        }
        return true;
    }
};

// @lc code=end

