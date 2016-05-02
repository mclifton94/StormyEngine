//
//  window.hpp
//  Stormy
//
//  Created by MarkClifton on 5/2/16.
//  Copyright © 2016 MarkClifton. All rights reserved.
//

#pragma once 

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace stormy { namespace graphics {
  
    class window {
    public:
        window(int Width, int Height, char* Title, bool Vsync);
        ~window();
        
        inline GLFWwindow* get() const { return m_pWindow; }
        inline bool shouldClose() const { return glfwWindowShouldClose(m_pWindow); }
        inline void setActive() const { glfwMakeContextCurrent(m_pWindow); }

        void setTitle(char* Title);
        
        inline void swap(){ glfwSwapBuffers(m_pWindow); }
        inline void clear(){ glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); }
    protected:
    private:
        float m_width, m_height;
        bool m_vsync;
        char* m_title;
        GLuint m_vao;
        
        GLFWwindow* m_pWindow;
        
        virtual void setContext();
        virtual void setProperties();
    };
    
}}
