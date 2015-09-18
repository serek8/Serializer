//
//  Number.h
//  Contacts
//
//  Created by Jan Seredynski on 14/09/15.
//  Copyright (c) 2015 Jan Seredynski. All rights reserved.
//

#ifndef __Contacts__Number__
#define __Contacts__Number__


#include <string>
#include <vector>


#include "IBaseSerializer.h"

enum class ENumberType
{ Home, Mobile, Other };
extern const char * ENumberNames[];

class OutputSerializer;
class InputSerializer;

class Number : public IBaseSerializer
{
public:
    
    Number();
    Number(ENumberType type, std::string number);
    
    
    virtual void write_to_stream(OutputSerializer &serializer) const;
    virtual void read_from_stream(InputSerializer &serializer);

    
    ENumberType type_;
    std::string content_; // the number
    
    void print()
    {
        std::cout<<"Type: "<<ENumberNames[(int)type_]<<"\tNumber: "<<content_;
    }
};





#endif /* defined(__Contacts__Number__) */
