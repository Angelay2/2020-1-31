#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#pragma warning(disable:4996)
// �ṹ�崫�� ���� λ�� ö��
// 
struct Student{
	char name[32];
	char sex;
	int age;
	char id[12];
};
int main1(){
	// ��ջ�Ͽ��ٿռ�
	struct Student tom;
	// �ڶ��Ͽ��ٿռ�
	struct Student* jim = (struct Student*)malloc(sizeof(struct Student));

	system("pause");
	return 0;

}
// typedef : ������������
// ����typedef ����ı���Ϊȫ�ֱ���, ������
// {}������ж���
typedef struct Student{
	char name[32];
	char sex;
	int age;
	char id[12];
}stu_t;// stu_t Ϊ����
int main2(){
	stu_t tom = { "tom", 'm', 112, "12345" };//��ʼ��
	// �κ��������� �κ��Զ��������� �������Ͷ����Է��κ�����(���� �ṹ��)
	system("pause");
	return 0;
}
// ֻҪ�������ṹ�� ��������һ��,������������������ ������ͬһ�ֽṹ�嶨��
struct A{
	int a;
	char b;
};
struct B{
	int a;
	char b;
};
int main(){
	struct A a;
	struct B *p = NULL;
	p = &a;

	system("pause");
	return 0;
}
// �ṹ������ԷŽṹ�� ���ǲ��ܷ�����
// 
struct A{
	int a;
	char b;
	struct A  obj;// ��ͨ��, ����, ��С����ȷ
	struct A* obj;// ָ�����Ϳ���ͨ��,4�ֽ�,������ṹ���������
};
























