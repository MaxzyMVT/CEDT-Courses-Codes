#include <vector>
#include <set>
using namespace std;

template <typename T>
vector<T> Union(const vector<T> &A, const vector<T> &B)
{
    vector<T> v(A);
    set<T> bucket(A.begin(), A.end());

    for (auto e : B)
    {
        auto ret = bucket.insert(e);
        if (ret.second) // insert succeed?
            v.push_back(e);
    }

    return v;
}

template <typename T>
vector<T> Intersect(const vector<T> &A, const vector<T> &B)
{
    vector<T> v;
    set<T> bucket(B.begin(), B.end());

    for (auto e : A)
    {
        auto ret = bucket.insert(e);
        if (!ret.second) // insert failed?
            v.push_back(e);
    }
    return v;
}
