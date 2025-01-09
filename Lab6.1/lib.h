#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

using namespace std;
void transfer(FILE* file, FILE* fperm);
bool output1(FILE* fperm, FILE* rperm);
void output2(FILE* rperm, FILE* res);

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