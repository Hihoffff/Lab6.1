#include "lib.h"
#include "lib.cpp"

int main() {
	setlocale(LC_ALL, "RUS");
	FILE* file = fopen("info.txt", "rt");
	FILE* fperm = fopen("fperm.bin", "w+b");
	FILE* rperm = fopen("rperm.bin", "w+b");
	FILE* res = fopen("res.txt", "w");
	FILE* res2 = fopen("zashita.txt", "w");
	if (file!=0 && fperm!=0 && rperm!=0 && res!=0) {
		transfer(file, fperm);
		fseek(fperm, 0, SEEK_SET);
		output1(fperm, rperm);
		if (ftell(rperm)>0) {
			fseek(rperm, 0, SEEK_SET);
			output2(rperm, res);

			//zashita
			int num;
			int age;
			int cur=0;

			fseek(rperm, 0, SEEK_SET);
			startData(rperm, cur, age,num);
			
			if (num != -1) {
				findAged(rperm, cur, age, num);
				zashita(rperm, res2, num);
			}
			else {
				cout << "Нет подходящих людей!" << endl;
				fputs("Нет подходящих!\n", res2);
			}
			
		}
		else {
			fputs("Нет подходящих студентов!\n", res);
		}
		fclose(file);
		fclose(fperm);
		fclose(rperm);
		fclose(res);
		fclose(res2);
	}
	else {
		printf("Ошибка при открытии файла!\n");
	}
}
