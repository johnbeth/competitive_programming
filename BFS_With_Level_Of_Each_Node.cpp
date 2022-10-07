#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // Enter the number of nodes
    int n;
    cin >> n;
    vector<vector<int>> vec;
    vec.resize(n + 1);
    for (int i = 1; i < n + 1; i++)
    {
        // Enter the number of connected nodes
        int a;
        cin >> a;
        for (int j = 0; j < a; j++)
        {
            // Enter the which node is connected to i-th node
            int b;
            cin >> b;
            vec[i].push_back(b);
        }
    }
    // Enter the source node
    int source;
    cin >> source;

    if (source > n)
    {
        cout << "error\n";
    }
    else
    {
        int level[n + 1];
        vector<int> visit(n + 1, -1);
        queue<int> que;
        que.push(source);
        level[source] = 0;
        visit[source] = 1;
        while (que.empty() == false)
        {
            int t = que.front();
            que.pop();
            for (int i = 0; i < vec[t].size(); i++)
            {
                if (visit[vec[t][i]] == -1)
                {
                    que.push(vec[t][i]);
                    visit[vec[t][i]] = 1;
                    level[vec[t][i]] = level[t] + 1;
                }
            }
        }
        // you can print level of each node
        //cout<<level[4]<<"\n";
    }
    return 0;
}
