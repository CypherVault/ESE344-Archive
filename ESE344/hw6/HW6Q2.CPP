#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N 110
#define MAX_VIDEOS 110
#define MAX_VIDEO_LEN 32

//   queue (BFS) satlelite functions
void enqueue(int *queue, int *rear, int val) {
    queue[(*rear)++] = val;
}
int dequeue(int *queue, int *front) {
    return queue[(*front)++];
}


typedef struct {
    char name[MAX_VIDEO_LEN];  // track each video name and times it appears , used for each

    int count;
} VideoFreq;

int findVideo(VideoFreq *freqs, int freqSize, const char *video) {
    for (int i = 0; i < freqSize; ++i)
        if (strcmp(freqs[i].name, video) == 0)
            return i;
    return -1; // searches for video by name from struct
}

// Comparator for qsort
int cmp(const void *a, const void *b) {
    VideoFreq *va = (VideoFreq*)a, *vb = (VideoFreq*)b;
    if (va->count != vb->count)
        return va->count - vb->count;
    return strcmp(va->name, vb->name);
}

// Main function, BFS style to find friends
void watchedVideosByFriends(
    char watchedVideos[MAX_N][MAX_VIDEOS][MAX_VIDEO_LEN], int watchedCount[MAX_N],
    int friends[MAX_N][MAX_N], int friendsCount[MAX_N],
    int n, int id, int level
) {
    int queue[MAX_N], front = 0, rear = 0;
    int visited[MAX_N] = {0};
    enqueue(queue, &rear, id);
    visited[id] = 1;

    // BFS to the required level
    for (int l = 0; l < level; ++l) {
        int size = rear - front;
        for (int i = 0; i < size; ++i) {
            int cur = dequeue(queue, &front);
            for (int j = 0; j < friendsCount[cur]; ++j) {
                int f = friends[cur][j];
                if (!visited[f]) {
                    enqueue(queue, &rear, f);
                    visited[f] = 1;
                }
            }
        }
    }

    // Count video frequencies
    VideoFreq freqs[MAX_N * MAX_VIDEOS];
    int freqSize = 0;
    while (front < rear) {
        int cur = dequeue(queue, &front);
        for (int i = 0; i < watchedCount[cur]; ++i) {
            char *video = watchedVideos[cur][i];
            int idx = findVideo(freqs, freqSize, video);
            
            if (idx == -1) {
                strcpy(freqs[freqSize].name, video);
                freqs[freqSize].count = 1;
                freqSize++;
            }
            else {
                freqs[idx].count++;
            }
        }
    }

    // Sort and print content
    qsort(freqs, freqSize, sizeof(VideoFreq), cmp);
    for (int i = 0; i < freqSize; ++i)
        printf("%s\n", freqs[i].name);
}

// Example usage
int main() {
    // watchedVideos[i][j] is the j-th video watched by person i
    char watchedVideos[MAX_N][MAX_VIDEOS][MAX_VIDEO_LEN] = {
        {"A", "B"},
        {"C"},
        {"B", "C"},
        {"D"}
    };
    int watchedCount[MAX_N] = {2, 1, 2, 1};
    // friends[i][j] is the j-th friend of person i
    int friends[MAX_N][MAX_N] = {
        {1, 2},
        {0, 3},
        {0, 3},
        {1, 2}
    };
    int friendsCount[MAX_N] = {2, 2, 2, 2};
    int n = 4, id = 0, level = 1;

    watchedVideosByFriends(watchedVideos, watchedCount, friends, friendsCount, n, id, level); 
    // finsihes by printing that sorted list
    // Output: "B\nC\n" expcted for this list 
    return 0;
}
