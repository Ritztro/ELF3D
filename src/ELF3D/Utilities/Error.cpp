#include <ELF3D/Utilities/Error.hpp>
#include <ELF3D/Utilities/File.hpp>

namespace elf
{
    Error errorInstance;

    Error::Error()
    {
        m_type = FILE;
        m_fileName = "error.log";
    }

    void Error::SetOutput(OutputTypes type, ...)
    {
        m_type = type;
        va_list args;
        if(type == FILE)
        {
            va_start(args, type);
            m_fileName = va_arg(args, const char*);
        }

        va_end(args);
    }

    void Error::Occur(const char *format, ...)
    {
        String buffer;
        buffer.SetSize(255);

        va_list args;
        va_start(args, format);

#if COMPILER == COMPILER_MSVC
        vsnprintf_s(buffer.Str(), 256, 255, format, args);
#else
        vsnprintf(buffer.Str(), 256, format, args);
#endif

        //Write to the output specified.
        if(m_type == IOSTREAM)
        {
            std::cout << buffer.Str() << std::endl;
        }
        else if(m_type == FILE)
        {
            File out;
            out.Load(m_fileName);

            out.WriteLine(buffer);

            //NOTE we don't need to close the file
            //because it is done automatically in
            //the destructor.
        }

        va_end(args);
    }
}
