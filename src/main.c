#include <stdio.h>
#include <string.h>
#include "tutor.h"
#include "file_ops.h"
#include "learner.h" // <-- Add this include

#define QUESTIONS_FILE "data/questions.txt"

void display_main_menu() {
    printf("\n========== Tutor-Learner System ==========\n");
    printf("1. Tutor Mode\n");
    printf("2. Learner Mode\n");
    printf("3. Exit\n");
    printf("=========================================\n");
    printf("Choose mode: ");
}

void tutor_mode(Question questions[], int *count) {
    int choice, id;
    char buffer[16];
    while (1) {
        printf("\n--- Tutor Menu ---\n");
        printf("1. Add Question\n");
        printf("2. List Questions\n");
        printf("3. Delete Question\n");
        printf("4. Edit Question\n");
        printf("5. Back to Main Menu\n");
        printf("Choose: ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &choice);

        switch (choice) {
            case 1:
                add_question(questions, count);
                break;
            case 2:
                display_questions(questions, *count);
                break;
            case 3:
                printf("Enter question ID to delete: ");
                fgets(buffer, sizeof(buffer), stdin);
                sscanf(buffer, "%d", &id);
                delete_question(questions, count, id);
                break;
            case 4:
                edit_question(questions, *count);
                break;
            case 5:
                return;
            default:
                printf("Invalid choice.\n");
        }
    }
}

int main() {
    Question questions[MAX_QUESTIONS];
    int count = 0;

    if (!load_questions(questions, &count, QUESTIONS_FILE)) {
        printf("No existing questions found. Starting fresh.\n");
    }

    while (1) {
        display_main_menu();
        int choice;
        char buffer[16];
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &choice);

        switch (choice) {
            case 1:
                tutor_mode(questions, &count);
                save_questions(questions, count, QUESTIONS_FILE);
                break;
            case 2:
                learner_mode(questions, count); // Now calls the function from learner.c
                break;
            case 3:
                save_questions(questions, count, QUESTIONS_FILE);
                printf("Exiting system. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please select 1-3.\n");
        }
    }
}