/*本文件定义了记录管理模块，支持各类文件和记录操作，包括新建文件，删除文件，打开文件，关闭文件，插入记录，删除记录*/

#ifdef RECORD_MANAGER
#define RECORD_MANAGER
#include<iostream>
#include<vector>
#include"../fileio/FileManager.h"
#include"../utils/pagedef.h"
#include"../bufmanager/BufPageManager.h"
#include"page_manager.h"

struct Location{
    int file_id;
    int page_id;
    int slot_id;
    Location(f,p,s){
        file_id = f;
        page_id = p;
        slot_id = s;
    }
};
class Record_Manager{
	FileManager* fm = new FileManager();
	BufPageManage* bp = new BufPageManager(fm);
	public static const int  FIRST_PAGE = 0;//
	//public static const int PAGE_COUNT = 0;
	public static const int MAX_PAGE = 1024;

	public static const int REC_SIZE = 1;
	public static const int REC_PER_PAGE = 2;
	public static const int REC_COUNT = 3;
	public static const int AVL_START = 4;
    
	public static const int FULL = 0;
	public static const int AVAL = 1;
	public static const int PURE = 2;

	Record_Manager(){}
	void initFile(int fileID, unsigned int record_size){
		BufType b = bp -> allocPage(fileID, first_page, page_index, false);
		b[REC_SIZE] = record_size; 
		//b[PAGE_COUNT] = 1; 
		b[REC_COUNT] = 0;
		b[REC_PER_PAGE] = PAGE_SIZE / (record_size + 1); 
        for (int i = FIRST_PAGE + 1; i < MAX_PAGE; i++){
			b[AVL_START + i] = 2;
        }
        
	}
    
public:
	bool creatFile(unsigned int record_size, String file_name){
		if(!fm -> createFile(file_name)) return false;
		int fileID = 0;
		if (!fm -> openFile(file_name, fileID)) return false;
		initFile(fileID, record_size);
		fm -> closeFile(fileID);
		return true;
	}
	int openFile(String file_name){
		int fileID = -1;
		fm -> openFile(file_name, fileID);
		return fileID;		
	}
	void closeFile(int fileID){
		fm -> closeFile(fileID);
	}
	bool insertRecord(int fileID, void* target_record){
        Page* first_page = new Page(bp, fileID, FIRST_PAGE, true);
        target_id = first_page -> get_avaliable_page();
        
        /*int target_id = -1;
		for(int i = 1; i < MAX_PAGE; i++)
			if (first_page[AVL_START+i] != 0){
				traget_id = i;
				break;
			}*/
		
		bool cons = true;
		if (target_id == -1 or target_id > MAX_PAGE) cons = false;
		else{
            Page* page = new Page(bp, fileID, target_id, false);
            cons = page -> insertRecord(target_record);
            first_page -> changeAva(page -> getState());
            delete page;
        }
        delete first_page;
        return cons;
	}
	
	bool removeRecord(Location loc){
        Page* first_page = new Page(bp, fileID, FIRST_PAGE, true);
        Page* page = new Page(bp, loc.file_id, loc.page_id, false);
        bool cons = page -> removeRecord(loc.slot_id);
        first_page -> changeAva(page -> getState());
        delete first_page;
        delete page;
        return cons;
    }

	vector<Location>* queryRecord(int fileID, int attribute_bias, int attribute_type, void* target_record){
        Page* first_page = new Page(bp, fileID, FIRST_PAGE, true);
        vector<Location> * slot_ids = first_page -> queryRecord(attribute_bias, attribute_type, target_record);
        delete first_page;
        return slot_ids;
	}
    
    bool changeRecord(Location loc ,void* target_record){
        Page* page = new Page(bp, loc.file_id, loc.page_id, false);
        bool cons = page -> changeRecord(loc.slot_id, traget_record);
        delete page;
        return cons;
    }
    

};

#endif
