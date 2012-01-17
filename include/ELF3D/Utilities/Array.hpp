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
    void PushBack(const type &a);

    /**
     * Changes the pre-allocated size.
     * @param size Number of objects.
     */
    void Resize(uint32 size);

    /**
     * Insert an Element into the array.
     * @param a Data to insert.
     */
    bool Insert(const type &a, uint32 location);

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
   
    type *Start();

    /**
    * @return Pointer to data at the end of the array.
    
    type *End();
    */

    type &operator [](const uint32 id);

private:
    uint32 m_Size; ///< Current Size of the array.
    type *m_Array; ///< Pointer to the array in memory.
};


template <class type>
Array<type>::Array()
{
    m_Size = 0;
    m_Array = 0;
}

template <class type>
Array<type>::Array(uint32 size)
{
    m_Size = size;
    m_Array = new type[size];
}

template <class type>
Array<type>::~Array()

    SAFE_DELETE_ARRAY(m_Array);
}

template <class type>
void Array<type>::PushBack(const type &a)
{
    type *temp = new type[m_Size + 1];
    for(int i = 0; i < m_Size; i++)
    {
        temp[i] = m_Array[i];
    }
    temp[m_Size] = a;

    SAFE_DELETE_ARRAY(m_Array);

    m_Array = temp;
    m_Size++;
}

template <class type>
void Array<type>::Resize(uint32 size)
{
    m_Size = size;
    type *temp = new type[m_Size];
    for(int i = 0; i < size; i++)
    {
        temp[i] = m_Array[i];
    }

    SAFE_DELETE_ARRAY(m_Array);

    m_Array = temp;
}

template <class type>
bool Array<type>::Insert(const type &a, uint32 location)
{
    if(location >= m_Size)
    {
        error.Occur("Array: Could not insert element into array, because specified location is larger than array.");
        return false;
    }
    
    m_Size++;
    type *temp = new type[m_Size];

    int i = 0;
    //Copy first half and add in value.
    for(;i < location;i++)
    {
        temp[i] = m_Array[i];
    }

    temp[location] = a;

    for(;i < m_Size - 1;i++)
    {
        temp[i + 1] = m_Array[i];
    }

    SAFE_DELETE_ARRAY(m_Array);
    m_Array = temp;

    return true;
}

template <class type>
type &Array<type>::operator [](const uint32 id)
{
    if(id >= m_Size)
    {
        error.Occur("Array: Error can't return requested element. Array doesn't contain that element!");
    }
    return m_Array[id];
}
/*
template <class type>
type *Array<type>::Start()
{
    return &m_Array[0];
}

template <class type>
type *Array<type>::End()
{
    return &m_Array[m_Size - 1];
}
*/
} //end of namespace

#endif
