//
//  Contact.h
//  Contacts
//
//  Created by Jan Seredynski on 14/09/15.
//  Copyright (c) 2015 Jan Seredynski. All rights reserved.
//

#ifndef __Contacts__Contact__
#define __Contacts__Contact__

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "IBaseSerializer.h"





using namespace std;



class Contact : public IBaseSerializer
{
protected:
    Contact(unsigned int version);

    virtual void write_to_stream(OutputSerializer &serializer) const;
    virtual void read_from_stream(InputSerializer &serializer);
    
    const unsigned int version_;
    
};




#endif /* defined(__Contacts__Contact__) */
