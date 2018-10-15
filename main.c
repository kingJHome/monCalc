#include <stdio.h>
#include <string.h>
#include "calcFun.h"

//整形转换为字符串
char* itoa(int num);
//表达式计算
void expressCalculation(char *content);
//读取文件内容
void readFileContent(char *filename,char *content);

int main(int argc,char *argv[]){
	char *content = NULL;

	readFileContent("expression.txt",content);

	return 0;
}

char* itoa(int num){

}

void expressCalculation(char *content){
	CharOp opChar = {NULL,0,0},
		   numChar = {NULL,0,0};
	size_t clen = strlen(content);
	
	//for( )
}

void readFileContent(char *filename,char *content){
	FILE *fp = fopen(filename,"r");

	if( fp ){
		char delim[] = "\n";
		size_t clen = 0;

		while( getline(&content, &clen, fp)!=-1 ){
			char *endFlag = strchr(content, delim);

			clen = 0;
			*endFlag = '\0';
			expressCalculation(content);
		}
	}
}
