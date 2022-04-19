#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#define MAXSize 100

//��һ���ṹ�����ʽ���洢����������Ϊ���ֲ��ֺͷ��Ų���
typedef struct {
	int num[MAXSize];
	char sign;
}LInt;

//�ж��Ƿ�Ϊһ������
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

//����һ��������,����һ���ַ�������ʽ��������
LInt InLInt() {
	printf("������һ����������");
	static LInt n;
	char Nstr[MAXSize];

	gets_s(Nstr, MAXSize);
	//����
	if (!Isdigit(Nstr)) {
		printf("ERROR");
			exit(0);
	}

	//����������,�������洢���ĳ���
	if (Nstr[0] == '-') {
		n.sign = '-';
		n.num[0] = strlen(Nstr) - 1;
	} 
	else {n.sign = '+'; n.num[0] = strlen(Nstr); }
	//��������Ϊһ��������
	for (int i = strlen(Nstr) - 1,k=1; i >= 0&&k<=n.num[0]; i--, k++) {
		n.num[k] = Nstr[i] - '0';
	}
	return n;
}

//��һ����ͨ������ת���ɳ�������
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
	c.num[0] = i;//ȷ������λ��
	return c;
}

//����˷�
char* Mul(LInt Lint, int Nor) {
	
	static char Result[MAXSize];
	int tem[MAXSize];
	LInt a = Lint; LInt b = ToLInt(Nor);
	 
	if ((a.num[0] == 1 && a.num[1] == 0) || b.num[0] == 1 && b.num[1] == 0) {//���ǵ�Ϊ0��ʱ��
		printf("0");		exit(0);
	}
		 
	int result[MAXSize][MAXSize] = { 0 }; memset(result, 0, sizeof(result));
	memset(Result, 0, sizeof(Result));
	memset(tem, 0, sizeof(tem));
	//����һ�£������Զ̵���Ϊ��׼
	if (a.num[0] < b.num[0]) {
		LInt temp = a; a = b; b = temp;
	}

	for (int i = 1,k=0; i <= b.num[0]; k++,i++) 
		for (int j = 1; j <= a.num[0]; j++) {
			result[i][j+k] = b.num[i] * a.num[j];
		}
		
	int c = 0,i=0,j=0,length=1;
	for ( i = 1; i <= a.num[0]+b.num[0]-1; i++) {
		for ( j = 1; j <= b.num[0]&&j<=i; j++) {//��֤�ڼӺ͵�ʱ���λ
			c += result[j][i];
		}
		tem[length++] = c % 10;
		c /= 10;
	}

	//ֱ�Ӵ����λ�Ĳ���
	if (c) {
		tem[a.num[0] + b.num[0]] = c; tem[0] = a.num[0]+b.num[0];
	}
	else tem[ 0]= a.num[0] + b.num[0]-1;

	//�������
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
//������
int main()
{
	LInt c;
	int ShInt;
	c=InLInt();
	printf("������һ����ͨ������");
	scanf_s("%d", &ShInt);
	
	char* s = Mul(c, ShInt);
	puts(s);


	return 0;
}