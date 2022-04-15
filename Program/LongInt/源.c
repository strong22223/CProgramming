#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define  MAX  1000
 


_Bool swapInt(char* A,int * B ) {//处理输入的长整数。
	int* begin_B = B;//测试输出
	int* begin_A = A;

	*B = strlen(A);//B的首位数字用来存储位数
	B++;
	A = A + strlen(A) - 1;//在存储数字的时间倒序存储

	while (A>=begin_A) {
		if (isdigit(*A)) {
			*B = *A - '0';
		}
		else {
			printf("输入错误！\n请重新输入：");
			return 0;
		}
		A--; 
		B++;//自增
	};//结束符别忘记

	//检测输出！
	//重新将B的位置给初始位置
	B = begin_B;
	for (int i = 1; i <=B[0]; i++)
		printf("%d", B[i]);
	return 1;
}
//输入

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
	static int Result[MAX]={0};
	int ShortInt[MAX];
	memset(Result, 0, sizeof(Result));
	memset(ShortInt, 0, sizeof(ShortInt));
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
		printf("0");
		exit(0);
	}
 //执行乘法，依照短的为基准来将短的数字作为基准乘
	int mar[20][20] = { 0 };
	memset(mar, 0, sizeof(mar));
	for (int i = 1,k=0; i <= ShortInt[0]; i++) {//k作用于交替
		for (int j = 1; j <= A[0]; j++) {
			mar[i][j + k] = ShortInt[i] * A[j];
		}k++;
	}
		
	int j=0, k = 0,a=0,length=1;
	for (j = 1; j <= A[0]+ShortInt[0]-1; j++) {

		for (k = 1; k <= ShortInt[0] && k <= j; k++) {
			a += mar[k][j];
		}
		
		Result[length++] = a % 10;
		a /= 10;
		Result[0] = length;
	 }
	//保存结果的长度
	if (Result[ShortInt[0] + A[0]] != 0) {
		Result[0] = ShortInt[0] + A[0] ;
	 }else Result[0] = ShortInt[0] + A[0]-1 ;
	return Result;
}
int main()
{
	int ShortInt, *LongInt;//用来接收	
	LongInt=InPut_Long();//输入长整数。

	printf("请输入一个普通整数：");
	scanf_s("%d", &ShortInt);

	int* result = Multiplicate(LongInt, ShortInt);
	for (int i =result[0]; i >= 1; i--)
		printf("%d", result[i]);

	 
		
	return 0;
}               