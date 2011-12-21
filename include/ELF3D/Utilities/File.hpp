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
#ifndef ELF_FILE_H_
#define ELF_FILE_H_

#include <ELF3D/System/Prerequisites.hpp>
#include <ELF3D/Utilities/String.hpp>

namespace elf
{
    enum FilePos {BEG, CUR, END};

    /**
    * The file class is used to read and write data or text to a file.
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
        * @return False if error. Check Error singleton for more information.
        */
        bool Load(const String &fileName);

        /**
        * Close the file from reading and writing.
        */
        void Close();

        /**
        * Sets the current position in file.
        * @param startFrom Where to start from.
        * @param offset How much to move.
        * @return False if error. Check Error singleton for more information.
        */
        bool SetPos(FilePos startFrom, uint32 offset);

        /**
        * Read from current position.
        * @param output Where to put read data.
        * @param sizeOfOutput How much to read. The file pointer would move along.
        * @return False if error. Check Error singleton for more information.
        */
        bool Read(void *output, uint32 sizeOfOutput);

        /**
        * Write to current position in file.
        * @param input Data to be written.
        * @param sizeOfInput Size of data to be written.
        * @return False if error. Check Error singleton for more information.
        */
        bool Write(void *input, uint32 sizeOfInput);

        /**
        * Read line from current position, until end of file or new line occurs.
        * @param output Where to put read line.
        * @return False if error. Check Error singleton for more information.
        */
        bool ReadLine(String &output);

        /**
        * Write a line to current position.
        * @param input Text to be written.
        * @return False if error. Check Error singleton for more information.
        */
        bool WriteLine(String &input);

        /**
        * @return False if loading went wrong.
        */
        bool IsLoaded();
    private:
        bool m_bLoaded;///< True if loading went fine.
        uint32 m_sizeOfFile;///< Size of file.
        std::fstream m_file;///< File handler.
        String m_fileName;///< Name of file.
    };
}

#endif
