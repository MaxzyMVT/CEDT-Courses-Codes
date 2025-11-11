#ifndef __DENSE_GRAPH_H__
#define __DENSE_GRAPH_H__

// Your code here
#include <vector>
using namespace std;
class DenseGraph
{
public:
    DenseGraph()
    {
        // Your code here
        mSize = 3;
        Edges.assign(3, vector<bool>(3, false));
    }

    DenseGraph(int n_in)
    {
        // Your code here
        mSize = n_in;
        Edges.assign(n_in, vector<bool>(n_in, false));
    }

    DenseGraph(const DenseGraph &G)
    {
        // Your code here
        mSize = G.mSize;
        Edges = G.Edges;
    }

    void AddEdge(int a, int b)
    {
        // Your code here
        Edges[a][b] = 1;
    }

    void RemoveEdge(int a, int b)
    {
        // Your code here
        Edges[a][b] = 0;
    }

    bool DoesEdgeExist(int a, int b) const
    {
        // Your code here
        return Edges[a][b];
    }

    DenseGraph Transpose() const
    {
        // Your code here
        DenseGraph ans = *this;
        for (int i = 0; i < ans.mSize; i++)
        {
            for (int j = i + 1; j < ans.mSize; j++)
            {
                swap(ans.Edges[i][j], ans.Edges[j][i]);
            }
        }
        return ans;
    }

protected:
    int mSize;
    // Your code here
    vector<vector<bool>> Edges;
};
#endif // __DENSE_GRAPH_H__
