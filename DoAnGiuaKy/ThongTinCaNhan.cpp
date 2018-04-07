#include "ThongTinCaNhan.h"

void printImageContainer(FILE *secondPage, Student *students, int i) {
	if (secondPage == NULL) return;
	fprintf(secondPage, "<div class=\"image-container bg-color-green\">\n");
	fprintf(secondPage, "<img src=\"./images/%s\" alt=\"%s\">\n", students[i].largeImg, students[i].mssv);
	fprintf(secondPage, "<div class=\"overlay\">\n");
	fprintf(secondPage, "<p>%s</p>\n", students[i].birthDay);
	fprintf(secondPage, "<p>%s %s</p>\n", students[i].faculty, students[i].year);
	fprintf(secondPage, "</div>\n");
	fprintf(secondPage, "</div>\n");
}

char*addcharacter(char*nguon, char kitu, int&n) {
	int m = n + 1;
	char*newstring = (char*)realloc(nguon, m*sizeof(char));
	if (newstring != NULL) {
		newstring[n] = kitu;
		n++;
	}
	return newstring;
}

void printFavorite(FILE *secondPage, char *favorites) {
	if (secondPage == NULL) return;
	if (favorites == NULL) {
		fprintf(secondPage, "<h3>Favorite</h3>\n");
		fprintf(secondPage, "<ul>\n");
		fprintf(secondPage, "<li>update</li>\n");
		fprintf(secondPage, "</ul>\n");
	}
	else {
		fprintf(secondPage, "<h3>Favorite</h3>\n");
		fprintf(secondPage, "<ul>\n");
		char c = ' ',*s=NULL;
		int i = 0, length = 0 ;
		while (c != '\0') {
			c = favorites[i++];
			if (c!='\0' && c != ',') {
				s = addcharacter(s, c, length);
			}
			else {
				s = addcharacter(s, '\0', length);
				fprintf(secondPage, "<li>%s\n</li>\n",s);
				if(s !=NULL) free(s); // giai phong vung nho f
				s = NULL;
				length = 0;
			}
		}
		fprintf(secondPage, "</ul>\n");
	}
}

void printPersonality(FILE *secondPage, Student *students, int i) {
	if (secondPage == NULL) return;
	fprintf(secondPage, "<ul class=\"listview\" id=\"personality\">\n");
	fprintf(secondPage, "<li class=\"bg-color-yellow fg-color-white\">\n");
	fprintf(secondPage, "<div class=\"icon\">\n");
	fprintf(secondPage, "<i class=\"icon-user\"></i>\n");
	fprintf(secondPage, "</div>\n");
	fprintf(secondPage, "<div class=\"data\">\n");
	fprintf(secondPage, "<h3>Personality</h3>\n");
	fprintf(secondPage, "<p>%s</p>", students[i].quote);
	fprintf(secondPage, "</div>\n");
	fprintf(secondPage, "</li>\n");
	fprintf(secondPage, "<li class=\"bg-color-red fg-color-white\">\n");
	fprintf(secondPage, "<div class=\"icon\">\n");
	fprintf(secondPage, "<i class=\"icon-headphones\"></i>\n");
	fprintf(secondPage, "</div>\n");
	fprintf(secondPage, "<div class=\"data\">\n");
	printFavorite(secondPage, students[i].hobbies);
	fprintf(secondPage, "</div>\n");
	fprintf(secondPage, "</li>\n");
	fprintf(secondPage, "</ul>\n");
	fprintf(secondPage, "</ul>\n");
}