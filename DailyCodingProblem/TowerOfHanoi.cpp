//
// Created by chris on 2/21/2021.
//
//C++ recursive function to
// solve tower of hanoi puzzle
/*
 * f there is more than 1 disk, then we can do the following:
Recursively move n - 1 disks from the source stack to the spare stack
Move the last (biggest) disk from the source stack to the target stack
Recursively move all n - 1 disks from the spare stack to the target stack
 */
#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char from_rod,
                  char to_rod, char aux_rod)
{
    if (n == 1)
    {
        cout << "Move disk 1 from rod " << from_rod <<
             " to rod " << to_rod<<endl;
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    cout << "Move disk " << n << " from rod " << from_rod <<
         " to rod " << to_rod << endl;
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

// Driver code
int main()
{
    int n = 3; // Number of disks
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods
    return 0;
}


