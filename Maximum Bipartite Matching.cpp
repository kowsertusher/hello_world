#include <iostream>
#include <string.h>
using namespace std;
#define M 6
#define N 6
bool bpm(bool bpGraph[M][N], int u, bool seen[], int matchR[])
{
    // Try every job one by one
    for (int v = 0; v < N; v++)
    {
        if (bpGraph[u][v] && !seen[v])
        {
            seen[v] = true;
            if (matchR[v] < 0 || bpm(bpGraph, matchR[v], seen, matchR))
            {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}
 
// Returns maximum number of matching from M to N
int maxBPM(bool bpGraph[M][N])
{
    // An array to keep track of the applicants assigned to
    // jobs. The value of matchR[i] is the applicant number
    // assigned to job i, the value -1 indicates nobody is
    // assigned.
    int matchR[N];
 
    // Initially all jobs are available
    memset(matchR, -1, sizeof(matchR));
 
    int result = 0; // Count of jobs assigned to applicants
    for (int u = 0; u < M; u++)
    {
        // Mark all jobs as not seen for next applicant.
        bool seen[N];
        memset(seen, 0, sizeof(seen));
 
        // Find if the applicant 'u' can get a job
        if (bpm(bpGraph, u, seen, matchR))
            result++;
    }
    return result;
}
 
// Driver program to test above functions
int main()
{
    bool bpgraph[M][N] =
    {
    {
        0,1,1,0,0,0
    },
    {
        1,0,0,1,0,0
    },
    {
        0,0,1,0,0,0
    },
    {
        0,0,1,1,0,0
    },
    {
        0,0,0,0,0,0
    },
    {
        0,0,0,0,0,1
    }
    };
 
    cout << "Maximum number of applicants that can get job is "
         << maxBPM(bpGraph);
 
    return 0;
}
