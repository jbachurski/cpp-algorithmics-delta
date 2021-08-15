// -*- ktl/graph/bipartite_matching.cpp -*-

#include <vector>
#include <cstddef>
#include <cstdint>

using std::vector; using std::size_t;

struct bipartite_matching
{
    using graph_t = vector<vector<size_t>>;

    const graph_t& graph;
    size_t n;
    vector<bool> vis;
    vector<size_t> match;

    bipartite_matching(const graph_t& _graph)
        : graph(_graph), n(graph.size()), vis(n), match(n, SIZE_MAX) {}

    bool dfs_match(size_t u)
    {
        if(vis[u])
            return false;
        vis[u] = true;
        for(auto v : graph[u])
        {
            if(match[v] == SIZE_MAX)
            {
                match[u] = v; match[v] = u;
                return true;
            }
        }
        for(auto v : graph[u])
        {
            if(dfs_match(match[v]))
            {
                match[u] = v; match[v] = u;
                return true;
            }
        }
        return false;
    }

    vector<size_t> operator() ()
    {
        fill(match.begin(), match.end(), SIZE_MAX);

        bool any = true;
        while(any)
        {
            any = false;
            fill(vis.begin(), vis.end(), false);
            for(size_t u = 0; u < n; u++)
                if(match[u] == SIZE_MAX and dfs_match(u))
                    any = true;
        }
        return match;
    }
};

// -$- ktl/graph/bipartite_matching.cpp -$-

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    size_t T;
    cin >> T;

    for(size_t no = 1; no <= T; no++)
    {
        size_t n, k;
        cin >> n >> k;

        vector<vector<uint>> A(n, vector<uint>(k));
        for(auto& row : A)
            for(auto& a : row)
                cin >> a;

        auto ok = [&](size_t u, size_t v) {
            for(size_t i = 0; i < k; i++)
                if(A[u][i] >= A[v][i])
                    return false;
            return true;
        };

        vector<vector<size_t>> graph(2*n);
        for(size_t u = 0; u < n; u++)
            for(size_t v = 0; v < n; v++)
                if(ok(u, v))
                    graph[u].push_back(v+n), graph[v+n].push_back(u);

        auto match = bipartite_matching{graph}();
        auto result = count(match.begin(), match.begin() + n, SIZE_MAX);

        cout << "Case #" << no << ": " << result << endl;
    }
}
