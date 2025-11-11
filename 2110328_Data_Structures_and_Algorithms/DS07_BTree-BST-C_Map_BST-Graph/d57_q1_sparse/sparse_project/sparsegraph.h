#ifndef __SPARSE_GRAPH_H__
#define __SPARSE_GRAPH_H__

// Your code here
#include <set>
using namespace std;

class SparseGraph
{
public:
    SparseGraph()
    {
        // Your code here
        mSize = 3;
        isTransposed = false;
    }

    SparseGraph(int n_in)
    {
        // Your code here
        mSize = n_in;
        isTransposed = false;
    }

    SparseGraph(const SparseGraph &G)
    {
        // Your code here
        mSize = G.mSize;
        isTransposed = G.isTransposed;
        mEdges = G.mEdges;
    }

    void AddEdge(int a, int b)
    {
        // Your code here
        if (isTransposed)
            mEdges.insert({b, a});
        mEdges.insert({a, b});
    }

    void RemoveEdge(int a, int b)
    {

        // Your code here
        if (isTransposed)
            mEdges.erase({b, a});
        mEdges.erase({a, b});
    }

    bool DoesEdgeExist(int a, int b) const
    {
        // Your code here
        if (isTransposed)
            return mEdges.find({b, a}) != mEdges.end();
        return mEdges.find({a, b}) != mEdges.end();
    }

    SparseGraph Transpose() const
    {
        // Your code here
        SparseGraph ans = *this;
        ans.isTransposed = !ans.isTransposed;
        return ans;
    }

protected:
    // Your code here
    bool isTransposed;
    int mSize;
    set<pair<int, int>> mEdges;
};
#endif // __SPARSE_GRAPH_H__
