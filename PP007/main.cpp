//#include <GLFW/glfw3.h>
//#include <stdlib.h>
//#include <stdio.h>
//#include "P.hpp"
//#include "M.hpp"
//
//#pragma comment(lib, "OpenGL32")
//
//static void error_callback(int error, const char* descripition)
//{   
//    fputs(descripition, stderr);
//}
//
//static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
//{
//    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//        glfwSetWindowShouldClose(window, GL_TRUE);
//}
//
//int main(void)
//{
//
//    GLFWwindow* window;
//    if (!glfwInit())
//        exit(EXIT_FAILURE);
//    window = glfwCreateWindow(800, 800, "Simple example", NULL, NULL);
//    if (!window)
//    {
//        glfwTerminate();
//        exit(EXIT_FAILURE);
//    }
//    
//    glfwMakeContextCurrent(window);
//    glfwSetKeyCallback(window, key_callback);
//
//    float ratio;
//    int width, height;
//    glfwGetFramebufferSize(window, &width, &height);
//    ratio = width / (float)height;
//
//    while (!glfwWindowShouldClose(window)) 
//    {
//        Player p;
//        
//
//        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT);
//        
//        glPointSize(10);
//
//        glBegin(GL_POINTS); //주인공
//
//        glColor3f(0.0f, 0.0f, 0.0f);
//        glVertex2f(-0.7f, 0.0f);
//
//        glEnd();
//        //-------------------------------------------------------------------------------------------------------
//        glPointSize(10);
//        glBegin(GL_TRIANGLES); //배경
//
//        glColor3f(0.0f, 0.0f, 1.0f);
//        glVertex2f(0.5f, 1.0f);
//        glColor3f(0.0f, 1.0f, 0.0f);
//        glVertex2f(1.0f, 0.0f);
//        glColor3f(1.0f, 0.0f, 0.0f);
//        glVertex2f(-1.0f, 0.0f);
//
//        glEnd();
//        //-------------------------------------------------------------------------------------------------------
//        glPointSize(10);
//        glBegin(GL_TRIANGLES);  //적
//        glColor3f(0.7f, 1.0f, 0.8f);
//        glVertex2f(0.75f, 0.025f);
//        glVertex2f(0.75f, -0.025f);
//        glVertex2f(0.7f, 0.0f);
//        glEnd();
//        
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//
//        
//    }
//    glfwDestroyWindow(window);
//    glfwTerminate();
//    exit(EXIT_SUCCESS);
//}
