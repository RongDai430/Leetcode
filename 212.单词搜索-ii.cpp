/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */

// @lc code=start
//利用字典树存储单词+dfs解决
//遍历二维网络中的每个点，作为起点，开始dfs，利用字典树判断是否是合法单词
//字典树相当于一个剪枝过程
//对于本例，字典树中不需要is_word，因为最后需要输出单词，所以用id会更方便
class Solution {
public:
    struct Node{
        int id;
        Node* path[26];
        Node(){
            id = -1;
            for(int i = 0; i < 26; i++) path[i] = NULL;
        }
    }* root;


    int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};

    vector<string> ans;
    vector<vector<bool>> vis;
    set<string> myset;

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        vis = vector<vector<bool>> (board.size(), vector<bool>(board[0].size(), false));

        //插入字典树
        root = new Node();
        for(int i = 0; i < words.size(); i++){
            Node* p = root;
            for(int j = 0; j < words[i].size(); j++){
                int t = words[i][j] - 'a';
                if(p->path[t] == NULL) p->path[t] = new Node();
                p = p->path[t];
            }        
            p->id = i;
        }

        //dfs
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[i].size(); j++){
                //注意，第一次开始dfs时候的初始值不能设置为root，因为已经遍历了该字母
                dfs(i,j,root->path[board[i][j]-'a'],words,board);
            }
        return ans;
    }

    void dfs(int x, int y, Node* p, vector<string>& words,vector<vector<char>>& board){

        if(p == NULL) return;

        vis[x][y] = true;
        if(p->id != -1){
            string temp = words[p->id];
            if(myset.find(temp) == myset.end()){
                myset.insert(temp);
                ans.push_back(temp);
            }
        }

        for(int i = 0; i < 4; i++){
            int xx = x + dx[i], yy = y + dy[i];
            if(xx >= 0 && xx < vis.size() && yy >= 0 && yy < vis[0].size() && vis[xx][yy] == false){

                //特别需要注意，同样的问题再次出现
                //这里不能写成这样
                /*  
                    p =  p->path[board[xx][yy] - 'a'];
                    dfs(xx, yy,p , words, board);
                */
                //原因在于在dfs过程中，对于每一个点，可能有多个可选择的方向
                //在每一步迭代时p需要指代的是还未迈出这一步的p
                //如果写成上式，那么修改了p，在遍历到下一个可能的方向时，就会出现越界问题
                dfs(xx, yy, p->path[board[xx][yy] - 'a'], words, board);
            }   
        }
        vis[x][y] = false;
    }
};

// @lc code=end

