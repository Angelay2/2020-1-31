#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

// ģ��ʵ��memcpy
void* my_memcpy(void* dst, const void* src, int num){
	assert(dst);
	assert(src);

	char* dst_p = (char*)dst;
	const char* src_p = (const char*)src;
	// num--: nΪ�� ѭ������
	while (num--){
		*dst_p = *src_p;
		dst_p++, src_p++; 
	}
	return dst;
}
// һ��Ҫ����num��Ԫ��,��num��Ԫ�����������ƶ� 
// <= �������һ�� 
// <= ָ�������ָ��num-1��
// 
// ��src����������������һ��,��һ��һ�������ƴ���������,
// <= ���������Ҳ�,
// <= ����ָ�����Ҳ�,numԪ�ص����һ��
// <= ָ��+num-1(*num-1) Ȼ����dst��д
void* my_memcpy1(void* dst, const void* src, int num){
	assert(dst);
	assert(src);

	char* dst_p = (char*)dst;
	const char* src_p = (const char*)src;
	

	if (dst_p > src_p && dst_p < src_p + num){
		dst_p = dst_p + num - 1;
		src_p = src_p + num - 1;
		// ���߶�ָ���ַ���ĩβ Ҫ����num��Ԫ�� memcpy����Ҫ����'\0'�������
		// Ҫ�뿽��num��Ԫ��,����ָ��Ӧ��Ų��num-1��λ��,
		// 
		while (num--){
			// ��src��β�����ݷ���dst��β
			*dst_p = *src_p;
			dst_p--, src_p--;
		}
	} // = > dst ������src��
	else {
		while (num--){
			*dst_p = *src_p;
			dst_p++, src_p++;// ��������
		}
	}
	
	return dst;
}
int main1(){
	const char* src = "hello world!";

	char dst[64];
	my_memcpy(dst, src, strlen(src) + 1);
	printf("%s\n", dst);

	system("pause");
	return 0;
}
// ��ӡaabcd1234 ����������һ��
int main2(){
	char src[32] = "abcd1234";

	my_memcpy1(src + 1, src, strlen(src) + 1);

	printf("%s\n", src);
	system("pause");
	return 0;
}
// ��ӡ��bcd1234, �ַ�������������һλ
int main3(){
	char src[32] = "abcd1234";

	my_memcpy1(src, src + 1, strlen(src) + 1);

	printf("%s\n", src);
	system("pause");
	return 0;
}
// ����(������)Ϊmemmove, memmoveҲΪ����
// memmove ��memcpy ����: memcpy�ڲ�����Ҫ�����ص� memmove��Ҫ����
// ���𲻴�, ���ȵ�һ��վ�ڱ�׼���ʵ�� ���߶����ֽڿ���,����ʵ�ֿ���
// ģ��ʵ��ʱ���в�� ʵ��ʱ�Ƽ�memmove 
// ��ʷ��������, ������ 
int main(){
	char src[32] = "abcd1234";

	memmove(src + 1, src,  strlen(src) + 1);

	printf("%s\n", src);
	system("pause");
	return 0;
}






















