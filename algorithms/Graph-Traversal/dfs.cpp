#include<bits/stdc++.h>
#include "../../data-structures/Graph/graph.h"

using namespace std;

int search_unvisited(vector<bool>& visited){
    int ans;
    for(int i = 0; i < visited.size(); ++i){
        if(!visited[i]){
            ans = i;
            break;
        }
    }

    return ans;
}

bool is_all_visited(vector<bool>& visited){
    bool ans = true;

    for(int i = 0; i < visited.size(); ++i){
        if(!visited[i]){
            ans = false;
            break;
        }
    }

    return ans;
}

vector<vector<int>> dfs(Graph* g){
    vector<bool> visited(g->AdjacencyList.size(),false);
    vector<int> parent(g->AdjacencyList.size(), -1);
    vector<int> ans;
    stack<int> curr_stck;

    curr_stck.push(1);
    visited[0] = true;
    ans.push_back(curr_stck.top());
    bool all_visited = false;
    
    while(!all_visited){
        if(curr_stck.empty()){
            int unv_node = search_unvisited(visited);
            curr_stck.push(unv_node+1);
            visited[unv_node] = true;
            ans.push_back(curr_stck.top());
        }

        else{
            int stck_top_idx = curr_stck.top()-1;
            bool all_neighbors_visited = true;
            llNode* curr_ptr = g->AdjacencyList[stck_top_idx]->head;

            while(curr_ptr != NULL){
                if(!visited[curr_ptr->val-1]){
                    all_neighbors_visited = false;
                    break;
                }
                curr_ptr =  curr_ptr->next;
            }

            if(all_neighbors_visited)
                curr_stck.pop();

            else{
                curr_stck.push(curr_ptr->val);
                visited[curr_ptr->val-1] = true;
                parent[curr_ptr->val-1] = stck_top_idx;
                ans.push_back(curr_stck.top());
            }
        }

        all_visited = is_all_visited(visited);
    }

    vector<vector<int>> res = {ans,parent};
    return res;

}

int main(){

    Graph* g = new Graph;
    g->create_from_adj_matrix();

    vector<vector<int>> dfs_g = dfs(g);

    cout << "Traversal array: " << ends;
    for(int i = 0; i < dfs_g[0].size(); ++i){
        cout << dfs_g[0][i] << " " << ends;
    }
    cout << "\n Parent array : " << ends;
    for(int i = 0; i < dfs_g[1].size(); ++i){
        cout << dfs_g[1][i]+1 << " " << ends;
    }
    cout << endl;
    return 0;
}