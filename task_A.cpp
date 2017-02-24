#include <vector>
#include <stdio.h>
#include <algorithm>
#include <climits>


using namespace std;

void solution() {
    vector<int> Countdiff(1 + 10000, 0);
    vector<int> Sumdiff(1 + 10000, 0);
    
    int n;
    
    scanf("%d", &n);
    
    
    for (int i = 0; i < n; i++) {
        int start;
        int end;
       
        scanf("%d %d", &start, &end);
        Countdiff[start]++;
        Countdiff[end]--;
        Sumdiff[start] += i;
        Sumdiff[end] -= i; 
    }
    vector<bool> isSingle(n, false);
    int minCount = INT_MAX;
    int curentCount = 0;
    int curentSum = 0;
    for (int i = 0; i < 10000; i++) {
        curentCount += Countdiff[i];
        minCount = min(minCount, curentCount);
        curentSum += Sumdiff[i];
        
        if (curentCount == 1) {
            isSingle[curentSum] = true;
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
        solution();
    }
    return 0;
}

