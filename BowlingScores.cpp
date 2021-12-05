#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
#define NSCORES 5
int n = 0;
void GetBowlingData(char fname[], char nm[SIZE][20], int scores[SIZE][NSCORES])
{
    FILE* fptr = fopen(fname, "r");
    int i = 0, j = 0;
    while (i < SIZE && fscanf(fptr, "%s", &nm[i]) != -1) {
        for (j = 0; j < NSCORES; j++) {
            fscanf(fptr, "%d", &scores[i][j]);
        }
        n++;
        i++;
    }
    fclose(fptr);
}
void GetAverageScore(int scores[SIZE][NSCORES], double avg[SIZE]) {

    int i, j;
    double a = 0, s = 0;

    for (i = 0; i < n; i++) {
        s = 0;
        for (j = 0; j < NSCORES; j++) {
            s += scores[i][j];
        }
        avg[i] = (s / NSCORES);
        //printf("%f\n",avg[i]);
    }

}
void PrettyPrintResult(char nm[SIZE][20], int scores[SIZE][NSCORES], double avg[]) {
    int i, j;
    printf("\n%20s%6s%6s%6s%6s%6s%12s\n", "Name", "S1", "S2", "S3", "S4", "S5", "Avg");
    for (i = 0; i < n; i++) {
        printf("\n%20s", nm[i]);
        for (j = 0; j < NSCORES; j++) {
            printf("%6d", scores[i][j]);
        }
        printf("%12.2f", avg[i]);

    }
}
int main() {
    char names[SIZE][20];
    int scores[SIZE][5];
    double avg[SIZE];
    char name[60] = "BowlingScores.txt";
    GetBowlingData(name, names, scores);
    GetAverageScore(scores, avg);
    PrettyPrintResult(names, scores, avg);
}