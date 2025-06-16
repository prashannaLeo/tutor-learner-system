#ifndef TUTOR_H
#define TUTOR_H

#define MAX_QUESTION_LEN 256
#define MAX_ANSWER_LEN 128
#define MAX_QUESTIONS 100

typedef struct {
    int id;
    char question[MAX_QUESTION_LEN];
    char answer[MAX_ANSWER_LEN];
} Question;

// Function prototypes
void add_question(Question questions[], int *count);
void display_questions(const Question questions[], int count);
int find_question_by_id(const Question questions[], int count, int id);
void delete_question(Question questions[], int *count, int id);
void edit_question(Question questions[], int count); // <-- Added

#endif // TUTOR_H