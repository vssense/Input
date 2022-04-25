#ifndef _WINDOW_HPP_INCLUDED
#define _WINDOW_HPP_INCLUDED

#include <GLFW/glfw3.h>

const size_t kDefaultWidth = 640;
const size_t kDefaultHeight = 480;

constexpr const char* kDefaultTitle = "Success is inevitable";

class Window
{
public:
    Window(size_t width = kDefaultWidth, size_t height = kDefaultHeight,
           const char* title = kDefaultTitle);
    ~Window();

    GLFWwindow* GetNativeWindow();
    void SetTitle(const char* title);

private:
    GLFWwindow* window_;
};

#endif // _WINDOW_HPP_INCLUDED