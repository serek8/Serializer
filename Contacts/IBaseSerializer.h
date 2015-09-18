//
//  OutputBaseSerializer.h
//  Contacts
//
//  Created by Jan Seredynski on 15/09/15.
//  Copyright (c) 2015 Jan Seredynski. All rights reserved.
//

#ifndef __Contacts__OutputBaseSerializer__
#define __Contacts__OutputBaseSerializer__


#include <iostream>
#include <string>


class OutputSerializer;
class InputSerializer;

class IBaseSerializer
{
public:
    virtual ~IBaseSerializer();

    
    virtual void write_to_stream(OutputSerializer &output_serializer) const = 0;
    virtual void read_from_stream(InputSerializer &serializer) = 0;
};






#endif /* defined(__Contacts__OutputBaseSerializer__) */




