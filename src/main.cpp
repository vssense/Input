#include <iostream>
#include <GLFW/glfw3.h>

#include "window.hpp"
#include "event.hpp"

using namespace input;

int main()
{
    std::cout << "sizeof Event = " << sizeof(Event) << '\n';

    Window window_{};
    EventManager::SetWindow(&window_);

    GLFWwindow* window = window_.GetNativeWindow();

    Event event{};

    /* Create a windowed mode window and its OpenGL context */

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        while (event.PollEvent())
        {
            std::cout << "Event processing\n";
        }

        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
    }

    return 0;
}
