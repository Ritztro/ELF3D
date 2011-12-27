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

    void FileMgr::RemoveFile(File *file)
    {
        m_files.Remove(file);
    }

    File *FileMgr::GetFile(uint32 fileID)
    {
        return m_files[fileID];
    }

    File *FileMgr::GetFile(String &fileName)
    {
        for(File **iter = m_files.Start(); iter != m_files.End();iter++)
        {
            if((*iter)->GetName() == fileName)
            {
                return (*iter);
            }
        }

        return 0;
    }
}