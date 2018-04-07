#include "DanhSachLop.h"

void printStudentsListHeader(FILE *f2) {
	if (f2 == NULL) return;
	fprintf(f2, "<div class=\"page-header\">\n");
	fprintf(f2, "<div class=\"page-header-content\">\n");
	fprintf(f2, "<h1>Students</h1>\n");
	fprintf(f2, "</div>\n");
	fprintf(f2, "</div>\n");
}

void printStudentsListContent(FILE *f2, Student *students, int n) {
	if (f2 == NULL) return;
	fprintf(f2, "<div class=\"page-region\">\n");
	fprintf(f2, "<div class=\"page-region-content\">\n");
	fprintf(f2, "<ul class=\"listview fluid\">\n");
	for (int i = 0; i < n; i++) {
		fprintf(f2, "<li>\n");
		fprintf(f2, "<a href=\"%s.html\">\n", students[i].mssv);
		fprintf(f2, "<div class=\"icon\">\n");
		fprintf(f2, "<img src=\"./images/%s\" alt=\"%s\">\n", students[i].smallImg, students[i].mssv);
		fprintf(f2, "</div>\n");
		fprintf(f2, "<div class=\"data\">\n");
		fprintf(f2, "<h4>%s</h4>\n", students[i].name);
		fprintf(f2, "<p>%s %s</p>\n", students[i].faculty, students[i].year);
		fprintf(f2, "</div>\n");
		fprintf(f2, "</a>\n");
		fprintf(f2, "</li>\n");
	}
	fprintf(f2, "</ul>\n");
	fprintf(f2, "</div>\n");
	fprintf(f2, "</div>\n");
}

void printStudentsList(FILE *f2, Student *students, int n) {
	if (f2 == NULL) return;
	fprintf(f2, "<div class=\"page\">\n");
	printStudentsListHeader(f2);
	printStudentsListContent(f2, students, n);
	fprintf(f2, "</div>\n");
}