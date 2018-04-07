#include "CuoiTrang.h"

void printFooter(FILE *f1, char *teamName) {
	if (f1 == NULL) return;
	fprintf(f1, "<div class=\"page\">\n");
	fprintf(f1, "<div class=\"nav-bar\" id=\"footer\">\n");
	fprintf(f1, "<div class=\"nav-bar-inner padding10\">\n");
	fprintf(f1, "<span class=\"element\">\n");
	fprintf(f1, "2013 &copy; %s - Styled with <a class=\"fg-color-white\" href=\"http://metroui.org.ua\">Metro UI CSS</a>\n", teamName);
	fprintf(f1, "</span>\n</div>\n</div>\n</div>\n");
}