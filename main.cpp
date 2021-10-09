#include <bits/stdc++.h>

const double INF = 1e9;

using namespace std;

struct tree{
    long long x, y, r;
};

int main()
{
    long long x1, y1, x2, y2;
    scanf("%I64d%I64d%I64d%I64d", &x1, &y1, &x2, &y2);
    long long n;
    scanf("%I64d", &n);
    vector<vector<pair<double, long long>>> g(n+2);
    vector<tree> t(n+1);
    t[0] = {x2, y2, 0};
    for(long long i = 0; i<n; i++){
        long long xx, yy, rr;
        scanf("%I64d%I64d%I64d", &xx, &yy, &rr);
        t[i+1] = {xx, yy, rr};
    }
    for(long long i = 0; i<t.size(); i++){
        for(long long j = 0; j<t.size(); j++){
            if(i==j){
                continue;
            }
            g[i].push_back({max(sqrt((t[i].x-t[j].x)*(t[i].x-t[j].x)+(t[i].y-t[j].y)*(t[i].y-t[j].y))-t[i].r-t[j].r, 0.0), j});
        }
    }
    for(long long i = 0; i<n+1; i++){
        if(t[i].x<x1){
            g[i].push_back({max(0.0, (double)(y1-t[i].y-t[i].r)), n+1});
        } else if(t[i].y<y1){
            g[i].push_back({max(0.0, (double)(y1-t[i].x-t[i].x)), n+1});
        } else {
            g[i].push_back({max(0.0, sqrt((x1-t[i].x)*(x1-t[i].x)+(y1-t[i].y)*(y1-t[i].y))-t[i].r), n+1});
        }
    }
    vector<double> d(n+2, INF);
    d[0] = 0;
    set<pair<double, long long>> q;
    q.insert({d[0], 0});

	while (!q.empty()) {
		long long v = q.begin()->second;
		q.erase(q.begin());

		for (size_t j=0; j<g[v].size(); ++j) {
			double len = g[v][j].first;
            long long to = g[v][j].second;
			if (d[v] + len < d[to]) {
				q.erase ({d[to], to});
				d[to] = d[v] + len;
				q.insert ({d[to], to});
			}

		}
	}
    printf("%lf", d[n+1]);
    return 0;
}
