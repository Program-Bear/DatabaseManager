#ifndef RECORD_H
#define RECORD_H
#define WRONG_INT -2147483647
#define WRONG_CHAR 0
#define INTEGER 0
#define STRING 1
#define ERROR -1
/*
 * 该头文件定义了数据库中的每一条记录在内存中存储时应当遵循的储存规则，请相关开发人员仔细阅读
 * 1. state：
 * 记录开始的状态位，记录了当前记录中的主键类型
 * state >> 31 -> 获得主键类型，0表示为int，1表示为char*
 * 其他位暂时留用，供未来拓展使用
 * 2. primary_index
 * 获取主键对应的index码
 * 3. int_size：
 * 记录了该记录中int类型的字段的总个数
 * 4. int* int_array:
 * int 类型的字段的开始地址
 * 5. char_size：
 * 记录了该记录中char*（字符串）类型字段的总个数
 * 6. char_length:
 * 各个字符串长度记录数组的开始地址
 * 7. char** char_array:
 * 所有字符串字段的开始地址
 * 
 * 主要的成员方法有：
 * get_state()
 * 用于读取当前Record的状态位state
 *
 * get_primary_index()
 * 获取主键对应的index码
 *
 * get_int_attribute(int index)
 * 用于获得第index个整数类型的字段
 * 
 * get_char_attribute(int index)
 * 用于获取第index个字符串类型的字段
 *
 * get_attribute_length(int index)
 * 用于获取第index个字符串的总长度
 *
 * get_attribute_type(int index)
 * 直接获得第index个字段对应的类型，0表示整数，1表示字符串, -1表示错误
 *
 * get_char(int index, int pos)
 * 获得第index个字符串的第pos个位置的字符
 *
 * bool save(void* target_address)
 * 将当前的Record中的内容写到从start_address开始的连续内存空间中
 *
 * bool load(void* source_address)
 * 使用从source_address位置开始的内存空间来构造当前记录
*/
struct Book{
    char* title;
    char* author;
    char* publisher;
    int copies;
    public Book(char* _t, char* _a, char* _p, int _c){
        title = _t;
        author = _a;
        pulisher = _p;
        copies = _c;
    }
};

struct Customer{
    char* name;
    char* gender;
    public Customer(char* n, char* g){
        name = n;
        gender = g;
    }
};

struct Website{
    char* name;
    char* url;
    public Website(char* n, char* u){
        name = n;
        url = u;
    }
};

struct Price{
    int web_id;
    int book_id;
    double price;
    public Price(int a, int b, int p){
        web_id = a;
        book_id = b;
        price = p;
    }
};

struct Orders{
    int web_id;
    int cus_id;
    int bok_id;
    char* data;
    int quantity;
    public Orders(int a, int b, int c, int d, char* f){
        web_id = a;
        cus_id = b;
        bok_id = c;
        data = f;
        quantity = d;
    }
};

class Record{
	int state;
	int primary_index;
	int int_size;
	int* int_array;
	int char_size;
    	int* char_length;
	char** char_array;
    	Record(){}
    	~Record(){
        	delete[] int_array;
        	for (int i = 0; i < char_size; i++){
            		delete *(char_array + i);
        	}
        	delete char_array;
        	delete[] char_length;
    	}

	void init(int _is, int _cs, int * len, int _pi = 0, bool is_primary_int = true){//初始化一条空记录
        	if (is_primary_int){
         	   	state = 1 << 31;
        	}
        	else{
            		state = 0;
        	}
        	primary_index = _pi;
        	int_size = _is;
        	char_size = _cs;
        	int_array = new int[int_size];
        	for (int i = 0; i < int_size; i++){
            		int_array[i] = 0;
        	}
       		char_length = new int[char_size];
        	for (int i = 0; i < char_size; i++){
            		char_length[i] = len[i];
        	}
        	char_array = new char*[char_size];
        	for (int i = 0; i < char_size; i++){
            		char_array[i] = new char[char_length[i]];
            		for(int t = 0; t < char_length[i]; t++){
                		char_array[i][t] = (char)20;
            		}
        	}
    	}

	public:
    	Record(int _is, int _cs, int* len,  int _pi = 0, bool is_pri_int = true){//初始化一条空记录
            init(_is,_cs,len,_pi,is_pro_int);
        }
    
    
    	Record(void* source_address);
    
        Record(Book* book);
    
        Record(Customer* customer);
    
        Record(Website* website);
    
        Record(Orders* orders);
    
        Record(Price* price);
    
        int get_state(){return state;}
        int get_primary_index(){return primary_index;}
        int get_int_attribute(int index){
            if (index > int_size) return WRONG_INT;
            return int_array[index];
        }
        char* get_char_attribute(int index){
            if (index > char_size) return (char)WRONG_CHAR;
            return char_array[index];
        }
    	int get_attribute_length(int index){
        	if (index > char_size) return WRONG_INT;
            return char_length[index];
    	}
    	char get_char(int index, int pos){
        	return char_array[index][pos];
    	}
	
    
        int get_total_size();

        int get_attribute_type(int index);

        bool save(void* target_address);
	
        bool load(void* source_address);

        void output();

    //bool load(void* start_address, int record_size);
    //bool save(void* target_address);
};
#endif
