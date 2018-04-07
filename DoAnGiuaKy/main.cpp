#include "All.h"
#include "TrangChu.h"
#include "ReadCsvFile.h"
#include "DanhSachLop.h"
#include "TrangRieng.h"

void destroylist(Student*sv,int n) {
	if (sv == NULL) return;
	for (int i = 0; i < n; i++) {
		 destroy(sv + i);
	}
	free(sv);
} // huy danh sach sinh vien

void main() {
	char *indexName = "thumucgoc\\index.html";
	char *csvName = "thumucgoc\\students.csv";
	FILE *indexHtml, *csv;
	Student *students=NULL;
	csv = fopen(csvName, "rb");
	if (csv == NULL) {
		cout << "Cannot open the input file!!!\n" << endl;
		return;
	}
	else {
		int n = 0; //so luong sinh vien
		readCSV(csv, students, n);
		printIndexHtml(indexHtml, indexName, students, n);
		printAllSecondPage(students, n);
		destroylist(students, n);
		fclose(csv);
	}
}