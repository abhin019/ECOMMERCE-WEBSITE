#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
void swap(int *x, int *y) {
int temp = *x;
*x = *y;
*y = temp;
}
void reverse(int array[], int start, int end) {
while (start < end) {
swap(&array[start], &array[end]);
start++;
end--;
}
}
bool next_permutation(int array[], int size) {
int k = -1;
for (int i = size - 2; i >= 0; i--) {
if (array[i] < array[i + 1]) {
k = i;
break;
}
}
if (k == -1)
return false;
int l = -1;
for (int i = size - 1; i > k; i--) {
if (array[k] < array[i]) {
l = i;
break;
}
}
swap(&array[k], &array[l]);
reverse(array, k + 1, size - 1);
return true;
}
int calculateCost(int n, int dist[n][n], int path[n]) {
int cost = 0;
for (int i = 0; i < n - 1; i++) {
if (dist[path[i]][path[i + 1]] == -1)
return -1;
cost += dist[path[i]][path[i + 1]];
}
if (dist[path[n - 1]][path[0]] == -1)
return -1;
cost += dist[path[n - 1]][path[0]];
return cost;
}
void final_cost(int n, int dist[n][n], int *mincost, int best_path[n]) {
int path[n];
for (int i = 0; i < n; i++) {
path[i] = i;
}
*mincost = -1;
do {
int currentCost = calculateCost(n, dist, path);
if (currentCost != -1 && (*mincost == -1 || currentCost < *mincost)) {
*mincost = currentCost;
for (int j = 0; j < n; j++)
best_path[j] = path[j];
}
} while (next_permutation(path, n));
}
int main() {
int n;
printf("No. of Cities: ");
scanf("%d", &n);
int dist[n][n];
for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) {
if (i == j) {
dist[i][j] = 0;
continue;
}
printf("Enter Distance between %d and %d: ", i, j);
scanf("%d", &dist[i][j]);
}
}
int mincost;
int best_path[n];
final_cost(n, dist, &mincost, best_path);
if (mincost == -1)
printf("\nPath Does not Exist\n");
else {
printf("\nMin Cost: %d", mincost);
printf("\nBest Path is: ");
for (int i = 0; i < n; i++)
printf("%d ", best_path[i]);
printf("%d\n", best_path[0]);
}
return 0;
}