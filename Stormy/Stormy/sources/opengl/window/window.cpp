//
//  window.cpp
//  Stormy
//
//  Created by MarkClifton on 5/2/16.
//  Copyright © 2016 MarkClifton. All rights reserved.
//

#include "window.hpp"

#include <iostream>

namespace stormy { namespace graphics {
    
    //--------------------------------------------------------------------------------
    window::window(int Width, int Height, char* Title, bool Vsync)
    : m_width(Width), m_height(Height), m_title(Title), m_vsync(Vsync)
    {
        if(!glfwInit()){
            std::cerr << "Failed to init GLFW!\n";
            exit(EXIT_FAILURE);
        }else{
            setContext();
            
            m_pWindow = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
            glfwMakeContextCurrent(m_pWindow);
            
            glewExperimental = true;
            if (glewInit() != GLEW_OK) {
                std::cerr << "failed to initialize GLEW\n";
                exit(EXIT_FAILURE);
            }
            
            glfwSwapInterval( m_vsync ? 1 : 0 );
            setProperties();
            
            glGenVertexArrays(1, &m_vao);
            glBindVertexArray(m_vao);
        }
    }
    
    //--------------------------------------------------------------------------------
    window::~window(){
        glDeleteVertexArrays(1, &m_vao);
        glfwMakeContextCurrent(NULL);
        glfwDestroyWindow(m_pWindow);
        glfwTerminate();
    }
    
    //--------------------------------------------------------------------------------
    void window::setTitle(char* Title){
        m_title = Title;
        glfwSetWindowTitle(m_pWindow, m_title);
    }
    
    //--------------------------------------------------------------------------------
    void window::setContext(){
        glfwWindowHint(GLFW_SAMPLES, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    }
    
    //--------------------------------------------------------------------------------
    void window::setProperties(){
        glEnable(GL_DEPTH_TEST);
        glEnable (GL_BLEND);
        glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }
}}