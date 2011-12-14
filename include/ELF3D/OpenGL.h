#ifndef _OPENGL_H_
#define _OPENGL_H_

#include <GL/glew.h>

#if defined(_WIN32)

    #include <GL/gl.h>
        #include <GL/glu.h>

#elif defined(__linux__) || defined(__FreeBSD__)

    #include <GL/gl.h>
        #include <GL/glu.h>

#elif defined(__OSX__) || defined (__APPLE__)

    #include <OpenGL/gl.h>
        #include <OpenGL/glu.h>

#endif

#endif

