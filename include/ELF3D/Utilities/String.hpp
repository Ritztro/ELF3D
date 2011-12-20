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
#ifndef _STRING_H_
#define _STRING_H_

#include "ELF3D/System/Prerequisites.hpp"

namespace elf
{
    /**
    * The string class is a character container.
    * The class have functions to manipulate characters.
    */
    class String
    {
    public:
        /**
        * Constructor.
        */
        String();
        
        /**
        * Destructor.
        */
        ~String();

        /**
        * Copy constructor.
        */
        String(const String &string);
        
        /**
        * Copy constructor.
        */
        String(const char *string);

        /**
        * Append one char to the string.
        * @param c Character to be append.
        */
        void Append(const char c);

        /**
        * Append a sequence of characters.
        * @param string Character sequence to be append.
        */
        void Append(const char *string);

        /**
        * Append a string.
        * @param string String to be append.
        */
        void Append(const String &string);

        /**
        * Remove all occurrence of this char from the string.
        * @param c Character to be removed.
        */
        void Remove(const char c);

        /**
        * Remove all occurrence of a sequence of characters.
        * @param string Character sequence to be removed.
        */
        void Remove(const char *string);

        /**
        * Remove all occurrence of a string.
        * @param string String to be removed.
        */
        void Remove(const String &string);

        /**
        * @return Number of characters, in other words size of string.
        */
        uint32 Size();

        void operator +=(const char c);
        void operator +=(const char *string);
        void operator +=(const String &string);

        void operator =(const char *string);
        void operator =(const String &string);
    private:
        int8 *m_string;
        uint32 m_size;
    };
}

#endif