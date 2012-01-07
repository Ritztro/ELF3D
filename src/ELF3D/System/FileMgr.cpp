#include <ELF3D/System/FileMgr.hpp>

namespace elf
{
    FileMgr inst;

    FileMgr::FileMgr()
    {
    }

    FileMgr::~FileMgr()
    {
    }

    void FileMgr::AddFile(File *file)
    {
        m_files.PushBack(file);
    }

    void FileMgr::RemoveFile(uint32 fileID)
    {
        m_files.Remove(fileID);
    }

    File *FileMgr::GetFile(uint32 fileID)
    {
        return m_files[fileID];
    }

    File *FileMgr::GetFile(String &fileName)
    {
        for(File **iter = m_files.Start(); iter != m_files.End();iter++)
        {
            if((*iter)->GetName() == fileName) //Check if **iter (derefenced pointer's pointer) file name matches
            {
                return (*iter); //Return pointer to file
            }
        }

        return 0;
    }

    uint32 FileMgr::GetFileID(File *file)
    {
        int count = 0;
        for(File **iter = m_files.Start(); iter != m_files.End(); iter++)
        {
            if(*iter == file)
            {
                return count;
            }
            count++;
        }
    }
}
