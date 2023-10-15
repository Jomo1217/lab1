#include <stdio.h>

/* for example, takes in array {1, 1, 1, 0, 2} and returns the total points i.e. 25 */
int add_points(int points[], int pointValues[]) {
    int total = 0;
    for (int i = 0; i < 5; i++) {
        total += points[i] * pointValues[i];
    }
    return total;
}

/* 
target points: target points
points: current point values: e.g. {1, 1, 1, 0, 2}
pointValues: {8, 7, 6, 3, 2}
index: current index within points array
*/
void combinations(int target, int current_points[], int pointValues[], int index) {
    if (target < 2) {
        printf("Invalid target score\n");
        return;
    }
    int currentTally = add_points(current_points, pointValues);
    
    if (currentTally == target) {
        for (int i = 0; i < 5; i++) {
            printf("%d ", current_points[i]);
        }
        printf("\n");
        return;
    }
    
    /* loop through*/
    for (int i = index; i < 5; i++) {
        if (currentTally + pointValues[i] <= target) {
            current_points[i]++;
            combinations(target, current_points, pointValues, i);
            current_points[i]--;
        }
    }
}

int main() {
    int pointValues[] = {8, 7, 6, 3, 2};
    int current_points[] = {0, 0, 0, 0, 0};
    int index = 0;
    int target;

    printf("Enter target score or enter 0 to stop: ");
        scanf("%d", &target);

    while (target != 0) {
        combinations(target, current_points, pointValues, index);
        printf("Enter target score or enter 0 to stop: ");
        scanf("%d", &target);
    }

    return 0;
}