//
// Created by Mingtian Chen on 2025/5/7.
//

#include <stdlib.h>
#include <stdio.h>

const int PING_EXIST_TIME_MILLISECONDS = 3000;

typedef struct {
    long long nowTime;

    int *pingHistory;
    int historySize;
    int historyCount;
} RecentCounter;


RecentCounter *recentCounterCreate() {
    RecentCounter *recentCounter = malloc(sizeof(RecentCounter));
    if (recentCounter == NULL) {
        return NULL;
    }
    recentCounter->nowTime = 0;
    recentCounter->historySize = 1;
    recentCounter->historyCount = 0;
    recentCounter->pingHistory = malloc(recentCounter->historySize * sizeof(int));
    if (recentCounter->pingHistory == NULL) {
        free(recentCounter);
        return NULL;
    }
    return recentCounter;
}

int recentCounterPing(RecentCounter *obj, int t) {
    obj->nowTime = t;
    if (obj->historyCount + 1 > obj->historySize) {
        obj->historySize *= 2;
        int *temp = realloc(obj->pingHistory, obj->historySize * sizeof(int));
        if (temp == NULL) {
            return -1;
        }
        obj->pingHistory = temp;
    }
    obj->pingHistory[obj->historyCount] = obj->nowTime;
    obj->historyCount++;

    int validPingHistoryIndex = 0;
    while (validPingHistoryIndex < obj->historyCount) {
        if (obj->nowTime - obj->pingHistory[validPingHistoryIndex] <= PING_EXIST_TIME_MILLISECONDS) {
            break;
        }
        validPingHistoryIndex++;
    }
    return obj->historyCount - validPingHistoryIndex;
}

void recentCounterFree(RecentCounter *obj) {
    free(obj);
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);

 * recentCounterFree(obj);
*/

int main(int argc, char *argv[]) {
    RecentCounter *recentCounter = recentCounterCreate();
    if (recentCounter == NULL) {
        return -1;
    }
    const int p1 = recentCounterPing(recentCounter, 1);
    if (p1 == -1) {
        recentCounterFree(recentCounter);
        return -1;
    }
    const int p2 = recentCounterPing(recentCounter, 100);
    if (p2 == -1) {
        recentCounterFree(recentCounter);
        return -1;
    }
    const int p3 = recentCounterPing(recentCounter, 3001);
    if (p3 == -1) {
        recentCounterFree(recentCounter);
        return -1;
    }
    const int p4 = recentCounterPing(recentCounter, 3002);
    if (p4 == -1) {
        recentCounterFree(recentCounter);
        return -1;
    }

    printf("%d\n", p1);
    printf("%d\n", p2);
    printf("%d\n", p3);
    printf("%d\n", p4);

    recentCounterFree(recentCounter);
    return 0;
}
