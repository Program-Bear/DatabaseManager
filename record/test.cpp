#include<iostream>
using namespace std;
class TestClass{
	int a;
	char array[5];
	int c;
public:
	TestClass(int _a, , int _c){
		a = _a;
		array = str;		
		c = _c;
	}

};
int main()
{
	int temp = 0;
	string str = "hell";
	TestClass* test = new TestClass(3,str,4);
	cout << sizeof(temp) << endl;
	cout << sizeof(str) << endl;
	cout << sizeof(*test) << endl;
	
}
