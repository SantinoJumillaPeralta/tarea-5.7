#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Movimiento con Aceleraci�n");

    sf::CircleShape circle(20.0f);
    circle.setFillColor(sf::Color::Blue);
    sf::Vector2f velocity(0.0f, 0.0f);
    float acceleration = 0.2f;
    float friction = 0.1f;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            if (velocity.x > 0.0f)
                velocity.x -= friction;
            else
                velocity.x -= acceleration;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if (velocity.x < 0.0f)
                velocity.x += friction;
            else
                velocity.x += acceleration;
        }
        else
        {
            // Si no se presionan teclas de direcci�n, aplicamos fricci�n
            if (velocity.x > 0.0f)
                velocity.x -= friction;
            else if (velocity.x < 0.0f)
                velocity.x += friction;
        }

        // Limitamos la velocidad m�xima
        if (velocity.x > 5.0f)
            velocity.x = 5.0f;
        else if (velocity.x < -5.0f)
            velocity.x = -5.0f;

        circle.move(velocity);

        window.clear();
        window.draw(circle);
        window.display();
    }

    return 0;
}

