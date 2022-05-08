#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAXSIZE 1000
//将替换后的字符串转入到另外一个文件中
FILE* getStr(FILE* S, char* str,char * replace) {
	//创建并且打开文件
	static FILE* another;
	if (fopen_s(&another, "D:\\Programming\\WorkRport\\AnotherEnglish.txt", "w+") != 0) {
		printf("ERROR!");
		exit(0);
	}
	//从文件S中读取到数据写入flag
	char flag[1000];
	fgets(flag, 1000, S);
	char* P = flag;
	while (*P) {
		if (strncmp(P, str, strlen(str)) == 0)
		{	//进行替换
			//strncpy_s(P,strlen(P), replace, strlen(str));
			for (int i = 1; i <= strlen(str); i++)
			{
				*P = replace[i - 1];
				P++;
			}
			printf("已经找见了\n");
			break;
		}
		P++;	
	}
	//将更换后的字符串写入another
	fputs(flag, another);
	fclose(S);
	fclose(another);
	return another;
}

void num(FILE* fp) {
	char str[MAXSIZE];
	int num[27];
	memset(num, 0, sizeof(num));//数量置为0
	 
 
	int i = 0;
	fgets(str,MAXSIZE, fp);
	puts(str);
	for (int i = 0; i < strlen(str); i++) {
		 
		char flag = tolower(str[i]);
		if(isalpha(flag))
		num[flag - 'a' + 1]++;//统计个数
	}

	int  c = 'A';
	printf("以下是每个字母出现的次数，不区分大小写：\n");
	for (int i = 1; i <= 26; i++) {
		printf("%c的个数是:", c);
		c++;
		printf("%d\n", num[i]);
	}
	//fclose(fp);
}
int main()
{
	//打开文件
	FILE* fp;
	if (fopen_s(&fp,"D:\\Programming\\WorkRport\\English.txt", "r") !=0) {
		printf("ERROR!");
		exit(0);
	}
	//统计字母中出现的个数
		num(fp);

	//查找并替换文本中的某字符串，将替换后的文本存入另一个文件。
		if (fopen_s(&fp, "D:\\Programming\\WorkRport\\English.txt", "r") != 0) {
			printf("ERROR!");
			exit(0);
		}
	char str[100];
	printf("请输入需要查找的字符串：");
	gets_s(str, 100);
	printf("请输入需要替换为的字符串：");
	char re[100];
	gets_s(re, 100);
	getStr(fp, str,re);//该函数返回一个打开的文件

	 
	return 0;
}