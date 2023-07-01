#include <stdio.h>
#include <math.h>

int minCostClimbingStairs(int* cost, int costSize);

int main () {
    int cost[10] = {10, 15, 20};
    int costSize = 3;

    minCostClimbingStairs(cost, costSize);
    printf("\n");
}

int minCostClimbingStairs(int* cost, int costSize){
    int costR[costSize];

    for (int i = 2; i < costSize; i++) {
        if (cost[i - 1] < cost [i - 2]) cost[i] += cost[i - 1];
        else cost[i] += cost[i - 2];
    }
    printf("%d - %d\n", cost[costSize - 1], cost[costSize - 2]);

    if (cost[costSize - 1] < cost[costSize - 2]) return cost[costSize - 1];
    else return cost[costSize - 2];
}