

void transfer(FILE* file, FILE* fperm) { 
	muchenik Student;
	while (fscanf(file, "%d %s %s %s %d %s %d %d %d %lf", &Student.group, &Student.secondName, &Student.name, &Student.thirdName, &Student.year, &Student.gender, &Student.physics, &Student.math, &Student.IT, &Student.scholarship) != EOF) {
		fwrite(&Student, sizeof(Student), 1, fperm);
	}
	return;
}

void output1(FILE* fperm, FILE* rperm) {
	muchenik Student;
	while (fread(&Student, sizeof(Student), 1, fperm) != 0) {
		if ((Student.physics + Student.math + Student.IT) / 3.0 > 4.5) {
			fwrite(&Student, sizeof(Student), 1, rperm);
		}
	}
}

void output2(FILE* rperm, FILE* res) {
	muchenik Student;
	while (fread(&Student, sizeof(Student), 1, rperm) != 0) {
		fprintf(res, "%s %s %s %d\n", Student.secondName, Student.name,Student.thirdName,Student.physics);
	}
	return;
}
//найдите старшего хорошиста
void zashita(FILE* rperm, FILE* res,int num) {
	muchenik Student;
	fseek(rperm, num, SEEK_SET);
	fread(&Student, sizeof(Student), 1, rperm);
	fprintf(res, "%s %s %s", Student.secondName, Student.name, Student.thirdName);
}
//в отдельной функции нач данные для сравнения
void startData(FILE* rperm,int& cur, int & age, int &num) {
	bool flag = true;
	muchenik Student;
	while (fread(&Student, sizeof(Student), 1, rperm) != 0 && flag) {
		if (Student.physics >= 4 && Student.math >= 4 && Student.IT >= 4) {
			age = 2025 - Student.year;
			flag = false;
			num = cur;
		}
		cur = ftell(rperm);
	}
	if (flag) {
		num = -1;
	}
	return;
}
void findAged(FILE* rperm, int& cur, int& age, int& num) {
	muchenik Student;
	fseek(rperm, num, SEEK_SET);
	while (fread(&Student, sizeof(Student), 1, rperm) != 0) {
		if (2025 - Student.year > age && (Student.physics >= 4 && Student.math >= 4 && Student.IT >= 4)) {
			age = 2025 - Student.year;
			num = cur;
		}
		cur = ftell(rperm);
	}
	return;
}


