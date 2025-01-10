#include "lib.h"
#include "lib.cpp"

int main() {
	setlocale(LC_ALL, "RUS");
	FILE* file = fopen("info.txt", "rt");
	FILE* fperm = fopen("fperm.bin", "w+b");
	FILE* rperm = fopen("rperm.bin", "w+b");
	FILE* res = fopen("res.txt", "w");
	if (file!=0 && fperm!=0 && rperm!=0 && res!=0) {
		transfer(file, fperm);
		fseek(fperm, 0, SEEK_SET);
		bool isHas = output1(fperm, rperm);
		if (isHas) {
			fseek(rperm, 0, SEEK_SET);
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
	else {
		printf("Ошибка при открытии файла!\n");
	}
	
	
}
