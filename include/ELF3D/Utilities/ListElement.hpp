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
#ifndef _LIST_ELEMENT_H_
#define _LIST_ELEMENT_H_

class List;

namespace elf
{
/**
* The ListElement class template is the object in a List. 
* It should be declared as a base class for the objects that you want to store in a List.
* @see List
*/
template <class type>
class ListElement
{
public:
    ListElement();
    ~ListElement();

    /**
    * Returns parent element of this element from a list.
    * @return A pointer to a ListElement object.
    */
    ListElement *Parent();

    /**
    * Returns next element of this element from a list.
    * @return A pointer to a ListElement object.
    */
    ListElement *Next();

    /**
    * Removes an element from any list it belongs to.
    */
    void Detach();

    /**
    * Returns the list which a element belongs to.
    * @return A pointer to a List object. 
    */
    List *GetList();
};
}
#endif
