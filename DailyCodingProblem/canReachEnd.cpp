#include <bits/stdc++.h>
using namespace std;

bool canReachEnd(vector<int> hops)
{
    int steps_left = 1;
    for (int i = 0; i < hops.size()-1; i++)
    {
        steps_left = max(steps_left-1, hops[i]);
        if (steps_left == 0)
            return false;
    }

    return true;
}
int main(void)
{
    vector<int> hops1{2, 0, 1, 0};
    vector<int> hops2{1,1,0,1};

    cout << canReachEnd(hops1) << endl;
    cout << canReachEnd(hops2) << endl;


}
