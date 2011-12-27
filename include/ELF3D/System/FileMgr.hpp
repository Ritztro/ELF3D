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
#ifndef ELF_FILE_MGR_H_
#define ELF_FILE_MGR_H_

#include <ELF3D/Utilities/File.hpp>
#include <ELF3D/Utilities/Singleton.hpp>
#include <ELF3D/Utilities/Array.hpp>

namespace elf
{
    /**
    * The FileMgr singleton class is a manager for files. 
    * You can access every OPEN file from here, by file ID or name.
    */
    class FileMgr : public Singleton<FileMgr>
    {
    public:
        FileMgr();
        ~FileMgr();

        /**
        * Adds a file to the FileMgr, this is default done automatically by File.
        * @param file Pointer to file.
        */
        void AddFile(File *file);

        /**
        * Remove file from container.
        * @param file Pointer to file, to be removed.
        */
        void RemoveFile(File *file);
        
        /**
        * @param fileName Is the name of file to be returned.
        * @return Pointer to a File class.
        */
        File *GetFile(String &fileName);

        /**
        * @param fileID Is the index into the container of File pointers.
        * @return Pointer to a File class.
        */
        File *GetFile(uin32 fileID);
    private:
        Array<File*> m_files;
    };

    #define fileMgr FileMgr::GetInstance()
}

#endif