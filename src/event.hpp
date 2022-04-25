#ifndef _EVENT_HPP_INCLUDED
#define _EVENT_HPP_INCLUDED

// Scroll event
// Study what is Text input. What is codepoints? Didn't get it.

namespace event
{

enum EventType
{
    kKeyPress,
    kMousePress,
    kMouseMove,
    
    // kMouseScroll,


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

enum PressMode
{
    kShift = 1,
    kCtrl  = 2,
    kAlt   = 4,
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
    int mode;            // Check with PressMode
};

struct KeyPress
{
    int key;             // Actually ascii number
    int scancode;
    Action action;
    int mods;            // Check with PressMode
};

class Event
{
    union EventData
    {
        MouseMove  mouse;
        MousePress button;
        KeyPress   key;
    };

  public:
    bool PollEvent();

    EventData GetData() const;
    EventType GetType() const;

  private:
    EventType type_;
    EventData data_;
};

} // namespace event

#endif // _EVENT_HPP_INCLUDED