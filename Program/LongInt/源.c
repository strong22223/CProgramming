#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define  MAX  1000
 


_Bool swapInt(char* A,int * B ) {//��������ĳ�������
	int* begin_B = B;//�������
	int* begin_A = A;

	*B = strlen(A);//B����λ���������洢λ��
	B++;
	A = A + strlen(A) - 1;//�ڴ洢���ֵ�ʱ�䵹��洢

	while (A>=begin_A) {
		if (isdigit(*A)) {
			*B = *A - '0';
		}
		else {
			printf("�������\n���������룺");
			return 0;
		}
		A--; 
		B++;//����
	};//������������

	//��������
	//���½�B��λ�ø���ʼλ��
	B = begin_B;
	for (int i = 1; i <=B[0]; i++)
		printf("%d", B[i]);
	return 1;
}
//����

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
	static int Result[MAX]={0};
	int ShortInt[MAX];
	memset(Result, 0, sizeof(Result));
	memset(ShortInt, 0, sizeof(ShortInt));
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
		printf("0");
		exit(0);
	}
 //ִ�г˷������ն̵�Ϊ��׼�����̵�������Ϊ��׼��
	int mar[20][20] = { 0 };
	memset(mar, 0, sizeof(mar));
	for (int i = 1,k=0; i <= ShortInt[0]; i++) {//k�����ڽ���
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
	//�������ĳ���
	if (Result[ShortInt[0] + A[0]] != 0) {
		Result[0] = ShortInt[0] + A[0] ;
	 }else Result[0] = ShortInt[0] + A[0]-1 ;
	return Result;
}
int main()
{
	int ShortInt, *LongInt;//��������	
	LongInt=InPut_Long();//���볤������

	printf("������һ����ͨ������");
	scanf_s("%d", &ShortInt);

	int* result = Multiplicate(LongInt, ShortInt);
	for (int i =result[0]; i >= 1; i--)
		printf("%d", result[i]);

	 
		
	return 0;
}               