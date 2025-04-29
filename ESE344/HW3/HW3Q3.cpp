#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if string a is a subsequence of string b
bool isSubsequence(const char* a, const char* b) {
    if (strlen(a) == 0) return true;
    
    int i = 0, j = 0;
    while (i < strlen(a) && j < strlen(b)) {
        if (a[i] == b[j]) {
            i++;
        }
        j++;
    }
    
    return i == strlen(a);
}

// Function to find the length of the longest uncommon subsequence
int findLUSlength(char** strs, int strsSize) {
    int maxLen = -1;
    
    for (int i = 0; i < strsSize; i++) {
        bool isUncommon = true;
        
        for (int j = 0; j < strsSize; j++) {
            if (i != j && isSubsequence(strs[i], strs[j])) {
                isUncommon = false;
                break;
            }
        }
        
        if (isUncommon) {
            int len = strlen(strs[i]);
            if (len > maxLen) {
                maxLen = len;
            }
        }
    }
    
    return maxLen;
}

int main() {
    // Example 1
    char* strs1[] = {"aba", "cdc", "eae"};
    int size1 = 3;
    printf("Example 1 output: %d\n", findLUSlength(strs1, size1));
    
    // Example 2
    char* strs2[] = {"aaa", "aaa", "aa"};
    int size2 = 3;
    printf("Example 2 output: %d\n", findLUSlength(strs2, size2));
    
    // Example 3
    char* strs3[] = {"aabbcc", "aabbcc", "cb"};
    int size3 = 3;
    printf("Example 3 output: %d\n", findLUSlength(strs3, size3));
    
    return 0;
}
