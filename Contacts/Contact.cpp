//
//  Contact.cpp
//  Contacts
//
//  Created by Jan Seredynski on 14/09/15.
//  Copyright (c) 2015 Jan Seredynski. All rights reserved.
//

#include "Contact.h"
#include "OutputSerializer.h"
#include "InputSerializer.h"

Contact::Contact(unsigned int version)
:version_(version)
{}

void Contact::write_to_stream(OutputSerializer &serializer) const
{
    serializer << version_;
}

void Contact::read_from_stream(InputSerializer &serializer)
{
    unsigned int session_version;
    serializer >> session_version;
    if(session_version != version_)
        std::cerr<<"\nIncopampatible version !! Parser ver."<<version_<<" <> input ver."<<session_version;
    else std::cout<<"\nVersion: "<<version_<<std::endl;
}