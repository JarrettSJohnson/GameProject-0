#include "Application.h"
#include "Renderer.h"
#include "Object.h"
#include "FrameTimer.h"

#include <iostream>

int SDL_main(int argc, char* argv[])
{
	ccm::Application app("Game", 1280, 720);
	ccm::Renderer renderer{ app };
	auto[width, height] = app.getSize();
	ccm::Object obj{ ccm::Rect{width / 2, height / 2, 128, 128}, ccm::Colors::Green };

	ccm::FrameTimer ft{};

	/* Game loop */
	while (!app.m_quit)
	{
		float dt = ft.mark();
		app.handleEvents();
		renderer.clear();
		renderer.draw(obj);
		renderer.render();
	}

	return 0;
}
