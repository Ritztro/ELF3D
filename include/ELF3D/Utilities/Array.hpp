/*
   This file is part of ELF3D

   Copyright (c) 2011 Ritztro

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
   THE SOFTWARE.
   -----------------------------------------------------------------------------
 */
#ifndef ELF_ARRAY_HPP_
#define ELF_ARRAY_HPP_

#include <ELF3D/Utilities/Error.hpp>
#include <ELF3D/System/Prerequisites.hpp>

namespace elf
{

/**
 * The Array class is a dynamic data storage container.
 * You can add and remove data from Array without having
 * to worry about size limitations.
 */
template <class type>
class Array
{
public:
    /**
     * Constructor
     */
    Array();

    /**
     * Destructor
     */
    ~Array();

    /**
     * Contructor that pre-allocates memory
     * @param size Number of Objects
     */
    Array(uint32 size);

    /**
     * Push new data to end of array.
     * @param a Data to push back.
     */
    void PushBack(type a);

    /**
     * Changes the pre-allocated size.
     * @param size Number of objects.
     */
    void Resize(uint32 size);

    /**
     * Insert an Element into the array.
     * @param a Data to insert.
     */
    void Insert(type a, uint32 location);

    /**
     * Remove an Element from the array.
     * @param id ID of element in array.
     */
    void Remove(uint32 location);

    /**
     * Empties the array of all elements
     */
    void Empty();

    /**
    * @return Pointer to data at start of array.
    */
    type *Start();

    /**
    * @return Pointer to data at the end of the array.
    */
    type *End();


    type &operator [](const int id);

private:
    uint32 m_Size; ///< Current Size of the array.
    uint32 m_Pos; ///< Current position to push to.
    type *m_Array; ///< Pointer to the array in memory.
};


template <class type>
Array<type>::Array()
{
    m_Size = 1;
    m_Pos = 0;
    m_Array = new type[1];
}

template <class type>
Array<type>::Array(uint32 size)
{
    m_Size = size;
    m_Pos = 0;
    m_Array = new type[size+1];
}

template <class type>
Array<type>::~Array()
{
    m_Size = 0;
    m_Pos = 0;
    SAFE_DELETE_ARRAY(m_Array);
}

template <class type>
void Array<type>::PushBack(type a)
{
    type *temp = new type[m_Size+1];
    for(int i = 0; i < m_Size; i++)
    {
        temp[i] = m_Array[i];
    }
    temp[m_Pos] = a;
    m_Pos++;

    SAFE_DELETE_ARRAY(m_Array);

    m_Array = new type[m_Size+1];
    for(int i = 0; i < m_Size; i++)
    {
        m_Array[i] = temp[i];
    }

    SAFE_DELETE_ARRAY(temp);
}

template <class type>
void Array<type>::Resize(uint32 size)
{
    type *temp = new type[size];
    for(int i = 0; i < size; i++)
    {
        temp[i] = m_Array[i];
    }


    SAFE_DELETE_ARRAY(m_Array);

    m_Array = new type[size];
    for(int i = 0; i < size; i++)
    {
        m_Array[i] = temp[i];
    }

    SAFE_DELETE_ARRAY(temp);
}

template <class type>
void Array<type>::Insert(type a, uint32 location)
{
    type *half1 = new type[location+1];
    type *half2 = new type[m_Size-location];

    //Copy first half and add in value.
    for(int i = 0; i < location; i++)
    {
        half1[i] = m_Array[i];
    }
    half1[location] = a;

    //Copy second half
    for(int i = m_Size-(location+1); i < m_Size; i++)
    {
        half2[i-location] = m_Array[i];
    }

    SAFE_DELETE_ARRAY(m_Array);

    m_Array = new type[m_Size+1];

    //Copy both halfs and new value back in.
    for(int i = 0; i < location+1; i++)
    {
        m_Array[i] = half1[i];
    }

    for(int i = m_Size-location; i < m_Size+1; i++)
    {
        half2[i-(location+1)] = m_Array[i];
    }


    SAFE_DELETE_ARRAY(half1);
    SAFE_DELETE_ARRAY(half2);
}

template <class type>
type &Array<type>::operator [](const int id)
{
    return m_Array[id];
}

template <class type>
type *Array<type>::Start()
{
    type *data;
    data = &m_Array[0];
    return data;
}

template <class type>
type *Array<type>::End()
{
    type *data;
    data = &m_Array[m_Pos-1];
    return data;
}

} //end of namespace

#endif
