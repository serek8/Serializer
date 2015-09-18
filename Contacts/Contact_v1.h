//
//  Contact_v1.h
//  Contacts
//
//  Created by Jan Seredynski on 14/09/15.
//  Copyright (c) 2015 Jan Seredynski. All rights reserved.
//

#ifndef __Contacts__Contact_v1__
#define __Contacts__Contact_v1__

#include <vector>
#include <map>

#include "Contact.h"
#include "IBaseSerializer.h"
#include "OutputSerializer.h"
#include "Number.h"





enum class ERelativeType : int { Parent=0, Sibling, Child, Friend, Work };
extern const char * ERelativeNames[];

#define CONTACT_V1_VER 1


class Contact_v1: public Contact
{
    
    
    
public:

    Contact_v1();

    Contact_v1 (string name, string surname, vector<Number> &numbers, vector<ERelativeType> &relatives);
    Contact_v1 &operator=( Contact_v1 &obj)
    {
        name_ = obj.name_;
        surname_ = obj.surname_;
        numbers_ = obj.numbers_;
        return *this;
    }
    
    Contact_v1(const Contact_v1& obj);
    
    
    
    virtual void write_to_stream(OutputSerializer &serializer) const;
    virtual void read_from_stream(InputSerializer &serializer);
    
    string name_;
    string surname_;
    vector<Number> numbers_;
    vector<ERelativeType> relatives_;
    
    void print(std::ostream &stream);
};

    std::ostream& operator << (std::ostream &stream,  Contact_v1 &contact);
    void operator << (std::map<std::string, Contact_v1> &map, Contact_v1 &contact);


#endif /* defined(__Contacts__Contact_v1__) */
