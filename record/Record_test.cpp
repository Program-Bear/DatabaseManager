#include<iostream>
#include<stdlib.h>
#include "Record.h"

#include "../bufmanager/BufPageManager.h"
#include "../fileio/FileManager.h"
#include "utils/pagedef.h"

using namespace std;
int main(){
	MyBitMap::initConst();
	FileManager* fm = new FileManager();
	BufPageManager* bpm = new BufPageManager(fm);
	
	fm -> createFile("Book_Record_Test.txt")
	fm -> createFile("Orders_Record_Test.txt")
	int bfi,ofi;
	fm -> openFile("Book_Record_Test.txt",bfi);
	fm -> openFile("Orders_Record_Test.txt",ofi);

	char title[] = "Gone with the wind";
	char author[] = "Margaret Mitchell";
	char publisher[] = "人民出版社";
	int copies = 10;

	Book* book = new Book(title, author, publisher, copies);
	cout << "创建一条图书记录" << endl;
	Record* book_record = new Record(book);	
	book_record -> output();

/*
	cout << "当前记录的状态位为:" << (record -> get_state() >> 31) << endl;
	cout << "当前记录的主键位的index数值为: " << (record -> get_primary_index()) << endl;
	cout << "当前记录的第3个int字段的数值为: " << (record -> get_int_attribute(3)) << endl;
	cout << "当前记录的第5个string字段的数值为:";
	char* temp = record -> get_char_attribute(5);
	for (int i = 0; i < record -> get_attribute_length(5); i++){
		cout << (int)record -> get_char(5,i);
	}
	cout << endl;

*/	
	
}
