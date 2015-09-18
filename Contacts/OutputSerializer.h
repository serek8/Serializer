//
//  OutputSerializer.h
//  Contacts
//
//  Created by Jan Seredynski on 15/09/15.
//  Copyright (c) 2015 Jan Seredynski. All rights reserved.
//

#ifndef __Contacts__OutputSerializer__
#define __Contacts__OutputSerializer__



#include <iostream>
#include <type_traits>
#include <vector>
#include <map>
#include "IBaseSerializer.h"





class OutputSerializer
{
    template<bool> struct _TPODAdapter {};
    template<bool> struct _TSerializable {};
    template<bool> struct _TArrayAdapter {};
    template<bool> struct _TMapAdapter {};

public:

    OutputSerializer(std::ostream &stream);
    
    template <typename T>
    std::ostream& operator << (const T& value)
    {
        save_object(value, _TPODAdapter<std::is_pod<T>::value>());
        return stream_;
    }
    
    
    template<typename T> void save_object(const T& value, _TPODAdapter<true>)
    {
        stream_.write((char*)&value, sizeof(value));
    }
    template<typename T> void save_object(const T& value, _TPODAdapter<false>)
    {
        save_object(value, _TSerializable<std::is_base_of<IBaseSerializer, T>::value>());
    }
    template<typename T> void save_object(const T& value, _TSerializable<true>)
    {
        value.write_to_stream(*this);
    }
    template<typename T> void save_object(const T& value, _TSerializable<false>)
    {
        save_object(value, _TArrayAdapter<std::is_same<std::string, T>::value ||
                                          std::is_same<std::vector<typename T::value_type>, T>::value>());
    }
    template<typename T> void save_object(const T& value, _TArrayAdapter<true>)
    {
        typename T::size_type size = value.size();
        *this << size;
        for(auto single_value : value) *this << single_value;
    }
    template<typename T> void save_object(const T& value, _TArrayAdapter<false>)
    {
        save_object(value, _TMapAdapter<std::is_same<std::map<typename T::key_type, typename T::mapped_type>, T>::value>());
    }
    template<typename T> void save_object(const T& value, _TMapAdapter<true>)
    {
        typename T::size_type size = value.size();
        *this << size;
        for (auto it=value.begin(); it!=value.end(); ++it)
        {
            //std::cout << it->first << " => " << it->second << '\n';
            *this << (it->first);
            *this << (it->second);
        }
        
    }
    template<typename T> void save_object(const T& value, _TMapAdapter<false>)
    {
       std::cerr<<"Not Supported object";
    }



    std::ostream &stream_;
    
};



#endif /* defined(__Contacts__OutputSerializer__) */
