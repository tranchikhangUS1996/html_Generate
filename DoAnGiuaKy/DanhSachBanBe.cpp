#include "DanhSachBanBe.h"

void printFriend(FILE *secondPage, Student *students, int j) {
	if (secondPage == NULL) return;
	fprintf(secondPage, "<li>\n");
	fprintf(secondPage, "<a href=\"%s.html\">\n", students[j].mssv);
	fprintf(secondPage, "<div class=\"icon\">\n");
	fprintf(secondPage, "<img src=\"./images/%s\" alt=\"%s\">\n", students[j].smallImg, students[j].mssv);
	fprintf(secondPage, "</div>\n");
	fprintf(secondPage, "<div class=\"data\">\n");
	fprintf(secondPage, "<h4>%s</h4>\n", students[j].name);
	fprintf(secondPage, "<p>%s %s</p>\n", students[j].faculty, students[j].year);
	fprintf(secondPage, "</div>\n");
	fprintf(secondPage, "</a>\n");
	fprintf(secondPage, "</li>\n");
}

void printFriendsList(FILE *secondPage, Student *students, int i, int n) {
	if (secondPage == NULL) return;
	fprintf(secondPage, "<h2>Friends</h2>\n");
	fprintf(secondPage, "<ul class=\"listview fluid\">\n");
	char *temp = strtok(students[i].friendList, ";");
	while (temp != NULL) {
		for (int j = 0; j < n; j++) {
			if (strcmp(temp, students[j].mssv) == 0) {
				printFriend(secondPage, students, j);
				break;
			}
		}
		temp = strtok(NULL, ";");
	}
	fprintf(secondPage, "</ul>\n");
}