#include <iostream>
#include <GLFW/glfw3.h>

#include "window/window.hpp"
#include "event/event.hpp"

using namespace input;

int main()
{
    std::cout << "sizeof Mods = " << sizeof(ButtonMods) << '\n';

    Window window_{};
    EventQueue::SetWindow(&window_);

    GLFWwindow* window = window_.GetNativeWindow();

    Event event{};

    // Why window is closing without event processing

    bool running = true;

    while (running)
    {
        while (PollEvent(&event))
        {
            switch (event.GetType())
            {
            case kQuit:
                running = false;
                break;

            case kMouseButton:
                std::cout << "action = " << event.GetButton().action << '\n';
                break;
                
            case kKey:
                std::cout << "scancode = " << event.GetKey().scancode << '\n';
                break;

            default:
                break;
            }
        }


        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
    }

    return 0;
}
