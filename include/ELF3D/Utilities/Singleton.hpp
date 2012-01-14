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
#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#include <ELF3D/System/Prerequisites.hpp>

namespace elf
{
    /**
    * Singleton class template is used to convert classes to a class singleton.
    * It is used like, class Foo : Singleton<Foo>
    * This class is based on Scott Bilas class, found here: http://scottbilas.com/publications/gem-singleton/
    */
    template<class type>
    class Singleton
    {
    public:
        Singleton()
        {
            assert(!m_instance);
            m_instance = static_cast<type*>(this);
        }

        ~Singleton()
        {
            assert(m_instance);
            m_instance = 0;
        }

        static type &GetInstance()
        {
            assert(m_instance);
            return *m_instance;
        }

        static type *GetPtrInstance()
        {
            return m_instance;
        }
    protected:
        static type *m_instance;
    private:
        //Make it is impossible to copy this class.
        Singleton(Singleton<type> &);
        Singleton &operator=(const Singleton<type> &);
    };

    template <class type>
    type *Singleton<type>::m_instance = 0;
}

#endif
