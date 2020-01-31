#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

// 模拟实现memcpy
void* my_memcpy(void* dst, const void* src, int num){
	assert(dst);
	assert(src);

	char* dst_p = (char*)dst;
	const char* src_p = (const char*)src;
	// num--: n为几 循环几次
	while (num--){
		*dst_p = *src_p;
		dst_p++, src_p++; 
	}
	return dst;
}
// 一共要拷贝num个元素,把num个元素整体往后移动 
// <= 先移最后一个 
// <= 指针必须先指到num-1个
// 
// 把src的内容整体往后移一个,得一个一个往后移从右往左移,
// <= 得先移最右侧,
// <= 必须指向最右侧,num元素的最后一个
// <= 指针+num-1(*num-1) 然后往dst里写
void* my_memcpy1(void* dst, const void* src, int num){
	assert(dst);
	assert(src);

	char* dst_p = (char*)dst;
	const char* src_p = (const char*)src;
	

	if (dst_p > src_p && dst_p < src_p + num){
		dst_p = dst_p + num - 1;
		src_p = src_p + num - 1;
		// 两者都指向字符串末尾 要拷贝num个元素 memcpy不需要考虑'\0'这个问题
		// 要想拷贝num个元素,最终指针应该挪到num-1的位置,
		// 
		while (num--){
			// 把src结尾的内容放在dst结尾
			*dst_p = *src_p;
			dst_p--, src_p--;
		}
	} // = > dst 落在了src里
	else {
		while (num--){
			*dst_p = *src_p;
			dst_p++, src_p++;// 从右往左拷
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
// 打印aabcd1234 整体往后移一个
int main2(){
	char src[32] = "abcd1234";

	my_memcpy1(src + 1, src, strlen(src) + 1);

	printf("%s\n", src);
	system("pause");
	return 0;
}
// 打印出bcd1234, 字符串整体往左移一位
int main3(){
	char src[32] = "abcd1234";

	my_memcpy1(src, src + 1, strlen(src) + 1);

	printf("%s\n", src);
	system("pause");
	return 0;
}
// 以上(左右移)为memmove, memmove也为拷贝
// memmove 与memcpy 区别: memcpy内部不需要考虑重叠 memmove需要考虑
// 区别不大, 首先第一点站在标准库的实现 两者都叫字节拷贝,都能实现拷贝
// 模拟实现时会有差别 实用时推荐memmove 
// 历史遗留问题, 兼容性 
int main(){
	char src[32] = "abcd1234";

	memmove(src + 1, src,  strlen(src) + 1);

	printf("%s\n", src);
	system("pause");
	return 0;
}






















