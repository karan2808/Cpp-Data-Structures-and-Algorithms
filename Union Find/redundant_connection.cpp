#include <iostream>
#include <vector>
using namespace std;

// Disjoint Set Union
class DSU {
    int *parent;
    int *rank;
    public:
    DSU (int max_size) {
        parent = new int[max_size + 1];
        rank = new int[max_size + 1];
        // set the ranks to 0 and the parent of node as the node itself
        for (int i = 0; i <= max_size; i++) {
            rank[i] = 0;
            parent[i] = i;
        }
    }

    // find the parent of the node,
    // connect the nodes to the main parent
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool union_(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
        // we find a cycle, since 2 nodes have same parents
        if (x_parent == y_parent) {
            return true;
        }
        // get the ranks and perform union
        int rank_x = rank[x_parent], rank_y = rank[y_parent];

        // new parent should be the node with greater rank
        if (rank_x < rank_y) {
            parent[x_parent] = y_parent;
        }
        else if (rank_x > rank_y) {
            parent[y_parent] = x_parent;
        }
        else {
            parent[x_parent] = y_parent;
            rank[x_parent]++;
        }
        return false;
    }
};


class Find_Redundant {
    public:
    vector<int>find_redundant_connection(vector<vector<int>>& edges) {
        vector<int> connection;
        DSU union_find(edges.size());
        // go through each edge to detect if two nodes have a common parent
        for (auto edge: edges) {
            if (union_find.union_(edge[0], edge[1])) {
                connection.push_back(edge[0]);
                connection.push_back(edge[1]);
                // break;
            }
        }
        return connection;
    }
};

void print_vec(vector<int> conn) {
    for (auto v: conn) {
        cout << v << " ";
    }
    cout << endl;
}

int main() {
    Find_Redundant find;
    vector<vector<int>>case_1 = {{1,2},{1,3},{2,3}};
    vector<vector<int>>case_2 = {{1,2},{1,3},{1,4},{1,5},{2,6},{6,4}};
    vector<vector<int>>case_3 = {{1,2},{2,3},{3,4},{1,5},{2,6},{6,4},{4,5}};
    vector<int>conn1 = find.find_redundant_connection(case_1);
    vector<int>conn2 = find.find_redundant_connection(case_2);
    vector<int>conn3 = find.find_redundant_connection(case_3);
    print_vec(conn1);
    print_vec(conn2);
    print_vec(conn3);
    return 0;
}