#include <cassert>
#include <iostream>
#include <GLFW/glfw3.h>

#include "event.hpp"

namespace input
{

Window* EventQueue::window_ = nullptr;
std::queue<Event> EventQueue::queue_{};

void EventQueue::ScrollCallback(GLFWwindow* window, double dx, double dy)
{
    std::cout << '[' << dx << ';' << dy << ']' << '\n';
}

void EventQueue::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
    std::cout << "button = " << button << '\n';
    std::cout << "action = " << action << '\n';
    std::cout << "mods   = " << mods << '\n';
}

void EventQueue::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    std::cout << "key      = " << char(key) << '\n';
    std::cout << "scancode = " << scancode << '\n';
    std::cout << "action   = " << action << '\n';
    std::cout << "mods     = " << mods << '\n';
}

void EventQueue::MouseMoveCallback(GLFWwindow* window, double xpos, double ypos)
{
    std::cout << '[' << xpos << ';' << ypos << ']' << '\n';
}

void EventQueue::CloseCallback(GLFWwindow* window)
{
    std::cout << "Closing!1!1!1!1!1\n";
}

void EventQueue::SetWindow(Window* window)
{
    assert(window);

    window_ = window;
    GLFWwindow* native_window = window_->GetNativeWindow();

    glfwSetKeyCallback(native_window, KeyCallback);
    glfwSetWindowCloseCallback(native_window, CloseCallback);
    glfwSetCursorPosCallback(native_window, MouseMoveCallback);
    glfwSetMouseButtonCallback(native_window, MouseButtonCallback);
    glfwSetScrollCallback(native_window, ScrollCallback);
}

void EventQueue::PostEvent(const Event& event)
{
    queue_.push(event);
}

bool EventQueue::PollEvent(Event* event)
{
    glfwPollEvents();

    if (!queue_.empty())
    {
        *event = queue_.front();
        queue_.pop();

        return true;
    }

    return false;
}

bool PollEvent(Event* event)
{
    return EventQueue::PollEvent(event);
}

} // namespace input
