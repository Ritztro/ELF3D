#include "ELF3D/Utilities/File.hpp"
#include <iostream>

namespace elf
{
    File::File()
    {
        m_bLoaded = false;
        m_sizeOfFile = 0;
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

    bool File::Load(const String &fileName)
    {
        try
        {
            m_bLoaded = true;
            m_fileName = fileName;
            m_file.open(m_fileName.ConstStr(), std::fstream::in | std::fstream::out | std::fstream::binary);
            
            m_file.seekg(0, std::ios::end);
            m_sizeOfFile = m_file.tellg();
            m_file.seekg(0, std::ios::beg);
        }
        catch(std::ifstream::failure e)
        {
            error.Occur("File: Exception %s, while opening %s.", e.what(), m_fileName.ConstStr());
            m_bLoaded = false;
        }

        return m_bLoaded;
    }

    void File::Close()
    {
        m_file.close();
    }

    bool File::SetPos(FILE_POS &startFrom, uint32 offset)
    {
        try
        {
            switch(startFrom)
            {
            case BEG:
                m_file.seekg(offset, std::ios::beg);
                break;
            case CUR:
                m_file.seekg(offset, std::ios::cur);
                break;
            case END:
                m_file.seekg(offset, std::ios::end);
                break;
            default:
                error.Occur("File: Invalid FILE_POS parameter, for SetPos.");
                break;
            }
        }
        catch(std::ifstream::failure e)
        {
            error.Occur("File: Exception %s, while setting get pos.");
            return false;
        }

        return true;
    }

    bool File::Read(void *output, uint32 sizeOfOutput)
    {
        try
        {
            m_file.read((char*)output, sizeOfOutput);
        }
        catch(std::ifstream::failure e)
        {
            error.Occur("File: Exception %s, while reading from %s.", e.what(), m_fileName.ConstStr());
            return false;
        }

        return true;
    }

    bool File::Write(void *input, uint32 sizeOfInput)
    {
        try
        {
            m_file.write((char*)input, sizeOfInput);
        }
        catch(std::ifstream::failure e)
        {
            error.Occur("File: Exception %s, while writing to %s.", e.what(), m_fileName.ConstStr());
            return false;
        }

        return true;
    }

    bool File::ReadLine(String &output)
    {
        try
        {   
            uint32 sizeOfBuffer = m_sizeOfFile - m_file.tellg();
            
            //Create a big enough buffer.
            char *buffer = new char[sizeOfBuffer];
            m_file.getline(buffer, sizeOfBuffer);
            output.Append(buffer);
        }
        catch(std::ifstream::failure e)
        {
            error.Occur("File: Exception %s, while reading line from %s.", e.what(), m_fileName.ConstStr());
            return false;
        }

        return true;
    }

    bool File::WriteText(String &input)
    {
        try
        {
            m_file.write(input.ConstStr(), input.Size());
        }
        catch(std::ifstream::failure e)
        {
            error.Occur("File: Exception %s, while writing text to %s.", e.what(), m_fileName.ConstStr());
            return false;
        }

        return true;
    }

    bool File::IsLoaded()
    {
        return m_bLoaded;
    }
}