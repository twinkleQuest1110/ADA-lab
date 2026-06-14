//JOB seq
#include <stdio.h>

void jobSeq(char job[], int d[], int p[], int n) {
    int i, j;
    int Total = 0;
    // Sort jobs according to profit
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(p[i] < p[j]) {

                // swap profit
                int temp = p[i];
                p[i] = p[j];
                p[j] = temp;

                // swap deadline
                temp = d[i];
                d[i] = d[j];
                d[j] = temp;

                // swap job id
                char t = job[i];
                job[i] = job[j];
                job[j] = t;
            }
        }
    }

    // Find maximum deadline
    int maxD = 0;
    for(i = 0; i < n; i++) {
        if(d[i] > maxD)
            maxD = d[i];
    }

    int slot[maxD];
    char result[maxD];

    for(i = 0; i < maxD; i++)
        slot[i] = 0;

    // Job sequencing
    for(i = 0; i < n; i++) {
        for(j = d[i] - 1; j >= 0; j--) {
            if(slot[j] == 0) {
                slot[j] = 1;
                result[j] = job[i];
                break;
            }
        }
    }

    // Print sequence & also Total Profit---
    printf("Selected Jobs: ");
    for(i = 0; i < maxD; i++) {
        if(slot[i] == 1)
            printf("%c ", result[i]);
            Total +=p[i];
    }
    printf("\nTotal = %d",Total);
}

int main() {

    char job[] = {'A', 'B', 'C', 'D', 'E'};
    int d[] = {2, 1, 2, 1};
    int p[] = {100,10,27,15};

    int n = 4;

    jobSeq(job, d, p, n);

    return 0;
}