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
#ifndef _ERROR_H_
#define _ERROR_H_

#include "ELF3D/Utilities/String.hpp"
#include "ELF3D/Utilities/Singleton.hpp"

namespace elf
{
    enum OutputTypes
    {
        IOSTREAM,
        FILE
    };

    /**
    * Error class singleton handles errors. The errors are being stored in a file, default error.log.
    */
    class Error : public Singleton<Error>
    {
    public:
        Error();

        void SetOutput(OutputTypes type, ...);
        void Occur(const char *format, ...);
    private:
        OutputTypes m_type;///< Type of output.
        String m_fileName;///< If the ouput type is file, this would be the name of the file.
    };
    
    #define error Error::GetInstance()
}

#endif