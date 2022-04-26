#include "event.hpp"

#include <iostream>

namespace input
{

Window* EventManager::window_ = nullptr;
std::queue<Event> EventManager::queue_{};

void EventManager::ScrollCallback(GLFWwindow* window, double dx, double dy)
{
    std::cout << '[' << dx << ';' << dy << ']' << '\n';
}

void EventManager::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
    std::cout << "button = " << button << '\n';
    std::cout << "action = " << action << '\n';
    std::cout << "mods   = " << mods << '\n';
}

void EventManager::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    std::cout << "key      = " << char(key) << '\n';
    std::cout << "scancode = " << scancode << '\n';
    std::cout << "action   = " << action << '\n';
    std::cout << "mods     = " << mods << '\n';
}

void EventManager::MouseMoveCallback(GLFWwindow* window, double xpos, double ypos)
{
    std::cout << '[' << xpos << ';' << ypos << ']' << '\n';
}

void EventManager::CloseCallback(GLFWwindow* window)
{
    std::cout << "Closing!1!1!1!1!1\n";
}

void EventManager::SetWindow(Window* window)
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

void EventManager::PostEvent(const Event& event)
{
    queue_.push(event);
}

bool EventManager::PollEvent(Event* event)
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

bool Event::PollEvent()
{
    return EventManager::PollEvent(this);
}

EventData Event::GetData() const
{
    return data_;    
}

EventType Event::GetType() const
{
    return type_;
}

} // namespace input
