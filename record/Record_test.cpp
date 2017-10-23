#include<iostream>
#include<stdlib.h>
#include "Record.h"
using namespace std;
int main(){
	cout << "创建一条拥有10个int字段，6个string字段的，以int位主键标识码的记录" << endl;
	Record * record = new Record(true, 10, 6);
	cout << "当前记录的状态位为:" << (record -> get_state() >> 31) << endl;
	cout << "当前记录的主键位的index数值为: " << (record -> get_primary_index()) << endl;
	cout << "当前记录的第3个int字段的数值为: " << (record -> get_int_attribute(3)) << endl;
	cout << "当前记录的第5个string字段的数值为:";
	char* temp = record -> get_char_attribute(5);
	for (int i = 0; i < record -> get_attribute_length(5); i++){
		cout << (int)record -> get_char(5,i);
	}
	cout << endl;

	
	
}
