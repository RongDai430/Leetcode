/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class Trie {
private:
    //字典树的实现是一种字典树的数据结构
    struct Node{
        bool is_word;
        Node* path[26];
        //结构体(类)初始化函数
        Node(){
            is_word = false;
            for(int i = 0; i < 26; i++) path[i] = NULL;
        }
    };
    Node* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* p = root;
        for(auto c : word){
            int t = c - 'a';
            if(p->path[t] == NULL)
                p->path[t] = new Node();
            p = p->path[t];
        }
        p->is_word = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* p = root;
        for(auto c : word){
            int t = c - 'a';
            if(p->path[t] == NULL) return false;
            p = p->path[t];
        }
        return p->is_word;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* p = root;
        for(auto c : prefix){
            int t = c - 'a';
            if(p->path[t] == NULL) return false;
            p = p-> path[t];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

