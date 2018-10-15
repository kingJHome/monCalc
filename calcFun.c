#include "calcFun.h"

void removeSpace(char *strs){
	char *spacer = NULL;

	while( (spacer = strchr(strs,' ')) != NULL ){
		*(spacer - 1) = *spacer;
	}
}

//是否是运算符(包括括号)
int inOp(char inchar){
	int isOp = 0;
	char ops = "+-*/()";

	if( strchr(ops, inchar) ){
		isOp = 1;
	}

	return isOp;
}

//表达式括号是否匹配正确
int expressionValid(char *press){
	int valid = 1,
		lbra = 0,
		rbra = 0;
	size_t pos = 0,
		   plen = 0;
	
	//清除空格
	removeSpace(press);
	plen = strlen(press);

	//检测括号是否正确
	for( ; pos < plen; ++pos){
		if(	press[pos]=='(' ){
			lbra++;
		}
		if( press[pos]==')' ){
			rbra++;
		}
	}
	if( lbra != rbra ){
		valid = 0;
	}

	return valid;
}

//运算符优先级判断
int priorityCal(char prev,char next){
	int priority = 0;

	switch( prev ){
		case '+': case '-':
			if(next=='+' || next=='-' || next==')'){
				priority = 1;
			}else if(next=='*' || next=='/' || next=='('){
				priority = -1;
			}
			break;
		case '*': case '/':
			if(next=='+' || next=='-' || next=='*' || next=='/' || next==')'){
				priority = 1;
			}else if(next=='('){
				priority = -1;
			}
			break;
		case '(':
			if(next==')'){
				priority = 0;
			}else{
				priority = -1;
			}
			break;
		case ')':
			priority = -1;
			break;
	}

	return priority;
}

//栈是否为空
int emptyStack(CharOp *so){
	int empty = 0;
	
	if( so->length==0 ){
		empty = 1;
	}

	return empty;
}

//栈容量增加
void addStackSize(CharOp *so){
	if( so->curPos == so->length ){//栈满,申请更多空间
		int newlen = 0;
		if( so->chars == NULL ){
			newlen = 1;
			so->chars = (char*)malloc(sizeof(char));
		}else{
			int newlen = so->length + so->length / 2 + 1;					
			realloc(so->chars,newlen * sizeof(char));
		}
		assert( so->chars );
		so->length = newlen;
	}
}

//入栈
void enStack(CharOp *so,char inc){
	addStackSize(so);	
	so->chars[so->curPos++] = inc;
}

//出栈
void deStack(CharOp *so,char *gc){
	if( so->curPos ){
		*gc = so->chars[so->curPos--];
	}
}

//获取栈顶元素
char getTop(CharOp *so){
	char result = '\0';

	if( so->length ){
		result = so->chars[so->curPos-1];
	}
	
	return result;
}
