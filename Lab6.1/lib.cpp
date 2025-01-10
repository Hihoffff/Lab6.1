

void transfer(FILE* file, FILE* fperm) { //что-то не так с формированием файла , скачазала что-то с массивом
	muchenik Student;
	while (!feof(file)) {
		fscanf(file, "%d %s %s %s %d %s %d %d %d %lf", &Student.group, &Student.secondName, &Student.name, &Student.thirdName, &Student.year, &Student.gender, &Student.physics, &Student.math, &Student.IT, &Student.scholarship);
		fwrite(&Student, sizeof(Student), 1, fperm);
	}
	return;
}

bool output1(FILE* fperm, FILE* rperm) {
	muchenik Student;
	bool isHas = false;
	while (fread(&Student, sizeof(Student), 1, fperm) != 0 && !isHas) {
		if ((Student.physics + Student.math + Student.IT) / 3.0 > 4.5) {
			fwrite(&Student, sizeof(Student), 1, rperm);
			isHas = true;
		}
	}
	return isHas;
}

void output2(FILE* rperm, FILE* res) {
	muchenik Student;
	while (fread(&Student, sizeof(Student), 1, rperm) != 0) {
		fprintf(res, "%s %s %s %d\n", Student.secondName, Student.name,Student.thirdName,Student.physics);
	}
	return;
}
