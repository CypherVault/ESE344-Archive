#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 10000
#define MAX_CHAR 26

int leastInterval(char* tasks, int tasksSize, int n) {
    // Count frequency of each task
    int freq[MAX_CHAR] = {0};
    int maxFreq = 0;
    int maxCount = 0;
    
    // Count frequencies
    for (int i = 0; i < tasksSize; i++) {
        freq[tasks[i] - 'A']++;
        if (freq[tasks[i] - 'A'] > maxFreq) {
            maxFreq = freq[tasks[i] - 'A'];
            maxCount = 1;
        } 
        else if (freq[tasks[i] - 'A'] == maxFreq) {
            maxCount++;
        }
    }
    
    // Calculate intervals
    int partCount = maxFreq - 1;
    int partLength = n - (maxCount - 1);
    int emptySlots = partCount * partLength;
    int availableTasks = tasksSize - maxFreq * maxCount;
    int idles = emptySlots - availableTasks;
    if (idles < 0) idles = 0;
    
    return tasksSize + idles;
}

void printTaskSequence(char* tasks, int size, int n) {
    printf("Tasks: [");
    for (int i = 0; i < size; i++) {
        printf("'%c'", tasks[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
    printf("Cooling period (n): %d\n", n); //period print
}

int main() {
    // Test cases
    struct TestCase {
        char tasks[MAX_TASKS];
        int size;
        int n;
    };
    
    struct TestCase testCases[] = {
        {{'A','A','A','B','B','B'}, 6, 2}, // indicate amount of tasks and requiried n =2 in seperate vector slice
        {{'A','C','A','B','D','B'}, 6, 1},
        {{'A','A','A','B','B','B'}, 6, 3}
    };
    
    int numTestCases = sizeof(testCases) / sizeof(testCases[0]);
    
    printf("=== Task Scheduler Demo ===\n\n");
    
    for (int i = 0; i < numTestCases; i++) {
        printf("Test Case %d:\n", i + 1);
        printf("-------------\n");
        
        printTaskSequence(testCases[i].tasks, testCases[i].size, testCases[i].n); // display the set of tests were working with
        
        int result = leastInterval(testCases[i].tasks, testCases[i].size, testCases[i].n); // send size and cooling sepeerately for simplicyt
        printf("Minimum intervals required: %d\n", result);
        
        // Print possible sequence
        printf("potential sequence given restrictions: ");
        int* slottaskused = (int*)calloc(testCases[i].size, sizeof(int));
        
        for (int time = 0; time < result; time++) {
            int taskFound = 0;
            for (int j = 0; j < testCases[i].size; j++) {
                if (!slottaskused[j]) {
                    printf("%c ", testCases[i].tasks[j]);
                    slottaskused[j] = 1; // find slots where both in the correct time slot and given intervals given we can use the time for the task
                    taskFound = 1;
                    break;
                }
            }
            if (!taskFound) {
                printf("idle ");
            }
        }
        printf("\n\n");
        
        free(slottaskused);
    }
    
    return 0;
}
