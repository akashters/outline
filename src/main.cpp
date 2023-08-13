
#include <vk_app.hpp>

void draw_canvas(skity::Canvas* canvas);
void highlight_cursor(skity::Canvas* canvas, float x, float y);

class App : public outline::VkApp {
public:
    App()
        : outline::VkApp(800, 600, "Outline", { 1.f, 1.f, 1.f, 1.f }) {}
    ~App() override = default;

protected:
    void OnUpdate(float elapsed_time) override {
        // get mouse position and draw circle
        double x, y;
        GetCursorPos(x, y);
        highlight_cursor(GetCanvas(), x, y);
        draw_canvas(GetCanvas());
        GetCanvas()->flush();
    }
};

int main(int argc, const char** argv) {
    App app;
    app.Run();
    return 0;
}