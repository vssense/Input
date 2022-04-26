#ifndef _EVENT_HPP_INCLUDED
#define _EVENT_HPP_INCLUDED

// Scroll event
// Study what is Text input. What is codepoints? Didn't get it.

#include <queue>

#include "window.hpp"

namespace input
{

enum EventType
{
    kQuit,
    kKeyPress,
    kMousePress,
    kMouseMove,
    kMouseScroll,


    // kMouseEnter,
    // kMouseLeave,
};

enum Action
{
    kPress,
    lRelease,
    kHold
};

enum MouseButton
{
    kLMB,
    kRMB,
    kScrollWheel,
    kSideButton1,
    kSideButton2
};

struct PressMode
{
    int shift_pressed : 1;
    int ctrl_pressed  : 1;
    int alt_pressed   : 1;
};

struct Scroll
{
    int dx;
    int dy;
};

struct MouseMove         // Do we need dx and dy here?
{
    int x;
    int y;
};

struct MousePress        // Do we need coords here?
{
    MouseButton button;
    Action action;
    PressMode mode;      // Check with PressMode
};

struct KeyPress
{
    int key;             // Actually ascii codes
    int scancode;
    Action action;
    PressMode mods;      // Check with PressMode
};

union EventData
{
    MouseMove  mouse;
    MousePress button;
    KeyPress   key;
    Scroll     scroll;
};

class Event
{
  public:
    Event() {}

    bool PollEvent();

    EventData GetData() const;              // mb inline
    EventType GetType() const;

  private:
    EventType type_;
    EventData data_;

};

class EventManager
{
  private:
    EventManager() {}
  public:

    static void SetWindow(Window* window);

    static void PostEvent(const Event& event);
    static bool PollEvent(Event* event);

  private:
    static void KeyCallback        (GLFWwindow* window, int key, int scancode, int action, int mods);
    static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
    static void MouseMoveCallback  (GLFWwindow* window, double xpos, double ypos);
    static void CloseCallback      (GLFWwindow* window);
    static void ScrollCallback     (GLFWwindow* window, double dx, double dy);

    static Window* window_;
    static std::queue<Event> queue_;
};

} // namespace event

#endif // _EVENT_HPP_INCLUDED