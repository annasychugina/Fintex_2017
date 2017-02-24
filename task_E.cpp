#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>


void solve1() {
    std::vector<int> Countdiff(1 + 10000, 0);
    std::vector<int> Sumdiff(1 + 10000, 0);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int begin, end;
        scanf("%d %d", &begin, &end);
        Countdiff[begin]++;
        Countdiff[end]--;
        Sumdiff[begin] += i;
        Sumdiff[end] -= i; 
    }
    std::vector<bool> isSingle(n, false);
    int minCount = INT_MAX;
    int curCount = 0;
    int curSum = 0;
    for (int i = 0; i < 10000; i++) {
        curCount += Countdiff[i];
        minCount = std::min(minCount, curCount);
        curSum += Sumdiff[i];
        //не убираем
        if (curCount == 1) {
            isSingle[curSum] = true;
        }
    }
    
    if (minCount != 1) {
        printf("Wrong Answer\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!isSingle[i]) {
            printf("Wrong Answer\n");
            return;
        }   
    }
    printf("Accepted\n");
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        solve1();
    }
    return 0;
}

