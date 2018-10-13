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
	int valid = 1,
		lbra = 0,
		rbra = 0;
	char *curChar = strdup(press);
	size_t pos = 0,
		   plen = strlen(curChar);
	
	//检测括号是否正确
	for( ; pos < plen; ++pos){
		if(	curChar[pos]=='(' ){
			lbra++;
		}
		if( curChar[pos]==')' ){
			rbra++;
		}
	}
	if( lbra != rbra ){
		valid = 0;
	}else{//检测四则运算符号表达式是否正确
		char sepe[] = "+-*/",
			 *sval = NULL;

		if( strspn(curChar, sepe) ){//表达式以运算符开头
			valid = 0;
		}else{
			for( pos = 0; pos < plen; ++pos){
				if( curChar[pos]=='(' || curChar[pos]==')' ){
					curChar[pos] = '@';
				}else if( isdigit(curChar[pos]) ){
					curChar[pos] = '#';
				}
			}

			while( sval = strsep(&curChar, sepe) ){
			}
		}
	}
	free(curChar);

	return valid;
}

//运算符优先级判断
int priorityCal(char prev,char next){
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
