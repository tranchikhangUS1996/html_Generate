#pragma once
#include "All.h"
#include <stdlib.h>
#include <string.h>
char*addchar(char*nguon, char kitu, int&n);
int ngatdauphay(char*&s, FILE*f);
int ngatdauphay(char*&s, FILE*f);
void destroy(Student*sv);
void readSv(FILE*f, Student*sv, int&daketthuc);
Student*taosv(Student*sv, int&soluong, FILE*f, int&daketthuc);
void readCSV(FILE*f, Student*&sv, int&soluongSV);
