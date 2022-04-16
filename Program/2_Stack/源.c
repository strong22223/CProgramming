#include<stdio.h>


//定义类栈的结构体
#define MAXSIZE 101
typedef struct {
	int  data[MAXSIZE];
	int top;
}Stack;
//出栈
_Bool Pop(Stack *S) {
	if (S->top <= -1) {
		return 0;
	}
	while (S->top>=0) {
		printf("%d ", S->data[S->top]);
		S->top--;
	}return 1;
}

//初始化栈,没有数据的时间，栈顶为-1.
void InitStack(Stack *S) {
	S->top = -1;
}

//判断栈是否为空
_Bool StackEmpty(Stack S) {
	if (S.top == -1) {
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
	printf("入栈：请输入整数每个整数之间使用空格隔开,输入\"exit\"停止\n");
	int nu;
	while (scanf_s("%d", &nu)==1) {
		S->top++;
		S->data[S->top] = nu;
	}
	//操作后展示战中的元素
	Pop(S);

	return 1;
}


//读取栈顶元素
int GetTop(Stack *S) {
	if (S->top <= -1) {
		printf("错误！");
		exit();
	}
	return S->data[S->top];
}
int main()
{
	Stack S;
	//入栈
	InitStack(&S);
	Push(&S);

	printf("返回栈顶元素:");
	GetTop(&S);



	return 0;
}