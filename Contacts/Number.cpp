//
//  Number.cpp
//  Contacts
//
//  Created by Jan Seredynski on 14/09/15.
//  Copyright (c) 2015 Jan Seredynski. All rights reserved.
//

#include "Number.h"

#include "OutputSerializer.h"
#include "InputSerializer.h"


const char * ENumberNames[] ={"Home", "Mobile", "Other"};

Number::Number()
{}


Number::Number(ENumberType type, std::string number)
:type_(type)
,content_(number)
{
    
}


void Number::write_to_stream(OutputSerializer &serializer) const
{

    serializer << type_;
    serializer << content_;
    
}

void Number::read_from_stream(InputSerializer &serializer)
{
    serializer >> type_;
    serializer >> content_;
}