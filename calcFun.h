#ifndef _INTCALC_FUN
#define _INTCALC_FUN

#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef enum{Op,Num}onChose;

typedef struct charOp{
	onChose cp;
	union{
		char *ops;
		int *nums;
	}onW;
	int curPos;
	int length;
}CharOp;

//是否是运算符(包括括号)
int inOp(char inchar);

//表达式括号是否匹配正确
int expressionValid(char *press);

//运算符优先级判断
int priorityCal(char prev,char next);

//初始化栈
void initStack(CharOp **so,onChose type);

//栈是否为空
int emptyStack(CharOp *so);

//栈容量增加
void addStackSize(CharOp *so);

//入栈
void enStack(CharOp *so,void *inc);

//出栈
void deStack(CharOp *so,void *gc);

//获取栈顶元素
void* getTop(CharOp *so);
#endif
