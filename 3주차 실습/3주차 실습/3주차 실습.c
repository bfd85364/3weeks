//3주차 실습.c
//ppt 문제 3번 참조하여 구조체 정의
//이름, 학년, 국어, 영어, 수학, 평균

#include <stdio.h>
#include <string.h>

void stu_average(struct stu*average);
void stu_insert1(struct stu*ins1, struct stu ins2);
void stu_insert2(struct stu*change, char name[20], int age, int score1, int score2, int score3);
void stu_print(struct stu print1);
void stu_printall(struct stu *print1, int count);

struct stu
{
	char name[20];
	int age;
	int score1, score2, score3;
	float average1;
};


int main()
{
	struct stu stu = { "홍길동", 1, 90, 80, 70 };
	struct stu stus[2];

	//평균 저장
	stu_average(&stu);

	//stu[0]에 있는 맴버의 값을 stus[0]에 저장
	stu_insert1(&stus[0], stu);

	//stu[1]에 있는 맴버의 값을 전달된 값으로 저장
	stu_insert2(stus + 1, "김길동", 2, 100, 90, 80);

	//전달된 stu를 출력 --> 평균 출력되어야 함	
	stu_print(stu);

	//배열 전체에 저장된 stus를 모두 출력 --> 평균 출력
	stu_printall(stus, 2);

	return 0;
}

void stu_average(struct stu* average)
{
	average->average1 = (average->score1 + average->score2 + average->score3) / 3.0f;
}

void stu_insert1(struct stu* ins1, struct stu ins2)
{
	*ins1 = ins2;
}

void stu_insert2(struct stu* change, char name[20], int age, int score1, int score2, int score3)
{
	strcpy_s((*change).name, sizeof((*change).name), "김길동");
	(*change).age = age;
	(*change).score1 = score1;
	(*change).score2 = score2;
	(*change).score3 = score3;

	change->average1 = (change->score1 + change->score2 + change->score3) / 3.0f;
}

void stu_print(struct stu print1)
{
	printf("%s %d %d %d %d %.2f\n", print1.name, print1.age, print1.score1, print1.score2, print1.score3, print1.average1);
}

void stu_printall(struct stu *print1, int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("%s %d %d %d %d %.2f\n", print1[i].name, print1[i].age, print1[i].score1, print1[i].score2, print1[i].score3, print1[i].average1);
	}
}