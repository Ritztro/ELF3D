#include "ELF3D/Utilities/File.hpp"
#include <fstream>
#include <iostream>

namespace elf
{
    File::File()
    {
        m_bLoaded = false;
        m_posInFile = 0;
    }
    
    File::File(const String &fileName)
    {
        File();
        Load(fileName);
    }

    File::~File()
    {
        Close();
    }

    void File::Load(const String &fileName)
    {
        std::fstream file;
        try
        {
            file.open(fileName.GetStr(), fstream::in | fstream::out);
        }
        catch 
    }

    void File::Close()
    {
    }
}