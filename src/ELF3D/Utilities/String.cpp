#include "ELF3D/Utilities/String.hpp"

namespace elf
{
    /**
    * Constructor.
    */
    String::String()
    {
        m_string = 0;
        m_size = 0;
    }
        
    /**
    * Destructor.
    */
    String::~String()
    {
        if(m_string)
        {

        }
    }

    /**
    * Copy constructor.
    */
    String::String(const String &string)
    {
    }
        
    /**
    * Copy constructor.
    */
    String::String(const char *string)
    {
    }

    /**
    * Append one char to the string.
    * @param c Character to be append.
    */
    void String::Append(const char c)
    {
    }

    /**
    * Append a sequence of characters.
    * @param string Character sequence to be append.
    */
    void String::Append(const char *string);

    /**
    * Append a string.
    * @param string String to be append.
    */
    void String::Append(const String &string);

    /**
    * Remove all occurrence of this char from the string.
    * @param c Character to be removed.
    */
    void String::Remove(const char c);

    /**
    * Remove all occurrence of a sequence of characters.
    * @param string Character sequence to be removed.
    */
    void String::Remove(const char *string);

    /**
    * Remove all occurrence of a string.
    * @param string String to be removed.
    */
    void String::Remove(const String &string);

    /**
    * @return Number of characters, in other words size of string.
    */
    uint32 String::Size();

    void String::operator +=(const char c)
    {
    }
    void String::operator +=(const char *string);
    void String::operator +=(const String &string);

    void String::operator =(const char *string);
    void String::operator =(const String &string);
}