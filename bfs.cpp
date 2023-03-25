//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
     /*
    bfs
    step 1--> front or u bole ekta variable niye setar modhe queue r first element ke store korbo
    
    step 2--> queue theke element take pop kore debo
    (front r modhe jei element ta ache seta ke queue theke pop korar kotha bolchi)
    
    step 2.1--> ekta loop chaliye dilam front or u r adjacent element gulo r jonno 
    
    step 3--> visited array te giye element take true mark kore dilam
    
    step 4--> element take result array te push kore print kore dilam
    
    step 5--> first or u r modhe je element ta ache setar adjacency element gulo ke queue te push kore dilam
    */
    
    void BFS( unordered_map<int, vector<int>> &adj,int u,vector<bool>&visited,vector<int>&result){
     queue<int>que;
     que.push(u);
     visited[u]=true;
     result.push_back(u);
     
     while(!que.empty()){
         int u=que.front();
         que.pop();
         
         for(int &v: adj[u]){
             if(!visited[v]){
                 que.push(v);
                 visited[v]=true;
                 result.push_back(v);
                 
             }
         }
     }
     
     
    }
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> mp[]) {
        // Code here
           unordered_map<int, vector<int>> adj;
        for(int u=0;u<V;u++){ 
           
            for(auto v = mp[u].begin(); v!= mp[u].end();v++){
          
                adj[u].push_back(*v);
         
            }
        }
        vector<int>result;
        vector<bool>visited(V,false);
        
        BFS(adj,0,visited,result);
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
