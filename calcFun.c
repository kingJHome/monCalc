#include "calcFun.h"

//是否是运算符(包括括号)
int inOp(char inchar){
	int isOp = 0;
	char ops = "+-*/()";

	if( strchr(ops, inchar) ){
		isOp = 1;
	}

	return isOp;
}

//表达式是否正确
int expressionValid(char *press){
}

//运算符优先级判断
int priorityCal(char prev,char next){
}

//栈容量增加
void addStackSize(CharOp *so){
}

//入栈
void enStack(CharOp *so,char inc){
}

//出栈
void deStack(CharOp *so,char *gc){
}

//获取栈顶元素
char getTop(CharOp *so){
	char result = '\0';

	if( so->length ){
		result = so->chars[so->curPos-1];
	}
	
	return result;
}
