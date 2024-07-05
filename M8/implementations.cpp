#include "data.h"
#include <iostream>
#define MAX_VERTICES 100
#include <queue>

using namespace std;

    Graph::Graph(int vertices) {
        num_vertices = vertices;
        for (int i = 0; i < num_vertices; i++) {
            for (int j = 0; j < num_vertices; j++) {
                adj_matrix[i][j] = 0;
            }
        }
    }

    void Graph::add_edge(int u, int v) {
        adj_matrix[u][v] = 1;
        adj_matrix[v][u] = 1; // Assuming an undirected graph
    }

    void Graph::remove_edge(int u, int v) {
        adj_matrix[u][v] = 0;
        adj_matrix[v][u] = 0;
    }

    void Graph::bfs(int start_vertex) {
        bool visited[MAX_VERTICES] = {false};
        
        queue<int> q;
        visited[start_vertex] = true;
        q.push(start_vertex);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";
            for (int v = 0; v < num_vertices; v++) {
                if (adj_matrix[u][v] == 1 && !visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }

    void Graph::dfs_traversal(int start_vertex) {
        bool visited[MAX_VERTICES] = {false};
        dfs(start_vertex, visited);
        cout << endl;
    }

    void Graph::dfs(int vertex, bool visited[]) {
        visited[vertex] = true;
        cout << vertex << " ";
        for (int i = 0; i < num_vertices; i++) {
            if (adj_matrix[vertex][i] == 1 && !visited[i]) {
                dfs(i, visited);
            }
        }
    }

    void Graph::display_matrix() {
        for (int i = 0; i < num_vertices; i++) {
            for (int j = 0; j < num_vertices; j++) {
                cout << adj_matrix[i][j] << " ";
            }
            cout << endl;
        }
    }


