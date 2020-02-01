#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#pragma warning(disable:4996)
// 结构体传参 联合 位段 枚举
// 
struct Student{
	char name[32];
	char sex;
	int age;
	char id[12];
};
int main1(){
	// 在栈上开辟空间
	struct Student tom;
	// 在堆上开辟空间
	struct Student* jim = (struct Student*)malloc(sizeof(struct Student));

	system("pause");
	return 0;

}
// typedef : 对类型重命名
// 不加typedef 后面的变量为全局变量, 不建议
// {}里必须有东西
typedef struct Student{
	char name[32];
	char sex;
	int age;
	char id[12];
}stu_t;// stu_t 为名字
int main2(){
	stu_t tom = { "tom", 'm', 112, "12345" };//初始化
	// 任何内置类型 任何自定义制类型 复合类型都可以放任何内容(数组 结构体)
	system("pause");
	return 0;
}
// 只要是两个结构体 哪怕内容一样,但是依旧是两种类型 除非用同一种结构体定义
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
// 结构体里可以放结构体 但是不能放自身
// 
struct A{
	int a;
	char b;
	struct A  obj;// 不通过, 类型, 大小不明确
	struct A* obj;// 指针类型可以通过,4字节,这叫做结构体的自引用
};
























