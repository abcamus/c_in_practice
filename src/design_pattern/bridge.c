/**
 * @brief 具体的实现画线、渲染文本的实现防范，平台相关，有多个实现
 *
 */
typedef struct {
    void (*draw_text)();
    void (*draw_line)();
} WindowImp;

typedef struct {
    WindowImp *impl;
} Window;

static void draw_text(Window *win)
{
    // 将请求发送给实现
    win->impl->draw_text();
}

static void draw_line(Window *win)
{
    // 将请求发送给实现
    win->impl->draw_line();
    win->impl->draw_line();
    win->impl->draw_line();
    win->impl->draw_line();
}

typedef struct {
    Window win;
    void (*draw_border)();
} IconWindow;

void draw_border(Window *win)
{
    draw_text(win);
    draw_line(win);
}