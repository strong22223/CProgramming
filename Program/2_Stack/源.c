#include<stdio.h>


//������ջ�Ľṹ��
#define MAXSIZE 101
typedef struct {
	int  data[MAXSIZE];
	int top;
}Stack;
//��ջ
_Bool Pop(Stack *S) {
	if (S->top <= -1) {
		return 0;
	}
	while (S->top>=0) {
		printf("%d ", S->data[S->top]);
		S->top--;
	}return 1;
}

//��ʼ��ջ,û�����ݵ�ʱ�䣬ջ��Ϊ-1.
void InitStack(Stack *S) {
	S->top = -1;
}

//�ж�ջ�Ƿ�Ϊ��
_Bool StackEmpty(Stack S) {
	if (S.top == -1) {
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
	printf("��ջ������������ÿ������֮��ʹ�ÿո����,����\"exit\"ֹͣ\n");
	int nu;
	while (scanf_s("%d", &nu)==1) {
		S->top++;
		S->data[S->top] = nu;
	}
	//������չʾս�е�Ԫ��
	Pop(S);

	return 1;
}


//��ȡջ��Ԫ��
int GetTop(Stack *S) {
	if (S->top <= -1) {
		printf("����");
		exit();
	}
	return S->data[S->top];
}
int main()
{
	Stack S;
	//��ջ
	InitStack(&S);
	Push(&S);

	printf("����ջ��Ԫ��:");
	GetTop(&S);



	return 0;
}