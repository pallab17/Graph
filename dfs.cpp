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
