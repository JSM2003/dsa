#include<bits/stdc++.h>
#include "graph.h"
using namespace std;

vector<vector<bool>> Graph::input_graph(){
            int n;
            cout << "\nEnter number of nodes in graph: " <<ends;
            cin >>n;

            cout << "\nEnter a valid adjacency matrix:\n\t" << endl;
            vector<vector<bool>> adj_mtrx;

            for(int i = 0; i < n; ++i){
                vector<bool> temp;
                int edge;
                for(int j = 0; j < n; ++j){
                    cin >> edge;
                    temp.push_back(edge);
                }

                adj_mtrx.push_back(temp);
            }

            return adj_mtrx;
        }

void Graph::create_from_adj_matrix(){
            vector<vector<bool>> adj_mtrx = input_graph();

            for(int i = 0; i < adj_mtrx.size(); ++i){
                llNode* node = new llNode(i+1);
                AdjacencyList.push_back(new LinkedList(node));
            }

            for(int i = 0; i < adj_mtrx.size(); ++i){
                for(int j = i+1; j < adj_mtrx.size(); ++j){
                    if(adj_mtrx[i][j]){
                        AdjacencyList[i]->insert(j+1);
                        AdjacencyList[j]->insert(i+1);
                    }
                }
            }
        }

void Graph::print_adj_list(){
            cout << "\n\n" << endl;
            for(int i = 0; i < AdjacencyList.size(); ++i){
                llNode* curr = AdjacencyList[i]->head;

                while(curr->next != NULL){
                    cout << curr->val << " -> " << ends;
                    curr = curr->next;
                }
                cout << curr->val << '\n' <<endl;
            }
        }
