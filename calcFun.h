#ifndef _INTCALC_FUN
#define _INTCALC_FUN

#include <string.h>

typedef struct charOp{
	char *chars;
	int curPos;
	int length;
}CharOp;

//是否是运算符(包括括号)
int inOp(char inchar);

//表达式是否正确
int expressionValid(char *press);

//运算符优先级判断
int priorityCal(char prev,char next);

//栈容量增加
void addStackSize(CharOp *so);

//入栈
void enStack(CharOp *so,char inc);

//出栈
void deStack(CharOp *so,char *gc);

//获取栈顶元素
char getTop(CharOp *so);
#endif
