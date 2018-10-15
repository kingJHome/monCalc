#include <stdio.h>
#include <string.h>
#include "calcFun.h"

//字符串转换为整形
void parttoi(char *vals,int *result,size_t *start,size_t len);
//表达式计算
void expressCalculation(char *content);
//读取文件内容
void readFileContent(char *filename,char *content);

int main(int argc,char *argv[]){
	char *content = NULL;

	readFileContent("expression.txt",content);

	return 0;
}

void parttoi(char *vals,int *result,size_t *start,size_t len){
	size_t st = *start,
		   slen = 0;
	
	for( ; st<len && isdigit(vals[st]); ++st,++slen);
	*result = atoi( vals );
	*start += slen;
}

void expressCalculation(char *content){
	if( expressionValid(content) ){
		size_t start = 0,
			   nlen = strlen(content);
		CharOp *opss = NULL,*numss = NULL;
		
		initStack( &opss, Op );
		initStack( &numss, Num );
		while(start < nlen){
			if( !inOp(content[start]) ){//不为操作符
				int num = 0;
				parttoi(content,&num,&start,nlen);
				enStack(numss, &num);
			}else{
				switch(priorityCal(getTop(opss),content[start])){
					case -1:
						break;
					case 0:
						break;
					case 1:
						break;
				}
				start++;
			}
		}
	}
}

void readFileContent(char *filename,char *content){
	FILE *fp = fopen(filename,"r");

	if( fp ){
		char sep = '\n';
		size_t clen = 0;

		while( getline(&content, &clen, fp)!=-1 ){
			char *endFlag = strchr(content, sep);

			clen = 0;
			*endFlag = '\0';
			expressCalculation(content);
		}
	}
}
