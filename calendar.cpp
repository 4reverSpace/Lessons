#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <string>
sf::RenderWindow window(sf::VideoMode(1200, 840), "Kalander");

void DrawButtons(); void DrawCalendar();
bool InLeftButton(int, int); bool InRightButton(int, int); int StringToNum(std::string);


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
    window.draw(left_button);

    sf::ConvexShape right_button(3);
    right_button.setPoint(0, sf::Vector2f(720, 30));
    right_button.setPoint(1, sf::Vector2f(720, 80));
    right_button.setPoint(2, sf::Vector2f(770, 55));
    right_button.setFillColor(sf::Color(160,160,160));
    window.draw(right_button);

    sf::RectangleShape input_field(sf::Vector2f (180, 45));//
    input_field.setOutlineColor(sf::Color::Black);
    input_field.setOutlineThickness(4);
    input_field.setPosition(520, 35);
    window.draw(input_field);
}

void DrawCalendar(int year) {
    if (year == 0)
        return;
    int first_day = 0;
    int add_day = 0;
    if (year >= 1) { // определение дня недели 1 января и високосности года
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
    std::string week[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"}; // дни недели и месяцы
    std::string month[12] = {"January", "February", "March", "April", "May",
            "June", "July", "August", "September", "October", "November", "December"};
    int day_in_month[12] = {31, 28 + add_day, 31, 30 , 31, 30, 31, 31, 30, 31, 30, 31};

    for (int i = 0; i < 12; ++i) { //рисуем месяцы
        day.setPosition(150 + 250 * ( i  % 4), 100 + 250 * (i / 4));
        day.setString(month[i]);
        window.draw(day);
    }

    for (int i = 0; i < 21; ++i){ // рисуем справа дни недели
        day.setPosition(100, 130 + 30 * i + 40 * ( i / 7 ));
        day.setString(week[i % 7]);
        window.draw(day);
    }

    day.setPosition(170, 130 + 30 * first_day); // задаем позицию для 1 января данного года
    int cur_day = 1, cur_month = 0;
    for (int i = 0; i < 365 + add_day; ++i, ++cur_day) { // рисуем сами дни
        int place_in_week = (first_day + i) % 7; // день недели
        if (i == 255 ||
            cur_month == 8 && cur_day == 20 ||
            cur_month == 3 && cur_day == 25) // праздник - зеленый
                day.setFillColor(sf::Color(0, 160, 30));
        else if (place_in_week >= 5) // выходной - красный
            day.setFillColor(sf::Color::Red);
        else // обычный день - синий
            day.setFillColor(sf::Color::Blue);

        // форматирование - если 1-9, то добавление 0 в конце
        day.setString((cur_day< 10 ? "0" : "") + std::to_string(cur_day));
        window.draw(day);
        // определение положения след дня
        if (cur_day == day_in_month[cur_month]) { // если месяц меняется
            cur_day = 0;
            ++cur_month;
            if (cur_month == 4 || cur_month == 8) // если меняется столбец
                day.setPosition(170, 130 + 250 * (cur_month / 4) + 30 * ((place_in_week + 1) % 7));
            else  // если не меняется
                day.setPosition(170 + 250 * (cur_month % 4),
                                130 + 250 * (cur_month / 4) + 30 * ((place_in_week + 1) % 7));
        } else {
            // если месяц не меняется
            if (place_in_week == 6) {
                day.move(40, -6 * 30);
            } else {
                day.move(0, 30);
            }
        }
    }
}
bool InLeftButton(int x, int y) {
    return x  - 560 > -2 * y && -x  + 340 < -2 *  y && x < 500;
}
bool InRightButton( int x, int y) {
    return -x  + 660 > -2 *  y && x  - 880 < -2 *  y && x > 720;
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
        while(window.pollEvent(event)) {
            if (event.key.code == sf::Keyboard::Escape) {
                playerInput.clear();
            }
            else if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode > 47 && event.text.unicode < 58 || // проверка на корректность ввода
                    playerInput.getSize() == 0 && event.text.unicode == 45) {
                    playerInput += event.text.unicode;
                    if (playerInput.getSize() == 7) // если 7 символ, то очищает, чтобы не было переполнения
                        playerInput.clear();
                    playerText.setString(playerInput);
                }
            }
            else if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed) { // определение клика мыши
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (InRightButton(event.mouseButton.x, event.mouseButton.y)) {
                        int year = StringToNum(playerInput.toAnsiString()) + 1;
                        playerInput = std::to_string(year);
                    } else if (InLeftButton(event.mouseButton.x, event.mouseButton.y)) {
                        int year = StringToNum(playerInput.toAnsiString()) - 1;
                        playerInput = std::to_string(year);
                    }

                }
            }
        }
        window.clear(sf::Color::White);
        playerText.setString(playerInput);
        DrawButtons();
        window.draw(playerText);
        DrawCalendar(StringToNum(playerInput.toAnsiString()));
        window.display();
    }

    return 0;
}
