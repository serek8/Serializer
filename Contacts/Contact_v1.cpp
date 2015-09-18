//
//  Contact_v1.cpp
//  Contacts
//
//  Created by Jan Seredynski on 14/09/15.
//  Copyright (c) 2015 Jan Seredynski. All rights reserved.
//

#include "Contact_v1.h"
#include "OutputSerializer.h"
#include "InputSerializer.h"

const char * ERelativeNames[] ={"Parent", "Sibling", "Child", "Friend", "Work"};

Contact_v1::Contact_v1()
:Contact(CONTACT_V1_VER)
{
    
}


Contact_v1::Contact_v1 (string name, string surname, vector<Number> &numbers, vector<ERelativeType> &relatives)
:Contact(CONTACT_V1_VER)
,name_(name)
,surname_(surname)
,numbers_(numbers)
,relatives_(relatives)
{
    
}

Contact_v1::Contact_v1(const Contact_v1 &obj)
:Contact(CONTACT_V1_VER)
,name_(obj.name_)
,surname_(obj.surname_)
,numbers_(obj.numbers_)
,relatives_(obj.relatives_)
{

}

void Contact_v1::write_to_stream(OutputSerializer &serializer) const
{
    Contact::write_to_stream(serializer);

    serializer << name_;
    serializer << surname_;
    serializer << numbers_;
    serializer << relatives_;
    
}

void Contact_v1::read_from_stream(InputSerializer &serializer)
{
    Contact_v1 contact;
    Contact::read_from_stream(serializer);
    serializer >> name_;
    serializer >> surname_;
    serializer >> numbers_;
    serializer >> relatives_;
}

void Contact_v1::print(std::ostream &stream)
{
    stream<<"\nName: "<< name_ <<"\nSurname: ";
    stream<< surname_<<"\nNumbers:";
    for(auto i:numbers_) {std::cout <<"\n\t"; i.print();}
    stream<<"\nRelation:";
    for(auto i:relatives_) std::cout <<"\n\t"<< ERelativeNames[(int)i];
}

std::ostream& operator << (std::ostream &stream,  Contact_v1 &contact)
{
    contact.print(stream);
    return stream;
}


void operator << (std::map<std::string, Contact_v1> &map, Contact_v1 &contact)
{
    map[contact.name_+contact.surname_] = contact;
    
}




