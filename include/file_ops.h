#ifndef FILE_OPS_H
#define FILE_OPS_H

#include "tutor.h"

int load_questions(Question questions[], int *count, const char *filename);
void save_questions(const Question questions[], int count, const char *filename);

#endif