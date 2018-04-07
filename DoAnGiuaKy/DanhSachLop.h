#pragma once
#include "All.h"
#include <string.h>
#include <stdlib.h>

void printStudentsListHeader(FILE *f2);
void printStudentsListContent(FILE *f2, Student *students, int n);
void printStudentsList(FILE *f2, Student *students, int n);