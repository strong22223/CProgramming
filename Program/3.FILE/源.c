#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAXSIZE 1000
//���滻����ַ���ת�뵽����һ���ļ���
FILE* getStr(FILE* S, char* str,char * replace) {
	//�������Ҵ��ļ�
	static FILE* another;
	if (fopen_s(&another, "D:\\Programming\\WorkRport\\AnotherEnglish.txt", "w+") != 0) {
		printf("ERROR!");
		exit(0);
	}
	//���ļ�S�ж�ȡ������д��flag
	char flag[1000];
	fgets(flag, 1000, S);
	char* P = flag;
	while (*P) {
		if (strncmp(P, str, strlen(str)) == 0)
		{	//�����滻
			//strncpy_s(P,strlen(P), replace, strlen(str));
			for (int i = 1; i <= strlen(str); i++)
			{
				*P = replace[i - 1];
				P++;
			}
			printf("�Ѿ��Ҽ���\n");
			break;
		}
		P++;	
	}
	//����������ַ���д��another
	fputs(flag, another);
	fclose(S);
	fclose(another);
	return another;
}

void num(FILE* fp) {
	char str[MAXSIZE];
	int num[27];
	memset(num, 0, sizeof(num));//������Ϊ0
	 
 
	int i = 0;
	fgets(str,MAXSIZE, fp);
	puts(str);
	for (int i = 0; i < strlen(str); i++) {
		 
		char flag = tolower(str[i]);
		if(isalpha(flag))
		num[flag - 'a' + 1]++;//ͳ�Ƹ���
	}

	int  c = 'A';
	printf("������ÿ����ĸ���ֵĴ����������ִ�Сд��\n");
	for (int i = 1; i <= 26; i++) {
		printf("%c�ĸ�����:", c);
		c++;
		printf("%d\n", num[i]);
	}
	//fclose(fp);
}
int main()
{
	//���ļ�
	FILE* fp;
	if (fopen_s(&fp,"D:\\Programming\\WorkRport\\English.txt", "r") !=0) {
		printf("ERROR!");
		exit(0);
	}
	//ͳ����ĸ�г��ֵĸ���
		num(fp);

	//���Ҳ��滻�ı��е�ĳ�ַ��������滻����ı�������һ���ļ���
		if (fopen_s(&fp, "D:\\Programming\\WorkRport\\English.txt", "r") != 0) {
			printf("ERROR!");
			exit(0);
		}
	char str[100];
	printf("��������Ҫ���ҵ��ַ�����");
	gets_s(str, 100);
	printf("��������Ҫ�滻Ϊ���ַ�����");
	char re[100];
	gets_s(re, 100);
	getStr(fp, str,re);//�ú�������һ���򿪵��ļ�

	 
	return 0;
}