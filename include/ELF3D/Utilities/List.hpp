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
#ifndef _LIST_H_
#define _LIST_H_

#include "ELF3D/Utilities/ListElement.hpp"

namespace elf 
{
    /**
    * The List class template is a container used to store doubly linked list of elements. 
    * The class type of the element that are to be stored in the List, must be a subclass of ListElement using the same template parameter.
    * @see ListElement
    */
    template <class type>
    class List
    {
    public:
        List();
        ~List();

        /**
        * Inserts a element after another element.
        * @param element A pointer to the element to insert.
        * @param elementAfter A pointer to the element to insert after.
        */
        void InsertAfter(ListElement<type> *element, ListElement<type> *elementAfter);
        
        /**
        * Inserts a element before antother element.
        * @param element A pointer to the element to insert.
        * @param elementAfter A pointer to the element to insert before.
        */
        void InsertBefore(ListElement<type> *element, ListElement<type> *elementBefore);

        /**
        * Adds a element to the end of a list.
        * @param element A pointer to the element to add.
        */
        void Append(ListElement<type> *element);   
        
        /**
        * Adds a element to the beginning of a list.
        * @param element A pointer to the element to add.
        */
        void Prepend(ListElement<type> *element);

        /**
        * Removes a element from a list.
        * @param A pointer to the element to be removed, from the list.
        */
        void Remove(ListElement<type> *element);

        /**
        * Removes all elements from a list, but does not delete them.
        */
        void RemoveAll();

        /**
        * Deletes all the elements in a list.
        */
        void DeleteAll();
    };
}
#endif
