#ifndef DBMS_E
#define DBMS_E
#define MAX_LENGTH 1024
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
class DBMS{
	DB * head;
	const string root = "/database";
public:
	char path[MAX_LENGTH];
	DBMS(){
		head = NULL;
		getcwd(path, MAX_LENGTH);
		now_path = string(path)	+ root;

		DB* work_node;
		DB* previous;

		DIR* nowDIR = opendir(now_path);
		dirent* nowFile;
		while((nowFile = readdir(nowDIR)) != NULL){
			
		}
	}

	bool create(char *s){
	}

	bool drop(char *s){
	}
	
	bool show_dbs(){
	
	}

	bool use(char *s){
	
	}
	
	bool show(){
	
	}

}

#endif

