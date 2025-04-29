#include <stdio.h>
#include <limits.h>

#define MAX_N 110
#define MAX_FLIGHTS 10010


typedef struct {
    int from, to, price; //custom stuct for each flifght 
} Flight;

int findCheapestPrice(int n, Flight flights[], int flightsSize, int src, int dst, int k) {
    int dist[MAX_N], temp[MAX_N];
    int i, j;  

    for (i = 0; i < n; ++i)
        dist[i] = INT_MAX / 2; // Use /2 to avoid overflow
    dist[src] = 0; //dist setup to hold the prices weve found so far 

    for (i = 0; i <= k; ++i) {
        // Copy current distances to temp
        for (j = 0; j < n; ++j)
            temp[j] = dist[j]; 
        // use bellman ford alg , given that we find a u to a v that is chepaer update the chepateas cost found so far

        for (j = 0; j < flightsSize; ++j) {
            int u = flights[j].from;
            int v = flights[j].to;
            int w = flights[j].price;
            if (temp[u] + w < dist[v])
                dist[v] = temp[u] + w;
        }
    }// return found relxed price from alg, if cost still is too high we default to error value of -1
    return dist[dst] >= INT_MAX / 2 ? -1 : dist[dst];
}

// Example usage
int main() { 
    Flight flights[] = {
        {0, 1, 100},
        {1, 2, 100},
        {2, 0, 100},
        {1, 3, 600},
        {2, 3, 200}
    };//setup struct data as given by the problem on pdf , flight data ll in one struct by sliced seperately
    int n = 4;
    int flightsSize = 5;
    int src = 0, dst = 3, k = 1;

    int result = findCheapestPrice(n, flights, flightsSize, src, dst, k);
    printf("%d\n", result); // expected Output: 700 for this problem set
    return 0;
}
