#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* removeKdigits(char* num, int k) {
    int len = strlen(num);
    if (k >= len) {
        char* res = (char*)malloc(2);
        strcpy(res, "0");
        return res;
    }
    
    int remain = len - k;
    char* stack = (char*)malloc(len + 1);
    int top = -1;
    
    for (int i = 0; i < len; ++i) {
        while (k > 0 && top >= 0 && stack[top] > num[i]) {
            top--;
            k--;
        }
        stack[++top] = num[i];
    }
    
    stack[remain] = '\0';  // Truncate to remaining length
    
    // Remove leading zeros
    int start = 0;
    while (start < remain && stack[start] == '0') {
        start++;
    }
    
    if (start == remain) {  // All zeros case
        char* res = (char*)malloc(2);
        strcpy(res, "0");
        free(stack);
        return res;
    }
    
    char* result = (char*)malloc(remain - start + 1);
    strcpy(result, stack + start);
    free(stack);
    return result;
}

int main() {
    
    char num[] = "1432219"; // given exmaple in HW pdf
    int k = 3;
    
    printf("Input: num = \"%s\", k = %d\n", num, k);
    char* result = removeKdigits(num, k); // greedy approach 
    printf("Output: \"%s\"\n", result);  // Output: "1219"
    
    free(result); //unallocate
    return 0;
}
