#include <stdio.h>

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize < 2) return 0; // cant find max profit in this case 
    
    int total_profit = 0;
    for (int i = 1; i < pricesSize; ++i) { //search everything to check across daily profits in a greedy style 
        int daily_change = prices[i] - prices[i - 1];
        if (daily_change > 0) {
            total_profit += daily_change; //record profit 
        }
    }
    return total_profit;
}

int main() {
    // Example test case
    int prices[] = {7, 1, 5, 3, 6, 4};
    int size = sizeof(prices) / sizeof(prices[0]); // get index count
    
    printf("Input Prices: [");
    for (int i = 0; i < size; ++i) { //print all our starting exmaple data 
        printf("%d%s", prices[i], (i < size - 1) ? ", " : "]\n");
    }
    
    int result = maxProfit(prices, size); //execute max profit greedy search on it 
    printf("Maximum Profit: %d\n", result);  // Output: 7
    
    return 0;
}
