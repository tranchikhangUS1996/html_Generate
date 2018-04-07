#include "ReadCsvFile.h"

char*addchar(char*nguon, char kitu, int&n) {
	int m = n + 1;
	char*newstring = (char*)realloc(nguon, m*sizeof(char));
	if (newstring != NULL) {
		newstring[n] = kitu;
		n++;
	}
	return newstring;
}

int ngatdauphay(char*&s, FILE*f) {
	int cout = 0; // kiem tra da ket thuc file CSV chua?
	if (f == NULL) return 0;
	char c = ' ';
	int i = 0;
	while (c != ',') {
		cout = fread(&c, sizeof(char), 1, f);
		if (cout == 0) return 0; // file CSV da ket thuc
		if (c != ',') {
			s = addchar(s, c, i);
		}
		else {
			s = addchar(s, '\0', i);
		}
	}
	return cout;
}

void catsothich(FILE*f, char*&s) {
	int cout = 1;
	if (f == NULL) return;
	char c = ' ';
	int i = 0;
	while (cout != 0 && c != '\n') {
		cout = fread(&c, sizeof(char), 1, f);
		if (cout != 0 && c != '\n') {
			s = addchar(s, c, i);
		}
		else {
			s = addchar(s, '\0', i);
		}
	}
}

void destroy(Student*sv) { 
	if (sv == NULL) return;
	if (sv->mssv != NULL) free(sv->mssv);
	if (sv->name != NULL) free(sv->name);
	if (sv->faculty != NULL)free(sv->faculty);
	if (sv->year != NULL) free(sv->year);
	if (sv->birthDay != NULL) free(sv->birthDay);
	if (sv->largeImg != NULL) free(sv->largeImg);
	if (sv->smallImg != NULL) free(sv->smallImg);
	if (sv->friendList != NULL) free(sv->friendList);
	if (sv->quote != NULL) free(sv->quote);
	if (sv->hobbies != NULL) free(sv->hobbies);
}

void readSv(FILE*f, Student*sv, int&daketthuc) {
	if (f == NULL) return;
	if (sv == NULL) return;
	daketthuc = ngatdauphay(sv->mssv, f);
	if (daketthuc == 0)  {
		destroy(sv);
		return;
	}
	ngatdauphay(sv->name, f);
	ngatdauphay(sv->faculty, f);
	ngatdauphay(sv->year, f);
	ngatdauphay(sv->birthDay, f);
	ngatdauphay(sv->largeImg, f);
	ngatdauphay(sv->smallImg, f);
	ngatdauphay(sv->friendList, f);
	ngatdauphay(sv->quote, f);
	catsothich(f, sv->hobbies);
}

Student*taosv(Student*sv, int&soluong, FILE*f, int&daketthuc) {

	int m = soluong + 1;
	Student*newsv = (Student*)realloc(sv, m*sizeof(Student));
	if (newsv != NULL) {
		if (f != NULL) {
			newsv[soluong] = { NULL };
			readSv(f, &newsv[soluong++], daketthuc);
		}
	}
	return newsv;
}

void readCSV(FILE*f, Student*&sv, int&soluongSV) {
	if (f == NULL) return;
	soluongSV = 0;
	int daketthuc = 1; // co hieu ket thuc file CSV
	while (daketthuc) {
		sv = taosv(sv, soluongSV, f, daketthuc);
		if (daketthuc == 0) {
			soluongSV--;
			sv = (Student*)realloc(sv, soluongSV*sizeof(Student)); // thu hoi lai vung nho
		}
	}
}

