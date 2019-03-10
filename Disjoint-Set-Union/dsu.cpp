#include <iostream>
#include <vector>
#include <algorithm>

class DSU {
public:
    DSU(size_t size) {
        parent.assign(size, 0);
        rank.assign(size, 0);
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }
    
    ~DSU(){
        parent.clear();
        rank.clear();
    }

    int add_set() {
        int set_index = parent.size();
        parent.push_back(set_index);
        rank.push_back(set_index);
        return set_index;
    }

    int find_set(int v) {
        if (v == parent[v]) {
            return v;
        }
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (rank[a] < rank[b]) {
                std::swap(a, b);
            }
            parent[b] = a;
            if (rank[a] == rank[b]) {
                ++rank[a];
            }
        }
    }

private:
    std::vector<int> parent;
    std::vector<int> rank;
};