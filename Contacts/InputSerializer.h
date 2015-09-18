//
//  InputSerializer.h
//  Contacts
//
//  Created by Jan Seredynski on 17/09/15.
//  Copyright (c) 2015 Jan Seredynski. All rights reserved.
//

#ifndef __Contacts__InputSerializer__
#define __Contacts__InputSerializer__

#include <string>
#include <vector>
#include <map>
#include <iostream>

#include "IBaseSerializer.h"

class InputSerializer
{
    template<bool> struct _TPODAdapter {};
    template<bool> struct _TSerializable {};
    template<bool> struct _TArrayAdapter {};
    template<bool> struct _TMapAdapter {};
    
public:
    
    InputSerializer(std::istream &stream);
    
    template <typename T>
    std::istream& operator >> (T& value)
    {
        load_object(value, _TPODAdapter<std::is_pod<T>::value>());
        return stream_;
    }
    
    
    template<typename T> void load_object( T& value, _TPODAdapter<true>)
    {
        stream_.read((char*)&value, sizeof(T));
    }
    template<typename T> void load_object( T& value, _TPODAdapter<false>)
    {
        load_object(value, _TSerializable<std::is_base_of<IBaseSerializer, T>::value>());
    }
    template<typename T> void load_object( T& value, _TSerializable<true>)
    {
        value.read_from_stream(*this);
    }
    template<typename T> void load_object( T& value, _TSerializable<false>)
    {
        load_object(value, _TArrayAdapter<std::is_same<std::string, T>::value ||
                    std::is_same<std::vector<typename T::value_type>, T>::value>());
    }
    template<typename T> void load_object( T& value, _TArrayAdapter<true>)
    {
        typename T::size_type size;
        *this >> size;
        value.resize(size);
        for(auto& v : value) *this>> v;
    }
    template<typename T> void load_object( T& value, _TArrayAdapter<false>)
    {
        load_object(value, _TMapAdapter<std::is_same<std::map<typename T::key_type, typename T::mapped_type>, T>::value>());
    }
    template<typename T> void load_object( T& value, _TMapAdapter<true>)
    {
        typename T::size_type size = value.size();
        *this >> size;
        for(int i=0; i<size; i++)
        {
            typename T::key_type key;
            typename T::mapped_type map_value;
            *this >> key;
            *this >> map_value;
            value[key] = map_value;
        }
    }
    template<typename T> void load_object(const T& value, _TMapAdapter<false>)
    {
        std::cerr<<"Not Supported object";
    }
    
    std::istream &stream_;
    
};





#endif /* defined(__Contacts__InputSerializer__) */
