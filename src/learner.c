#include <stdio.h>
#include <string.h>
#include "learner.h"

void learner_mode(const Question questions[], int count) {
    if (count == 0) {
        printf("No questions available for practice.\n");
        return;
    }
    char answer[MAX_ANSWER_LEN];
    int score = 0;
    printf("\n--- Learner Mode ---\n");
    for (int i = 0; i < count; i++) {
        printf("Q%d: %s\nYour answer: ", i + 1, questions[i].question);
        fgets(answer, sizeof(answer), stdin);
        answer[strcspn(answer, "\n")] = '\0';
        if (strcmp(answer, questions[i].answer) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. Correct answer: %s\n", questions[i].answer);
        }
    }
    printf("You scored %d out of %d.\n", score, count);
}