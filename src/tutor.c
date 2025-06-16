#include <stdio.h>
#include <string.h>
#include "tutor.h"

void add_question(Question questions[], int *count) {
    if (*count >= MAX_QUESTIONS) {
        printf("Question limit reached.\n");
        return;
    }
    Question *q = &questions[*count];
    q->id = (*count == 0) ? 1 : questions[*count - 1].id + 1;

    printf("Enter question: ");
    fgets(q->question, MAX_QUESTION_LEN, stdin);
    q->question[strcspn(q->question, "\n")] = '\0';

    printf("Enter answer: ");
    fgets(q->answer, MAX_ANSWER_LEN, stdin);
    q->answer[strcspn(q->answer, "\n")] = '\0';

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
        printf("ID: %d | Q: %s | A: %s\n", questions[i].id, questions[i].question, questions[i].answer);
    }
}

int find_question_by_id(const Question questions[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (questions[i].id == id)
            return i;
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
    }
    (*count)--;
    printf("Question deleted successfully.\n");
}

void edit_question(Question questions[], int count) {
    int id, idx;
    char buffer[16];
    char new_question[MAX_QUESTION_LEN];
    char new_answer[MAX_ANSWER_LEN];

    printf("Enter question ID to edit: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &id);

    idx = find_question_by_id(questions, count, id);
    if (idx == -1) {
        printf("Question with ID %d not found.\n", id);
        return;
    }

    printf("Current question: %s\n", questions[idx].question);
    printf("Enter new question (leave blank to keep unchanged): ");
    fgets(new_question, sizeof(new_question), stdin);
    new_question[strcspn(new_question, "\n")] = '\0';
    if (strlen(new_question) > 0) {
        strncpy(questions[idx].question, new_question, MAX_QUESTION_LEN);
        questions[idx].question[MAX_QUESTION_LEN - 1] = '\0';
    }

    printf("Current answer: %s\n", questions[idx].answer);
    printf("Enter new answer (leave blank to keep unchanged): ");
    fgets(new_answer, sizeof(new_answer), stdin);
    new_answer[strcspn(new_answer, "\n")] = '\0';
    if (strlen(new_answer) > 0) {
        strncpy(questions[idx].answer, new_answer, MAX_ANSWER_LEN);
        questions[idx].answer[MAX_ANSWER_LEN - 1] = '\0';
    }

    printf("Question updated successfully.\n");
}