#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define  MAX  1000
 
 

_Bool swapInt(char* A,int * B ) {//处理输入的长整数。
	*B = strlen(A);//B的首位数字用来存储位数
	B++;
	int* flag = B;
	while (*A) {
		if (isdigit(*A)) {
			*B = *A - '0';
		}
		else {
			printf("输入错误！\n请重新输入：");
			return 0;
		}
		A++; B++;//自增
	}
	//检测输出！
	while (*flag) {
		printf("%d", *flag);
		flag++;
	}
	return 1;
}
int* InPut_Long() {
	static int LongInt[MAX];
	static char str[MAX];//用来读取读取长整数。

	printf("请输入一个长整数：");
	gets_s(str, MAX);
	while (!swapInt(str, LongInt)) {//输入错误的时间重新输入。
		gets_s(str, MAX);
	}

	return LongInt;
}
int* Multiplicate(int* A, int num) {
	static int Result[MAX];
	int ShortInt[MAX];
	int* LongInt = strlen(A) - 1;//长数指向尾部
	int i = 1;
	if (num) {//不是0的时间
		do {
			ShortInt[i] = num % 10;
			num /= 10;
			i++;
		} while (num);
		ShortInt[0] = i-1;//0位用来存储普通数字的位数
	}
	else{
		ShortInt[0] = 1;
	}
 //执行乘法
	for (int j = 1; j < i; j++) {
		for (int k = 1; k < strlen(A); k++) {

		}
	}
	return;
}
int main()
{
	int ShortInt, *LongInt;//用来接收	
	LongInt=InPut_Long();//输入长整数。
	printf("请输入一个普通整数：");
	scanf_s("%d", &ShortInt);
	Multiplicate(LongInt, ShortInt);


	 
		
	return 0;
}               