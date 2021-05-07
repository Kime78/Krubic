#include <stdio.h>
#include "glad.h"
#include <GLFW/glfw3.h>
#include <stdbool.h>
#include <stdlib.h>

static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main(int argc, char **args)
{
    glfwInit();
    GLFWwindow *window = glfwCreateWindow(640, 480, "Krubic", NULL, NULL);

    printf("Hello pain");
    glfwSetKeyCallback(window, key_callback);

    glfwMakeContextCurrent(window);
    gladLoadGL();
    glfwSwapInterval(1);
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);

    glfwTerminate();
    exit(0);
}