question link-
  https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  void DFS( unordered_map<int, vector<int>> adj,int u,vector<bool>&visited,vector<int>&result){
      if(visited[u]==true){
        //   dry run for 0 
        // as o vsisted noye tai ekhane dhukbena
          //   dry run for 2 
        // as 2 vsisted noye tai ekhane dhukbena
           return;
          
      }
      visited[u]=true;
    //   marking 0 as visited
    //   marking 2 as visited
      result.push_back(u);
    //   result e 0 ke push korlam
    //   result e 2 ke push korlam
      
      for(int &v : adj[u]){
        //   adj[u]= adj[0]==[2,3,1]
        // prothome &v=2
        // tarpor &v=3
        // tarpor &v=1
        
        //   adj[u]= adj[2]==[0,4]
        // prothome &v=0
        // tarpor &v=4
//  2nd node r jonno jehetu 0 visisted tai amra if section e dhukbona
// tai &v= 4 r jonnno check korbo eibar
          if(!visited[v]){
            //   jehetu 2 visited noye tai ekhane dhuklam
            //   jehetu 4 visited noye tai ekhane dhuklam
              DFS(adj,v,visited,result);
            //   ebar 2 node tar opor dfs apply korbo
            //   4 node tar opor dfs apply korbo
          }
      }
           
       
           
  }

    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> mp[]) {
        // mp[0]--> 2,3,1  
        // mp[1]--> 0
        // mp[2]--> 0,4
        // mp[3]--> 0
        // mp[4]--> 2
        // Code here
        unordered_map<int, vector<int>> adj;
        for(int u=0;u<V;u++){ 
            // u=0, V=5 , 0<5 
            for(auto v = mp[u].begin(); v!= mp[u].end();v++){
                // v=mp[u].begin()=mp[0].begin()=2 !mp[u].end() = 2,3,1 i.e. 1 r porer element that is a garbage element full stop . opdi cholbe as 0 based indexing v++ 
            //   v=2
            //   v=3
            //   v=1
                adj[u].push_back(*v);
                // adj[o].push_back(*v==2) 0-->2
                // adj[o].push_back(*v==3) 0-->3
                // adj[o].push_back(*v==1) 0-->1
            }
        }
        vector<int>result;
        vector<bool>visited(V,false);
        
        DFS(adj,0,visited,result);
        return result;
    
    }
};
