#include<stdio.h>


//定义类栈的结构体
#define MAXSIZE 101
typedef struct {
	int  data[MAXSIZE];
	int top;
}Stack;
//出栈
_Bool Pop(Stack * S,int num) {

		if (S->top <= -1) {
			printf("此栈为空！\n");
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
		printf("此栈为空！");
		return 0;
	}
	while (S.top>=0) {
		printf("%d ", S.data[S.top]);
		S.top--;
	}
	printf("\n");
	return 1;
}

//初始化栈,没有数据的时间，栈顶为-1.
void InitStack(Stack *S) {
	S->top = -1;
}

//判断栈是否为空
_Bool StackEmpty(Stack *S) {
 
	if (S->top == -1) {
		return 1;
	}return 0;
}
//入栈
_Bool Push(Stack *S) {
	if (S->top >= MAXSIZE - 1) {
		printf("此栈已满！");
			return 0;
	}
	//多次
	printf("入栈:\n");
	int num;
	if (scanf_s("%d", &num)) {
	
			S->top++;
			S->data[S->top] = num;
	}
	else {
		
		printf("错误!\n");;
	}
	//操作后展示战中的元素
	Popall(S);

	return 1;
}


//读取栈顶元素
int GetTop(Stack *s) {
	Stack S = *s;
	if (S.top <= -1) {
		printf("错误！此栈为空！");
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
		printf("请输入你的操作：\n1.入栈\n2.出栈\n3.返回栈顶元素\n");
		scanf_s("%d", &flag); getchar();

		switch (flag) {
		case 1:Push(&S); break;
		case 2: {int num; printf("请输入出栈的次数："); scanf_s("%d", &num); Pop(&S, num); }; break;
		case  3: {	printf("返回栈顶元素:");		  printf("%d\n", GetTop(&S)); }; break;
		default:break;
		}
	}


 

 
	return 0;
}