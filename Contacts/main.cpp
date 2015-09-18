//
//  main.cpp
//  Contacts
//
//  Created by Jan Seredynski on 14/09/15.
//  Copyright (c) 2015 Jan Seredynski. All rights reserved.
//

#include <iostream>
#include <fstream>

#include <vector>
#include <string>
#include <map>

#include "OutputSerializer.h"
#include "InputSerializer.h"


#include "Number.h"
#include "Contact.h"
#include "Contact_v1.h"




int main(int argc, const char * argv[]) {
    
    std::vector<Number> num;
    num.push_back(Number(ENumberType::Home, "+48 738-382-94"));
    num.push_back(Number(ENumberType::Mobile, "+48 588-382-13"));
    
    std::vector<ERelativeType> rel;
    rel.push_back(ERelativeType::Friend);
    rel.push_back(ERelativeType::Work);
    
    Contact_v1 contact1("Luke", "Skywalker", num, rel);
    Contact_v1 contact2("Obi", "Wan-Kenobi", num, rel);
    Contact_v1 contact3("Yoda", "Wan-Kenobi", num, rel);

    
    {
        std::map<std::string, Contact_v1> contact_book;
        contact_book << contact1;
        contact_book << contact2;
        contact_book << contact3;
        ofstream file("example.txt", ios::out | ios::binary);
        OutputSerializer out(file);
        out << contact_book;
        file.close();
    }
    {
        ifstream file_read("example.txt", ios::out | ios::binary);
        
        InputSerializer input_serializer(file_read);
        std::map<std::string, Contact_v1> contact_book;
        input_serializer >> contact_book;
        
        for (auto it : contact_book)  std::cout <<"Contact:"<< it.first << it.second << "\n+ - - - - - - - - - - - -+\n";
        file_read.close();
    }
    

    return 0;
}
