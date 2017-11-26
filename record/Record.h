#ifndef RECORD_H
#define RECORD_H

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
    public Book(
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

struct Index{
	long long key;
	int pageid;
	int offset;
	public Index(long long _key, int _pageid, int _offset){
		key = _key;
		pageid = _pageid;
		offset = _offset;
	}
}


class Record{
	int state;
	int primary_index;
   	int* char_length;
    	Record(){}
    	~Record(){
        	delete[] int_array;
        	for (int i = 0; i < char_size; i++){
            		delete *(char_array + i);
        	}
        	delete char_array;
        	delete[] char_length;
    	}
    
        int get_state(){return state;}
    
        int get_type();

        bool save(void* target_address);
	
        bool load(void* source_address);

        void output();
};
#endif
