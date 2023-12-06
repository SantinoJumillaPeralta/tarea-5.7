#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Fast & Furious");

    // Velocidades inicial y final del c�rculo
    float velocidadInicial = 1.0f;
    float velocidadFinal = 5.0f;
    float velocidadActual = velocidadInicial;

    // Posici�n inicial del c�rculo
    sf::Vector2f posicion(100.0f, 300.0f);
    const float radioCirculo = 20.0f;

    // Crear un c�rculo verde
    sf::CircleShape circulo(radioCirculo);
    circulo.setFillColor(sf::Color::Green);
    circulo.setPosition(posicion);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Mover el c�rculo horizontalmente
        posicion.x += velocidadActual;

        // Si el c�rculo sale por el lado derecho, vuelve a entrar por la izquierda
        if (posicion.x > window.getSize().x + radioCirculo) {
            posicion.x = -radioCirculo;
            velocidadActual *= 1.5f;  // Incrementar la velocidad al volver a entrar

            // Restaurar la velocidad inicial si se alcanza la velocidad final preestablecida
            if (velocidadActual > velocidadFinal) {
                velocidadActual = velocidadInicial;
            }
        }

        window.clear();
        circulo.setPosition(posicion);
        window.draw(circulo);
        window.display();
    }

    return 0;
}

