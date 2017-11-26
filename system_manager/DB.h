#ifndef DB_E
#define DB_E
#include "../file/File.h"
#include "../file/file_def.h"
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
using namespace std;

class DB
{
	File* file_head;
	char name[1024];
public:
	DB* next;
	DB(char* _name){
		file = NULL;
		next = NULL;
		strcpy(this -> name, _name);
	}
	void initDB(char* path){//初始化数据库
		string now_path(path);
		now_path = now_path + "/" + name;
		DIR* nowDir = opendir(now_path.c_str());
		now_path = now_path + "/";
		dirent* nowFile;
		File* work_node = NULL;
		while((nowFile = readdir(nowDir)) != NULL){
			string fileName(nowFile -> d_name);
			if (nowFile -> d_type == 4) continue;
			p = new File(now_path);
			p -> reset(fileName);
			if (file_head == NULL){
				file_head = p;
				work_node = file_head;
			}	
			else{	
				work_node -> next = p;
				work_node = p;
			}	
		}
	}
	bool create_file(char* filename, FILE_TYPE type, bool null_bit[], int primary_key, int type_length[], char* now_path){//创建一个文件
		//File* new_file = new File();
		string now_path(npath);
		now_path = now_path + "/";
		string now_name(filename);
		File* new_file = new File(now_path);
		if (new_file -> exists(now_name)){
			cout << "[Error] This Table already exists!" << endl;
			delete new_file;
			return false;
		}
		new_file -> init(now_name);
		new_file -> next = this -> file_head;
		file_head = new_file;
		return true;
	}
	bool drop_file(char *filename){//删除一个文件
		File* work_node = file_head;
		File* previous = NULL;
		while(work_node){
			if (strcmp(work_node -> getFilename(),filename) == 0){
				work_node -> deletefile();
				if (previous){
					previous -> next = work_node -> next;
				}
				else{
					file_head = work -> next;
				}
				delete work_node;
				cout << "Delete table " << filename << " successfully!" << endl;
				return true;
			}
			previous = work_node;
			work_node = work_node -> next;
		}
		cout << "[Error] Couldn't find table " << filename << endl;
		return false;
	}
	void show_files(){//显示当前数据库中的表的名称
		File* work_node = file_head;
		if (!work_node){
			cout << "There is no such file in database" << endl;
			return;	
		}
		while(work_node){
			cout << work_node -> getFilename() << endl;
			work_node = work_node -> next;
		}
		return;
	}
	bool show_file(char* filename){//显示某一个文件中的内容
		File* work_node = file_head;
		while(work_node){
			if (strcmp(work_node -> getFilename(),filename) == 0){
				work_node -> show();
				return true;
			}
			work_node = work_node -> next;
		}
		cout << "[Error] Couldn't find such table!" << endl;
		return false;
	}
};
#endif
