#include "logic.h"

using namespace nsGame;

void Logic::load() {
}

int Logic::update() {
    return 0;
}

void Logic::render(MinGL & window) {
    window.setBackgroundColor(nsGraphics::RGBAcolor(255, 0, 0));
}

void Logic::events(nsEvent::Event_t event) {
    std::cout << event.eventType << std::endl;
}