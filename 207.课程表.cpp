/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //拓扑排序
        //图用邻接表存储
        //建立队列存储入度为0的点
        //每次出队时，相当于将该节点删除
        //如果出队列的个数等于课程数，即无环，否则有环存在，无解
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> indg(numCourses, 0);

        for(int i = 0; i < prerequisites.size(); i++){
            int x = prerequisites[i][0], y = prerequisites[i][1];
            graph[y].push_back(x);
            indg[x]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indg[i] == 0) q.push(i);
        }

        int count = 0;
        while (!q.empty()){
            int x = q.front();
            q.pop();
            for(int i = 0; i < graph[x].size(); i++){
                indg[graph[x][i]] --;
                if(indg[graph[x][i]] == 0) q.push(graph[x][i]);
            }
            count++;
        }

        return count == numCourses;
    }
};

// @lc code=end

