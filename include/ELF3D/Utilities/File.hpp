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
#ifndef _FILE_H_
#define _FILE_H_

#include "ELF3D/Utilities/String.hpp"

namespace elf
{
    enum FILE_POS {BEGIN, CURRENT, END};

    /**
    * The file class is used to read and write to a file.
    */
    class File
    {
    public:
        /**
        * Constructor
        */
        File();

        /**
        * Loads a File.
        * @param fileName Name of file.
        */
        File(const String &fileName);

        /**
        * Destructor
        */
        ~File();

        /**
        * Loads a file.
        * @param fileName Name of file.
        */
        void Load(const String &fileName) throw(int);

        /**
        * Close the file from reading and writing.
        */
        void Close();

        /**
        * Sets the current position in file by 
        */
        void SetPos(FILE_POS &startFrom, uint32 offset) throw(int); 

        /**
        * Read from current position.
        * @param output Where to put read data.
        * @param sizeOfOutput How much to read. The file pointer would move along.
        */
        void Read(void **output, uint32 sizeOfOutput) throw(int);

        /**
        * Write to current position in file.
        * @param input Data to be written.
        * @param sizeOfInput Size of data to be written.
        */
        void Write(void *input, uint32 sizeOfInput) throw(int);

        /**
        * Read text from current position.
        * @param output Where to put read text.
        * @param sizeOfOutput How much to read. NOTE: The file pointer would move along.
        */
        void ReadText(String &output, uint32 sizeOfOutput);

        /**
        * Write text to current position.
        * @param input Text to be written.
        */
        void WriteText(String &input);

        /**
        * @return False if last loading went wrong.
        */
        bool IsLoaded();
    private:
        bool m_bLoaded;///< True if loading went fine.
        uint32 m_posInFile;///< Position in file.
    };
}

#endif