#include <iostream>
#include <vector>
#include <utility>
using namespace std;

#define Edge pair<int, int> // weight, end-vertex
#define Graph vector<vector<Edge>>

bool findSum(int vertex, int sum, const int &target, const int &UpperBoundLeftPath, const vector<int> &MaxEdgeWeight, int &mark, const Graph &G, int &foundTargets, const vector<int> &targets)
{
    mark |= 1 << vertex;

    for (int i = 0; i < 8; i++)
    {
        if (sum == targets[i])
            foundTargets |= 1 << i;
    }

    if (sum == target)
        return true;

    bool found = false;
    for (auto [w, v] : G[vertex])
    {
        if (!found && ~mark & 1 << v && sum + w + UpperBoundLeftPath - MaxEdgeWeight[v] >= target && sum + w <= target)
            found |= findSum(v, sum + w, target, UpperBoundLeftPath - MaxEdgeWeight[v], MaxEdgeWeight, mark, G, foundTargets, targets);
        if (found)
            break;
    }

    mark &= ~(1 << vertex);
    return found;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<Edge> V;
    V.reserve(m);

    Graph G(n, V);
    vector<int> MxW(n);
    vector<int> K(8);

    int MxSum = 0, MxPath = 0;
    for (int i = 0; i < 8; i++)
        cin >> K[i], MxSum = max(MxSum, K[i]);

    while (m--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        G[a].push_back({w, b});
        G[b].push_back({w, a});
        MxW[a] = max(MxW[a], w);
        MxW[b] = max(MxW[b], w);
    }

    for (int w : MxW)
        MxPath += w;

    int foundTargets = 0;
    for (int i = 0; i < 8; i++)
    {
        int k = K[i];
        if (foundTargets & 1 << i)
        {
            cout << "YES\n";
            continue;
        }

        bool found = false;
        for (int u = 0; !found && u < n; u++)
        {
            int mark = 0;
            found |= findSum(u, 0, k, MxPath - MxW[u], MxW, mark, G, foundTargets, K);
        }
        cout << (found ? "YES\n" : "NO\n");
    }

    return 0;
}
/*
4 4
10 20 30 40 50 60 70 80
0 1 10
0 2 15
1 2 5
0 3 35

10 40
4188 3655 4033 3359 2192 3848 2853 1509
3 7 71
0 6 159
0 2 178
6 7 226
0 1 96
6 8 103
5 7 42
4 6 309
0 9 115
2 7 431
1 4 145
8 9 293
2 5 172
3 8 320
2 6 127
4 5 485
3 6 208
1 7 164
0 3 316
1 8 495
2 3 491
3 4 302
5 6 470
1 3 460
4 7 107
2 4 490
7 8 483
3 9 368
2 8 37
1 6 209
5 8 107
5 9 10
6 9 330
0 5 96
0 8 304
3 5 263
1 2 145
1 5 427
0 7 259
4 8 21

14 80
4495 3520 4312 3622 2832 3601 5840 539
12 13 4
0 10 74
8 11 495
1 3 223
1 10 429
6 10 209
4 5 272
7 11 278
2 8 364
4 12 343
5 8 370
2 9 228
0 3 86
9 11 173
2 4 468
11 12 46
3 8 194
2 6 402
4 9 94
0 7 52
1 4 278
0 8 186
2 3 19
0 6 438
3 11 428
6 8 419
11 13 387
4 13 94
3 13 291
5 13 122
5 6 6
6 12 361
3 4 6
4 11 94
1 7 483
0 2 158
4 10 272
2 7 372
1 11 160
7 8 216
7 13 8
8 9 473
9 12 76
6 9 149
3 9 207
5 10 498
3 5 216
1 5 130
6 11 214
9 10 274
4 6 450
0 11 378
1 13 410
8 12 1
8 10 378
9 13 474
0 9 427
3 7 267
1 12 440
2 13 12
1 2 417
10 13 496
0 12 218
5 11 427
2 12 402
0 4 154
3 10 205
0 13 236
3 12 328
2 5 92
1 9 132
7 10 269
0 5 54
6 7 193
4 7 329
2 10 153
5 9 133
2 11 382
6 13 344
8 13 379

*/