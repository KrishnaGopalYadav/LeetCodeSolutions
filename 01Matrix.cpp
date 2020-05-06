// Problem Statement 
/*Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1.
 
Example 1:
Input:
[[0,0,0],
 [0,1,0],
 [0,0,0]]

Output:
[[0,0,0],
 [0,1,0],
 [0,0,0]]
Example 2:
Input:
[[0,0,0],
 [0,1,0],
 [1,1,1]]

Output:
[[0,0,0],
 [0,1,0],
 [1,2,1]]
 
Note:
1.	The number of elements of the given matrix will not exceed 10,000.
2.	There are at least one 0 in the given matrix.
3.	The cells are adjacent in only four directions: up, down, left and right.*/
Solution:
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(matrix[i][j]==0) {
                    q.push(make_pair(i,j));
                    dp[i][j]=0;
                }
            }
        }
        int c[]={-1,0,0,1};
        int d[]={0,-1,1,0};
        while(!q.empty()) {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++) {
                int dx=x+c[i];
                int dy=y+d[i];
                if(dx>=0&&dx<n&&dy>=0&&dy<m&&dp[dx][dy]>dp[x][y]+1){
                    dp[dx][dy]=1+dp[x][y];
                    q.push(make_pair(dx,dy));
                }
            }
        }
        return dp;
    }
};
