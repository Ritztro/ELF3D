#include <ELF3D/System/FileMgr.hpp>

namespace elf
{
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
}
