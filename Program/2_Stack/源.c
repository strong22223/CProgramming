#include<stdio.h>


//������ջ�Ľṹ��
#define MAXSIZE 101
typedef struct {
	int  data[MAXSIZE];
	int top;
}Stack;
//��ջ
_Bool Pop(Stack * S,int num) {

		if (S->top <= -1) {
			printf("��ջΪ�գ�\n");
			return 0;
		}
		while (S->top >= 0&&num) {
			printf("%d \n", S->data[S->top]);
			S->top--;
			num--;
		}return 1;
	}
_Bool Popall(Stack *s) {
	Stack S = *s;
	if (S.top <= -1) {
		printf("��ջΪ�գ�");
		return 0;
	}
	while (S.top>=0) {
		printf("%d ", S.data[S.top]);
		S.top--;
	}
	printf("\n");
	return 1;
}

//��ʼ��ջ,û�����ݵ�ʱ�䣬ջ��Ϊ-1.
void InitStack(Stack *S) {
	S->top = -1;
}

//�ж�ջ�Ƿ�Ϊ��
_Bool StackEmpty(Stack *S) {
 
	if (S->top == -1) {
		return 1;
	}return 0;
}
//��ջ
_Bool Push(Stack *S) {
	if (S->top >= MAXSIZE - 1) {
		printf("��ջ������");
			return 0;
	}
	//���
	printf("��ջ:\n");
	int num;
	if (scanf_s("%d", &num)) {
	
			S->top++;
			S->data[S->top] = num;
	}
	else {
		
		printf("����!\n");;
	}
	//������չʾս�е�Ԫ��
	Popall(S);

	return 1;
}


//��ȡջ��Ԫ��
int GetTop(Stack *s) {
	Stack S = *s;
	if (S.top <= -1) {
		printf("���󣡴�ջΪ�գ�");
		return TMP_MAX_S;
	}
	return S.data[S.top];
}
int main()
{
	Stack S;
	InitStack(&S);
	int flag;
	while (1) {
		printf("��������Ĳ�����\n1.��ջ\n2.��ջ\n3.����ջ��Ԫ��\n");
		scanf_s("%d", &flag); getchar();

		switch (flag) {
		case 1:Push(&S); break;
		case 2: {int num; printf("�������ջ�Ĵ�����"); scanf_s("%d", &num); Pop(&S, num); }; break;
		case  3: {	printf("����ջ��Ԫ��:");		  printf("%d\n", GetTop(&S)); }; break;
		default:break;
		}
	}


 

 
	return 0;
}