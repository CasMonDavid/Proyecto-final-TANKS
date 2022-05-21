#include <iostream>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <string>
#include <Windows.h>

using namespace std;

int jugar();

int ancho = 600;
int alto = 800;
int segundo = 0;

ALLEGRO_DISPLAY* ventana;
ALLEGRO_TIMER* segundoTimer;
ALLEGRO_EVENT_QUEUE* queue;
ALLEGRO_FONT* lazy;
ALLEGRO_BITMAP* menu_principal;
ALLEGRO_BITMAP* menu_opcion1;
ALLEGRO_BITMAP* menu_opcion2;
ALLEGRO_BITMAP* juego_fondo;
ALLEGRO_BITMAP* personaje_arriba;
ALLEGRO_BITMAP* personaje_abajo;
ALLEGRO_BITMAP* personaje_derecha;
ALLEGRO_BITMAP* personaje_izquierda;

int main()
{
    al_init();
    al_init_font_addon();
    al_init_ttf_addon();
    al_install_mouse();
    al_init_primitives_addon();
    al_init_image_addon();
    al_install_keyboard();

    int ancho_w = GetSystemMetrics(SM_CXSCREEN);
    int alto_w = GetSystemMetrics(SM_CYSCREEN);
    int segundo = 0;
    int x = -1, y = -1;
    int botones[] = { 0 };

    ventana = al_create_display(ancho, alto);
    segundoTimer = al_create_timer(1.0);
    queue = al_create_event_queue();
    lazy = al_load_font("fuentes/lazy.ttf", 20, NULL);

    ALLEGRO_EVENT evento_tiempo;

    //imagenes BMP
    menu_principal = al_load_bitmap("imagenes/pagina_uno.bmp");
    menu_opcion1 = al_load_bitmap("imagenes/pagina_dos.bmp");
    menu_opcion2 = al_load_bitmap("imagenes/pagina_tres.bmp");
    personaje_arriba = al_load_bitmap("imagenes/personaje_jugador_arriba.png");
    personaje_abajo = al_load_bitmap("imagenes/personaje_jugador_abajo.png");
    personaje_derecha = al_load_bitmap("imagenes/personaje_jugador_derecha.png");
    personaje_izquierda = al_load_bitmap("imagenes/personaje_jugador_izquierda.png");
    juego_fondo = al_load_bitmap("imagenes/juego_uno.bmp");

    //eventos
    al_register_event_source(queue, al_get_timer_event_source(segundoTimer));
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_start_timer(segundoTimer);

    //Ventana del juego
    al_set_window_title(ventana, "MI juego");
    al_set_window_position(ventana, ancho_w / 2 - 600 / 2, alto_w / 2 - 800 / 2);


    while (true)
    {
        al_wait_for_event(queue, &evento_tiempo);
        if (evento_tiempo.type == ALLEGRO_EVENT_TIMER) {
            if (evento_tiempo.timer.source == segundoTimer) {
                segundo++;
            }
        }

        al_clear_to_color(al_map_rgb(0, 0, 0));

        if (botones[0] == 0) {
            al_draw_bitmap(menu_principal, 0, 0, 0);
        }
        else if (botones[0] == 1) {
            al_draw_bitmap(menu_opcion1, 0, 0, 0);
        }
        else {
            al_draw_bitmap(menu_opcion2, 0, 0, 0);
        }

        if (evento_tiempo.type == ALLEGRO_EVENT_MOUSE_AXES || evento_tiempo.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
            x = evento_tiempo.mouse.x;
            y = evento_tiempo.mouse.y;

            if ( x >= 96 && x <= 322 && y >= 248 && y <= 287 ) {
                botones[0] = 1;
                if (evento_tiempo.mouse.button & 1) { //jugar
                    jugar();
                }
            }
            else {
                if (x >= 94 && x <= 354 && y >= 333 && y <= 375) { //salir
                    botones[0] = 2;
                    if (evento_tiempo.mouse.button & 1) {
                        return 1;
                    }
                }
                else {
                    botones[0] = 0;
                }
            }
        }

        al_draw_text(lazy, al_map_rgb(255, 255, 255), 0, 770, NULL, ("Segundos: " + to_string(segundo)).c_str());
        al_flip_display();
    }
    return 0;
}

int jugar()
{    
    float posi_x = 38, posi_y = 53, velocidad_movimiento = 32;
    int posicion_animacion = 0;

    while (true) {
        ALLEGRO_EVENT evento_jugar;
        al_wait_for_event(queue, &evento_jugar);
        

        if (evento_jugar.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            switch (evento_jugar.keyboard.keycode) {
            case ALLEGRO_KEY_DOWN:
                posi_y += velocidad_movimiento;
                break;
            case ALLEGRO_KEY_UP:
                posi_y -= velocidad_movimiento;
                break;
            case ALLEGRO_KEY_RIGHT:
                posi_x += velocidad_movimiento;
                break;
            case ALLEGRO_KEY_LEFT:
                posi_x -= velocidad_movimiento;
            default:
                break;
            }
        }
        if (evento_jugar.type == ALLEGRO_EVENT_TIMER) {
            if (evento_jugar.timer.source == segundoTimer) {
                segundo++;
            }
        }

        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap(juego_fondo, 0, 0, 0);

        if (evento_jugar.keyboard.keycode == ALLEGRO_KEY_DOWN) {
            //al_draw_bitmap(personaje_abajo, posi_x, posi_y, 0);
            posicion_animacion = 0;
        }
        else if (evento_jugar.keyboard.keycode == ALLEGRO_KEY_UP) {
            //al_draw_bitmap(personaje_arriba, posi_x, posi_y, 0);
            posicion_animacion = 1;
        }
        else if (evento_jugar.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
            //al_draw_bitmap(personaje_derecha, posi_x, posi_y, 0);
            posicion_animacion = 2;
        }
        else if (evento_jugar.keyboard.keycode == ALLEGRO_KEY_LEFT) {
            //al_draw_bitmap(personaje_izquierda, posi_x, posi_y, 0);
            posicion_animacion = 3;
        }

        if (posicion_animacion == 0) {
            al_draw_bitmap(personaje_abajo, posi_x, posi_y, 0);
        }
        else if (posicion_animacion == 1) {
            al_draw_bitmap(personaje_arriba, posi_x, posi_y, 0);
        }
        else if (posicion_animacion == 2) {
            al_draw_bitmap(personaje_derecha, posi_x, posi_y, 0);
        }
        else {
            al_draw_bitmap(personaje_izquierda, posi_x, posi_y, 0);
        }

        
        
        //al_draw_bitmap(personaje_arriba, posi_x, posi_y, 0);
        al_draw_text(lazy, al_map_rgb(255, 255, 255), 0, 770, NULL, ("Segundos: " + to_string(segundo)).c_str());
        al_flip_display();
    }

    return 1;
}