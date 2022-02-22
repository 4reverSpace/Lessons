#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <string>

sf::RenderWindow window(sf::VideoMode(1200, 840), "Kalander");


int StringToNum(std::string text) {
    int ans = 0;
    for (int i = (text[0] == '-'); i < text.length()  ; ++ i) {
        ans *= 10;
        ans += (int)(text[i] - '0');
    }
    if (text[0] == '-')
        ans *= -1;
    return ans;
}
void DrawButtons() {
    sf::ConvexShape left_button(3);
    left_button.setPoint(0, sf::Vector2f(500, 30));
    left_button.setPoint(1, sf::Vector2f(500, 80));
    left_button.setPoint(2, sf::Vector2f(450, 55));
    left_button.setFillColor(sf::Color(160,160,160));
    sf::ConvexShape right_button(3);
    right_button.setPoint(0, sf::Vector2f(720, 30));
    right_button.setPoint(1, sf::Vector2f(720, 80));
    right_button.setPoint(2, sf::Vector2f(770, 55));
    right_button.setFillColor(sf::Color(160,160,160));
    window.draw(left_button);
    window.draw(right_button);
}
void DrawCalander(int year) {
    if (year == 0)
        return;
    int first_day = 0;
    int add_day = 0;
    if (year >= 1) {
        first_day = (abs(365 * (year - 1)) + abs((year - 1) / 4) - abs((year - 1) / 100) + abs((year - 1) / 400)) % 7;
        add_day = (year % 4 == 0) - (year % 100 == 0) + (year % 400) == 0;
    }
    else {
        add_day = ((abs(year) - 1) % 4 == 0) - ((abs(year) - 1) % 100 == 0) + ((abs(year) - 1) % 400) == 0;
        first_day = (6 - (abs(365 * (year + 1)) + abs((year + 1) / 4) - abs((year + 1) / 100) + abs((year + 1) / 400)) % 7) % 7;
    }
    sf::Text day ;
    sf::Font font;
    font.loadFromFile("C:/Users/79028/Desktop/Scripts/C++/AllerDisplay.ttf");
    day.setFont(font);
    day.setFillColor(sf::Color::Black);
    day.setCharacterSize(22);
    std::string week[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
    std::string month[12] = {"January", "February", "March", "April", "May",
            "June", "July", "August", "September", "October", "November", "December"};
    for (int i = 0; i < 12; ++i) {
        day.setPosition(150 + 250 * ( i  % 4), 100 + 250 * (i / 4));
        day.setString(month[i]);
        window.draw(day);
    }
    int day_in_month[12] = {31, 28 + add_day, 31, 30 , 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 0; i < 21; ++i){
        day.setPosition(100, 130 + 30 * i + 40 * ( i / 7 ));
        day.setString(week[i % 7]);
        window.draw(day);
    }
    day.setPosition(170, 130 + 30 * first_day);
    int cur_day = 1, cur_month = 0;
    for (int i = 0; i < 365 + add_day; ++i, ++cur_day) {
        int place_in_week = (first_day + i) % 7;
        if (i == 255 ||
            cur_month == 8 && cur_day == 20 ||
            cur_month == 3 && cur_day == 23)
                day.setFillColor(sf::Color(70, 220, 50));
        else if (place_in_week >= 5)
            day.setFillColor(sf::Color::Red);
        else
            day.setFillColor(sf::Color::Blue);
        day.setString((cur_day< 10 ? "0" : "") + std::to_string(cur_day));
        window.draw(day);
        if (cur_day == day_in_month[cur_month]) {
            cur_day = 0;
            ++cur_month;
            if (cur_month == 4 || cur_month == 8) {
                day.setPosition(170, 130 + 250 * (cur_month / 4) + 30 * ((place_in_week + 1) % 7));
            } else {
                day.setPosition(170 + 250 * (cur_month % 4), 130 + 250 * (cur_month / 4) + 30 * ((place_in_week + 1) % 7));
            }
        } else {
            if (place_in_week == 6) {
                day.move(40, -6 * 30);
            } else {
                day.move(0, 30);
            }
        }
    }
}
int main()
{

    sf::Event event;
    sf::String playerInput;

    sf::Font font;
    if (!font.loadFromFile("C:/Users/79028/Desktop/Scripts/C++/AllerDisplay.ttf"))
    {
        return -1;
    }
    sf::Text playerText;
    playerText.setPosition(560,40);
    playerText.setFont(font);
    playerText.setCharacterSize(30);
    playerText.setStyle(sf::Text::Regular);
    playerText.setFillColor(sf::Color::Red);
    window.clear(sf::Color(255,255,255,1));
    while (window.isOpen())
    {
        while(window.pollEvent(event))
        {
            if (event.key.code == sf::Keyboard::Escape)
            {
                playerInput.clear();
            }
            else if (event.type == sf::Event::TextEntered) // ?
            {
                if ((event.text.unicode > 47 && event.text.unicode < 58) ||
                    (playerInput.getSize() == 0 && event.text.unicode == 45)) {
                    playerInput += event.text.unicode;
                    if (playerInput.getSize() == 7) {
                        playerInput.clear();
                    }
                    playerText.setString(playerInput);
                }
            }
            else if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    if (-event.mouseButton.x  + 660 > -2 *  event.mouseButton.y &&
                        event.mouseButton.x  - 880 < -2 *  event.mouseButton.y &&
                        event.mouseButton.x > 720 ){
                        int year = StringToNum(playerInput.toAnsiString()) + 1;
                        playerInput = std::to_string(year);
                    } else if (event.mouseButton.x  - 560 > -2 *  event.mouseButton.y &&
                            -event.mouseButton.x  + 340 < -2 *  event.mouseButton.y &&
                            event.mouseButton.x < 500) {
                        int year = StringToNum(playerInput.toAnsiString()) - 1;
                        playerInput = std::to_string(year);
                    }

                }
            }
        }
        window.clear(sf::Color::White);
        playerText.setString(playerInput);
        sf::RectangleShape pole(sf::Vector2f (180, 45));
        pole.setOutlineColor(sf::Color::Black);
        pole.setOutlineThickness(4);
        pole.setPosition(520,35);
        window.draw(pole);
        window.draw(playerText);
        DrawCalander(StringToNum(playerInput.toAnsiString()));
        DrawButtons();
        window.display();
    }

    return 0;
}
