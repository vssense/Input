#include <iostream>
#include <GLFW/glfw3.h>

void ScrollCallback(GLFWwindow* window, double dx, double dy)
{
    // Do not know why here is dx. It is always zero
    // Upd: Found it being no zero with touchpad 
    std::cout << '[' << dx << ';' << dy << ']' << '\n';
}


void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
    std::cout << "button = " << button << '\n';
    std::cout << "action = " << action << '\n';
    std::cout << "mods   = " << mods << '\n';
}

void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    std::cout << "key      = " << char(key) << '\n';
    std::cout << "scancode = " << scancode << '\n';
    std::cout << "action   = " << action << '\n';
    std::cout << "mods     = " << mods << '\n';
}

void CursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
{
    std::cout << '[' << xpos << ';' << ypos << ']' << '\n';
}


void CloseCallback(GLFWwindow* window)
{
    std::cout << "Closing1111111111111111111111111\n";
}

int main(void)
{
    GLFWwindow* window = nullptr;

    /* Initialize the library */
    if (!glfwInit())
    {
        return -1;
    }


    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwSetKeyCallback(window, KeyCallback);
    glfwSetWindowCloseCallback(window, CloseCallback);
    glfwSetCursorPosCallback(window, CursorPositionCallback);
    glfwSetMouseButtonCallback(window, MouseButtonCallback);
    glfwSetScrollCallback(window, ScrollCallback);

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
