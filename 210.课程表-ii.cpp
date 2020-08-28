/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //需要输出顺序的拓扑排序
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> indg(numCourses, 0);
        for(int i = 0;i < prerequisites.size(); i++){
            int x = prerequisites[i][0], y = prerequisites[i][1];
            graph[y].push_back(x);
            indg[x]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indg[i] == 0) q.push(i);
        }

        vector<int> ans;

        int count = 0;  //判断是否存在环
        while(!q.empty()){
            count++;
            int x = q.front();
            q.pop();
            ans.push_back(x);
            for(int i = 0; i < graph[x].size(); i++){
                indg[graph[x][i]]--;
                if(indg[graph[x][i]] == 0) q.push(graph[x][i]);
            }
        }

        if(count == numCourses) return ans; else return vector<int>{};

    }
};

// @lc code=end

