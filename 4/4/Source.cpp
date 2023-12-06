#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ejemplo de Bounce");

    sf::Vector2f position(400.0f, 100.0f);
    sf::Vector2f velocity(0.0f, 0.0f);

    const float gravity = 0.1f;
    const float bounceFactor = -0.7f;
    const float floorPosition = 580.0f; // Posición del suelo ajustada

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        velocity.y += gravity;
        position += velocity;

        if (position.y > floorPosition) { // Verifica si ha alcanzado el suelo
            position.y = floorPosition; // Ajusta la posición al suelo
            velocity.y *= bounceFactor;

            // Agregar una pequeña fricción para evitar rebotes infinitos
            if (std::abs(velocity.y) < 0.1f) {
                velocity.y = 0.0f;
                position.y = floorPosition - 1.0f;
            }
        }

        window.clear();

        sf::CircleShape ball(20.0f);
        ball.setFillColor(sf::Color::Red);
        ball.setPosition(position);
        window.draw(ball);

        window.display();
    }

    return 0;
}
