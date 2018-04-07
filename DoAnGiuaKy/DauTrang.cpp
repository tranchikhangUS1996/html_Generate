#include "DauTrang.h"

void printHeader(FILE *f1, char *title) {
	if (f1 == NULL) return;
	fprintf(f1, "<head>\n");
	fprintf(f1, "<meta charset=\"utf - 8\">\n");
	fprintf(f1, "<meta name=\"viewport\" content=\"target - densitydpi = device - dpi, width = device - width, initial - scale = 1.0, maximum - scale = 1\">\n");
	fprintf(f1, "<meta name=\"description\" content=\"HCMUS Students\">\n");
	fprintf(f1, "<meta name=\"author\" content=\"Tên nhóm\">\n");
	fprintf(f1, "<link href=\"./static/css/modern.css\" rel=\"stylesheet\">\n");
	fprintf(f1, "<link href=\"./static/css/modern - responsive.css\" rel=\"stylesheet\">\n");
	fprintf(f1, "<link href=\"./static/css/site.css\" rel=\"stylesheet\">\n");
	fprintf(f1, "<script type=\"text/javascript"" src=""./static/javascript/jquery.js\"></script>\n");
	fprintf(f1, "<script type=\"text/javascript"" src=""./static/javascript/dropdown.js\"></script>\n");
	fprintf(f1, "<title>%s</title>\n", title);
	fprintf(f1, "</head>\n");
}

void printNavigation(FILE *f2) {
	if (f2 == NULL) return;
	fprintf(f2, "<div class=\"page\">\n");
	fprintf(f2, "<div class=\"nav-bar\" id=\"header\">\n");
	fprintf(f2, "<div class=\"nav-bar-inner padding10\">\n");
	fprintf(f2, "<span class=\"pull-menu\"></span>\n");
	fprintf(f2, "<a href=\"index.html\">\n");
	fprintf(f2, "<img class=\"place-left\" src=\"./static/images/logo.png\" alt=\"HCMUS\">\n");
	fprintf(f2, "<span class=\"element brand\">HCMUS Students</span>\n");
	fprintf(f2, "</a>\n");
	fprintf(f2, "<div class=\"divider\"></div>\n");
	fprintf(f2, "<ul class=\"menu\">\n");
	fprintf(f2, "<li><a href=\"index.html\"><i class=\"icon-home\"></i>Home</a></li>\n");
	fprintf(f2, "</ul>\n");
	fprintf(f2, "</div>\n");
	fprintf(f2, "</div>\n");
	fprintf(f2, "</div>\n");
}