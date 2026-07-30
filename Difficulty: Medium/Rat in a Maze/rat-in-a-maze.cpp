class Solution {
  public:
  
    void solve(vector<vector<int>>& maze,int i,int j,int n,string path,vector<string>& ans){
        
        if(i<0||j<0||i>=n||j>=n||maze[i][j]==0)
            return;
            
        if(i==n-1&&j==n-1){
            ans.push_back(path);
            return;
        }
        
        maze[i][j]=0;
        
        solve(maze,i+1,j,n,path+'D',ans);
        solve(maze,i,j-1,n,path+'L',ans);
        solve(maze,i,j+1,n,path+'R',ans);
        solve(maze,i-1,j,n,path+'U',ans);
        
        maze[i][j]=1;
    }
  
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> ans;
        int n=maze.size();
        
        if(maze[0][0]==0||maze[n-1][n-1]==0)
            return ans;
            
        solve(maze,0,0,n,"",ans);
        
        return ans;
    }
};