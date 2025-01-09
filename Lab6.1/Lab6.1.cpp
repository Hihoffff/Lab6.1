#include "lib.h"
#include "lib.cpp"

int main() {
	setlocale(LC_ALL, "RUS");
	FILE* file = fopen("info.txt", "rt");
	FILE* fperm = fopen("fperm.txt", "w+b");
	FILE* rperm = fopen("rperm.txt", "w+b");
	FILE* res = fopen("res.txt", "w");

	transfer(file, fperm);
	fseek(fperm, 0, SEEK_SET);
	bool isHas = output1(fperm, rperm);
	if (isHas) {
		output2(rperm, res);
	}
	else {
		fputs("Нет подходящих студентов!", res);
	}
	fclose(file);
	fclose(fperm);
	fclose(rperm);
	fclose(res);
	
}
