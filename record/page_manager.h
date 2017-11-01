//
//  Header.h
//  
//
//  Created by victor on 22/10/2017.
//
//本文件定义了页内的记录管理模块，支持在页内插入，删除，更改，查询记录

#ifndef Header_h
#define Header_h
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<string.h>
#include"../utils/pagedef.h"
#include"../bufmanager/BufpageManager.h"
class Page{
    BufPageManage* bp;
    BufType content = new unsigned int[PAGE_SIZE];
    int index;
    int record_size;
    
    Page(BufPageManage* bmp, int file_id, int page_id, bool is_first_page){
        bp = bmp;
        BufType temp = bp -> getPage(file_id, page_id, index);
        memcpy(content, temp, PAGE_SIZE);
    }
    ~Page(){
        delete[] content;
    }
    
    
public:
    
    
};



#endif /* Header_h */
