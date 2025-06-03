#include <stdio.h>
#include <string.h>
#include "file_ops.h"

int load_questions(Question questions[], int *count, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) return 0;

    *count = 0;
    while (fgets(questions[*count].question, MAX_QUESTION_LEN, fp) &&
           fgets(questions[*count].answer, MAX_ANSWER_LEN, fp)) {
        questions[*count].question[strcspn(questions[*count].question, "\n")] = '\0';
        questions[*count].answer[strcspn(questions[*count].answer, "\n")] = '\0';
        questions[*count].id = *count + 1;
        (*count)++;
        if (*count >= MAX_QUESTIONS) break;
    }
    fclose(fp);
    return 1;
}

void save_questions(const Question questions[], int count, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Error saving questions!\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s\n%s\n", questions[i].question, questions[i].answer);
    }
    fclose(fp);
}