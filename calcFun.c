#include "calcFun.h"

void removeSpace(char *strs){
	char *spacer = NULL;

	while( (spacer = strchr(strs,' ')) != NULL ){
		while( *spacer!='\0'){
			*spacer = *(spacer + 1);
			spacer++;
		}
	}
}

//是否是运算符(包括括号)
int inOp(char inchar){
	int isOp = 0;
	char ops[] = "+-*/()";

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

//初始化栈
void initStack(CharOp **so,onChose type){
	if( *so == NULL ){
		*so = (CharOp*)malloc(sizeof(CharOp));		
	}
	
	(*so)->cp = type;
	if( type == Op ){
		(*so)->onW.ops = NULL;
	}else{
		(*so)->onW.nums = NULL;
	}
	(*so)->curPos = 0;
	(*so)->length = 0;
}

//栈是否为空
int emptyStack(CharOp *so){
	int empty = 0;
	
	if( so->length==0 || so->curPos==0 ){
		empty = 1;
	}

	return empty;
}

//栈容量增加
void addStackSize(CharOp *so){
	if( so->curPos == so->length ){//栈满,申请更多空间
		int newlen = 0;
		
		if( so->cp == Op ){
			if( so->onW.ops == NULL ){
				newlen = 1;
				so->onW.ops = (char*)malloc(sizeof(char));
			}else{
				newlen = so->length + so->length / 2 + 1;
				char *result = (char*)realloc(so->onW.ops,newlen * sizeof(char));
			}
			assert( so->onW.ops );
		}else{
			if( so->onW.nums == NULL ){
				newlen = 1;
				so->onW.nums = (int*)malloc(sizeof(int));
			}else{
				newlen = so->length + so->length / 2 + 1;
				int *result = (int*)realloc(so->onW.nums,newlen * sizeof(int));
			}
			assert( so->onW.nums );
		}		
		so->length = newlen;
	}
}

//入栈
void enStack(CharOp *so,void *inc){
	addStackSize(so);
	if( so->cp == Op ){
		so->onW.ops[so->curPos++] = *(char*)inc;
	}else{
		so->onW.nums[so->curPos++] = *(int*)inc;
	}
}

//出栈
void deStack(CharOp *so,void *gc){
	if( so->curPos ){
		if( so->cp == Op){
			char *op = (char*)gc;
			*op = so->onW.ops[so->curPos--];
		}else{
			int *num = (int*)gc;
			*num = so->onW.nums[so->curPos--];
		}
	}
}

//获取栈顶元素
void* getTop(CharOp *so){
	if( so->length ){
		if( so->cp== Op ){
			return so->onW.ops+so->curPos-1;
		}else{
			return so->onW.nums+so->curPos-1;
		}
	}else{
		return NULL;
	}
}
