//3���� �ǽ�.c
//ppt ���� 3�� �����Ͽ� ����ü ����
//�̸�, �г�, ����, ����, ����, ���

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
	struct stu stu = { "ȫ�浿", 1, 90, 80, 70 };
	struct stu stus[2];

	//��� ����
	stu_average(&stu);

	//stu[0]�� �ִ� �ɹ��� ���� stus[0]�� ����
	stu_insert1(&stus[0], stu);

	//stu[1]�� �ִ� �ɹ��� ���� ���޵� ������ ����
	stu_insert2(stus + 1, "��浿", 2, 100, 90, 80);

	//���޵� stu�� ��� --> ��� ��µǾ�� ��	
	stu_print(stu);

	//�迭 ��ü�� ����� stus�� ��� ��� --> ��� ���
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
	strcpy_s((*change).name, sizeof((*change).name), "��浿");
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