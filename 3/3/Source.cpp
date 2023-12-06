#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ejemplo de Bounce");

    sf::Vector2f position(400.0f, 100.0f);
    sf::Vector2f velocity(0.0f, 0.0f);

    const float gravity = 0.1f;
    const float bounceFactor = -0.7f;
    const float ballRadius = 20.0f;
    const float windowHeight = 600.0f;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        velocity.y += gravity;
        position += velocity;

        if (position.y + ballRadius > windowHeight) {
            position.y = windowHeight - ballRadius;
            velocity.y *= bounceFactor;
        }

        window.clear();

        sf::CircleShape ball(ballRadius);
        ball.setFillColor(sf::Color::Red);
        ball.setPosition(position);
        window.draw(ball);

        window.display();
    }

    return 0;
}

