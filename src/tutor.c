#include <stdio.h>
#include <string.h>
#include "tutor.h"

void add_question(Question questions[], int *count) {
    if (*count >= MAX_QUESTIONS) {
        printf("Cannot add more questions. Maximum reached.\n");
        return;
    }
    printf("Enter question: ");
    fgets(questions[*count].question, MAX_QUESTION_LEN, stdin);
    questions[*count].question[strcspn(questions[*count].question, "\n")] = '\0';

    printf("Enter answer: ");
    fgets(questions[*count].answer, MAX_ANSWER_LEN, stdin);
    questions[*count].answer[strcspn(questions[*count].answer, "\n")] = '\0';

    questions[*count].id = *count + 1;
    (*count)++;
    printf("Question added successfully.\n");
}

void display_questions(const Question questions[], int count) {
    if (count == 0) {
        printf("No questions available.\n");
        return;
    }
    printf("\nList of Questions:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d\nQ: %s\nA: %s\n\n", questions[i].id, questions[i].question, questions[i].answer);
    }
}

int find_question_by_id(const Question questions[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (questions[i].id == id) {
            return i;
        }
    }
    return -1;
}

void delete_question(Question questions[], int *count, int id) {
    int idx = find_question_by_id(questions, *count, id);
    if (idx == -1) {
        printf("Question with ID %d not found.\n", id);
        return;
    }
    for (int i = idx; i < *count - 1; i++) {
        questions[i] = questions[i + 1];
        questions[i].id = i + 1;
    }
    (*count)--;
    printf("Question deleted successfully.\n");
}