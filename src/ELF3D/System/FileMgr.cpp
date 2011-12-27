#include <ELF3D/System/FileMgr.hpp>

namespace elf
{
    FileMgr::FileMgr()
    {
    }

    FileMgr::~FileMgr()
    {
    }

    FileMgr::AddFile(File *file)
    {
        m_files.PushBack(file);
    }
}