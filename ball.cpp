#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

void TextDef(sf::Text &text, sf::Font &font, std::string valuestring, int txtSize, bool isBold) {
    text.setFont(font);
    text.setString(valuestring);
    text.setCharacterSize(txtSize);
    text.setFillColor(sf::Color::Black);
    if (isBold) {
        text.setStyle(sf::Text::Bold);
    }
    else {
        text.setStyle(sf::Text::Regular);
    }
}

int main() {
    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SORT!"); // creating window
    sf::CircleShape ball(30.0f);
    ball.setPosition(470,100);
    sf::Font font;
    if (!font.loadFromFile("G:\\abdullah\\Abdullah(Dont Delete Any thing)\\FONTS\\Rubik_Mono_One\\RMOR.ttf")) {
        std::cout << "Cant load/find the file" << '\n';
    }

    float moveSpeedY = 0.02f; // Adjust scrolling speed as needed
    float moveSpeedX = 0.3f; // Adjust scrolling speed as needed

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                std::cout << "Clicking\n";
            }
        }
        if(ball.getPosition().x+20 > 960){
            std::cout << "Collide with Wall" <<'\n';
            moveSpeedX = -moveSpeedX;
        }else if (ball.getPosition().y+20 > 960){
            std::cout << "Collide" << '\n';
            moveSpeedY = -moveSpeedY - 0.01f;
        }else if(ball.getPosition().x-20 < 0){
            std::cout << "Collide" << '\n';
            moveSpeedX = 0.3;
        }else if (ball.getPosition().y-20 < 0){
            std::cout << "Collide" << '\n';
            moveSpeedY = moveSpeedY + 0.01f;
        }        
        
        ball.move(moveSpeedX,moveSpeedY);
        window.clear(); // clearing window before using

        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        window.draw(ball);

        window.display(); // displaying everything
    }

    return 0;
}
