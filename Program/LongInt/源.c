#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define  MAX  1000
 
 

_Bool swapInt(char* A,int * B ) {//��������ĳ�������
	*B = strlen(A);//B����λ���������洢λ��
	B++;
	int* flag = B;
	while (*A) {
		if (isdigit(*A)) {
			*B = *A - '0';
		}
		else {
			printf("�������\n���������룺");
			return 0;
		}
		A++; B++;//����
	}
	//��������
	while (*flag) {
		printf("%d", *flag);
		flag++;
	}
	return 1;
}
int* InPut_Long() {
	static int LongInt[MAX];
	static char str[MAX];//������ȡ��ȡ��������

	printf("������һ����������");
	gets_s(str, MAX);
	while (!swapInt(str, LongInt)) {//��������ʱ���������롣
		gets_s(str, MAX);
	}

	return LongInt;
}
int* Multiplicate(int* A, int num) {
	static int Result[MAX];
	int ShortInt[MAX];
	int* LongInt = strlen(A) - 1;//����ָ��β��
	int i = 1;
	if (num) {//����0��ʱ��
		do {
			ShortInt[i] = num % 10;
			num /= 10;
			i++;
		} while (num);
		ShortInt[0] = i-1;//0λ�����洢��ͨ���ֵ�λ��
	}
	else{
		ShortInt[0] = 1;
	}
 //ִ�г˷�
	for (int j = 1; j < i; j++) {
		for (int k = 1; k < strlen(A); k++) {

		}
	}
	return;
}
int main()
{
	int ShortInt, *LongInt;//��������	
	LongInt=InPut_Long();//���볤������
	printf("������һ����ͨ������");
	scanf_s("%d", &ShortInt);
	Multiplicate(LongInt, ShortInt);


	 
		
	return 0;
}               