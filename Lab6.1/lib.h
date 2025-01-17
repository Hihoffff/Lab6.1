#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

using namespace std;
void transfer(FILE* file, FILE* fperm);
void output1(FILE* fperm, FILE* rperm);
void output2(FILE* rperm, FILE* res);
void zashita(FILE* rperm, FILE* res,int num);
void findAged(FILE* rperm, int& cur, int& age, int& num);
void startData(FILE* rperm, int& cur, int& age, int& num);

struct muchenik {
	int group;
	char secondName[20];
	char name[20];
	char thirdName[20];
	int year;
	char gender[20];
	int physics;
	int math;
	int IT;
	double scholarship;
};