#include "context.hpp"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>
#include <algorithm>
#include <math.h>

#define NO_FLAGS 0

Context::Context() {
    al_init();
    al_init_primitives_addon();
    display = al_create_display(WINDOW_WIDTH, WINDOW_HEIGHT);
    event_queue = al_create_event_queue();

    if (display == NULL || event_queue == NULL) {
        cout << "Error: Could not create Allegro resources" << endl;
        exit(1);
    }

    al_register_event_source(event_queue, al_get_display_event_source(display));
}

Context::~Context() {
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
}

bool Context::shouldExit() { 
    ALLEGRO_EVENT curEvent;
    bool didWeGetEvent = al_peek_next_event(event_queue, &curEvent);

    if (didWeGetEvent) {
        al_drop_next_event(event_queue);
        return curEvent.type == ALLEGRO_EVENT_DISPLAY_CLOSE;
    }

    return false;
}

void Context::RenderFrame() {
   
    al_set_target_backbuffer(display);

    ALLEGRO_COLOR color = al_map_rgba(0, 0, 0, 255);
    al_clear_to_color(color);

    ALLEGRO_COLOR tc = al_map_rgba(0, 128, 0, 255);
    uint8_t n = 0;
    for (Triangle* t : triangles) {

        al_draw_triangle(t->isoP1.X, t->isoP1.Y, t->isoP2.X, t->isoP2.Y, t->isoP3.X, t->isoP3.Y, tc, 1.0);
        n += 64;
        tc = al_map_rgba(n, 128, 64, 255);
    }

    al_flip_display();

}

void Context::RegisterTriangle(Triangle* t) {
    triangles.push_back(t);
}