//
//  Common.hpp
//  Periodic Task Schedular
//
//  Created by Bir Bahadur Khatri on 24/11/2021.
//

#ifndef Common_hpp
#define Common_hpp

#include <stdio.h>
#include <string>
void initialize();
int getNumberOfRows(std::string table);
float getValue(std::string table, std::string column, std::string command);

#endif /* Common_hpp */
