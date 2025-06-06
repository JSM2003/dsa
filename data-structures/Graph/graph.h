#include<bits/stdc++.h>
#include "utils.h"
using namespace std;

class Graph{
    public:
        vector<LinkedList*> AdjacencyList;
        vector<vector<bool>> input_graph();
        void create_from_adj_matrix();
        void print_adj_list();
};