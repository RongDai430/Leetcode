/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */

// @lc code=start
class WordDictionary {
private:
    struct Node{
        bool is_end;
        Node* path[26];
        Node(){
            is_end = false;
            for(int i = 0; i < 26; i++) path[i] = NULL;
        }
    }*root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node* p = root;
        for(auto c : word){
            int t = c - 'a';
            if(p->path[t] == NULL) p->path[t] = new Node();
            p = p->path[t];
        }
        p->is_end = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    //这一部分需要着重考察
    //如果碰到'.'，就dfs遍历Trie树里的所有分支
    bool search(string word) {
        return dfs(word, 0, root);
    }

    bool dfs(string& word, int index, Node* p){
        if(index == word.size()) return p->is_end;
        if(word[index] != '.'){
            if(p->path[word[index]-'a'] == NULL) return false;
            return dfs(word, index + 1, p->path[word[index]-'a']);
        }
        else{
            for(int i = 0; i < 26; i++){
                //这里需要注意不能写成
                //if(p->path[i] )
                //    return dfs(word, index + 1, p->path[i]);
                //如果写成了这样，那么返回值完全取决于第一个非空path
                //然而实际上需要判断所有可能的path，以及后续能否成功
                if(p->path[i] && dfs(word, index + 1, p->path[i]))
                    return true;
            }
            return false;
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

