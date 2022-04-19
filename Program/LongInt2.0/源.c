#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#define MAXSize 100

//以一个结构体的形式来存储长整数，分为数字部分和符号部分
typedef struct {
	int num[MAXSize];
	char sign;
}LInt;

//判断是否为一个数字
_Bool Isdigit(char* S) {

	if (S[0] == '-' || isdigit(S[0])) {
		S++;
		while (*S) {
			if (!isdigit(*S))
				return 0;
			S++;
		}
	}
	else return 0;
	return 1;
}

//输入一个长整数,是以一个字符串的形式来接受他
LInt InLInt() {
	printf("请输入一个长整数：");
	static LInt n;
	char Nstr[MAXSize];

	gets_s(Nstr, MAXSize);
	//处理
	if (!Isdigit(Nstr)) {
		printf("ERROR");
			exit(0);
	}

	//处理正负号,并且来存储他的长度
	if (Nstr[0] == '-') {
		n.sign = '-';
		n.num[0] = strlen(Nstr) - 1;
	} 
	else {n.sign = '+'; n.num[0] = strlen(Nstr); }
	//处理他作为一个长整数
	for (int i = strlen(Nstr) - 1,k=1; i >= 0&&k<=n.num[0]; i--, k++) {
		n.num[k] = Nstr[i] - '0';
	}
	return n;
}

//将一个普通的整数转换成长整数来
LInt ToLInt(int num){
	static LInt c;
	int len = 0;
	if (num < 0)c.sign = '-';
	else c.sign = '+';
	num = abs(num);
	int i = 0;
	do {
		c.num[i+1] = num % 10;
		num /= 10;
		i++;
	} while (num);
	c.num[0] = i;//确定他的位数
	return c;
}

//计算乘法
char* Mul(LInt Lint, int Nor) {
	
	static char Result[MAXSize];
	int tem[MAXSize];
	LInt a = Lint; LInt b = ToLInt(Nor);
	 
	if ((a.num[0] == 1 && a.num[1] == 0) || b.num[0] == 1 && b.num[1] == 0) {//考虑到为0的时间
		printf("0");		exit(0);
	}
		 
	int result[MAXSize][MAXSize] = { 0 }; memset(result, 0, sizeof(result));
	memset(Result, 0, sizeof(Result));
	memset(tem, 0, sizeof(tem));
	//交换一下，首先以短的作为基准
	if (a.num[0] < b.num[0]) {
		LInt temp = a; a = b; b = temp;
	}

	for (int i = 1,k=0; i <= b.num[0]; k++,i++) 
		for (int j = 1; j <= a.num[0]; j++) {
			result[i][j+k] = b.num[i] * a.num[j];
		}
		
	int c = 0,i=0,j=0,length=1;
	for ( i = 1; i <= a.num[0]+b.num[0]-1; i++) {
		for ( j = 1; j <= b.num[0]&&j<=i; j++) {//保证在加和的时间错位
			c += result[j][i];
		}
		tem[length++] = c % 10;
		c /= 10;
	}

	//直接处理进位的操作
	if (c) {
		tem[a.num[0] + b.num[0]] = c; tem[0] = a.num[0]+b.num[0];
	}
	else tem[ 0]= a.num[0] + b.num[0]-1;

	//处理符号
	if(a.sign==b.sign)
	for (j = 0, i = tem[0]; i >= 1; i--,j++) {
		Result[j] = tem[i]+'0';
	}
	else {
		Result[0] = '-';
		for (j = 1, i = tem[0]; i >= 1; i--, j++) {
				Result[j] = tem[i] + '0';
			}
	}
	Result[j] = '\0';
	return Result;
}
//主函数
int main()
{
	LInt c;
	int ShInt;
	c=InLInt();
	printf("请输入一个普通整数：");
	scanf_s("%d", &ShInt);
	
	char* s = Mul(c, ShInt);
	puts(s);


	return 0;
}