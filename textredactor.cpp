#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <string>
const int Width = 900, Length = 1500;
std::vector<std::string> Array = {};
sf::RenderWindow window(sf::VideoMode(Length, Width), "Kalander");

//Функциональная
int GetInt(std::string str);
int BinaryString(std::string str, int begin, sf::Text text);
//Внешняя часть
void DrawButtons(); void DrawText(); std::string StringInput(std::string str = ""); int NumInput(std::string str = "");
//кнопки
void ButtonOneInsert(); void ButtonManyInsert(); void ButtonDelete(); void ButtonStringInsert();
void ButtonChangeChar();void ButtonChangeString(); void ButtonZero(); void ButtonNumbers();
void ButtonStars(); void ButtonBrace();


//std::cout<<text.getGlobalBounds().left + text.getLocalBounds().width << std::endl;

int GetInt(std::string str) {
    int ans = 0;
    for (int i = 0; i < str.size(); ++i) {
        ans *= 10;
        ans += str[i] - '0';
    }
    return ans;
}
std::string StringInput(std::string str) {
    sf::RenderWindow string_input(sf::VideoMode(800, 130), "Print string here");
    sf::Text title;
    sf::Font font;
    font.loadFromFile("Cantarell-Regular.ttf");
    title.setFont(font);
    title.setFillColor(sf::Color(20,140,240));
    title.setCharacterSize(25);
    title.setString(str);
    title.setPosition(10, 10);
    sf::Text text;
    sf::String string;
    text.setFont(font);
    text.setFillColor(sf::Color::Blue);
    text.setCharacterSize(20);
    text.setPosition(30, 70);
    while (string_input.isOpen()) {
        sf::Event event;
        while(string_input.pollEvent(event)) {
            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode > 31 && event.text.unicode < 127) {
                    if (text.getGlobalBounds().left + text.getLocalBounds().width < 750)
                        string += event.text.unicode;
                } else if (event.text.unicode == 8) {
                    if (!string.isEmpty())
                        string.erase(string.getSize() - 1);
                } else if (event.text.unicode == 13)
                    string_input.close();
            }
        }
        string_input.clear(sf::Color::White);
        text.setString(string);
        string_input.draw(title);
        string_input.draw(text);
        string_input.display();
    }
    return string.toAnsiString();
}
int NumInput(std::string str) {
    sf::RenderWindow num_input(sf::VideoMode(300, 100),"");
    sf::Text title;
    sf::Font font;
    font.loadFromFile("Cantarell-Regular.ttf");
    title.setFont(font);
    title.setFillColor(sf::Color(20,140,240));
    title.setCharacterSize(25);
    title.setString(str);
    title.setPosition(10, 10);
    sf::Text text;
    sf::String num;
    text.setFont(font);
    text.setFillColor(sf::Color::Blue);
    text.setCharacterSize(20);
    text.setPosition(20, 53);
    while (num_input.isOpen()) {
        sf::Event event;
        while(num_input.pollEvent(event)) {
            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode >= 48 && event.text.unicode <= 57) {
                        num += event.text.unicode;
                        if (GetInt(num.toAnsiString()) > 100)
                            num.erase(num.getSize() - 1);
                }
                else if (event.text.unicode == 8) {
                    if (!num.isEmpty())
                        num.erase(num.getSize() - 1);
                }
                else if (event.text.unicode == 13)
                    num_input.close();
            }

        }
        num_input.clear(sf::Color::White);
        text.setString(num);
        num_input.draw(text);
        num_input.draw(title);
        num_input.display();
    }
    return GetInt(num.toAnsiString());
}
void DrawButtons() {
    sf::RectangleShape separate_line(sf::Vector2f(0, Width));
    separate_line.setPosition(Length - Length / 6, 0);
    separate_line.setOutlineThickness(1);
    separate_line.setOutlineColor(sf::Color::Black);
    window.draw(separate_line);
    sf::RectangleShape lines(sf::Vector2f(Length - Length / 6, 0));
    lines.setOutlineThickness(0.5);
    lines.setOutlineColor(sf::Color(140,150,190));
    for (int i = 0; i < Width; i += 40) {
        lines.setPosition(0, i + 1);
        window.draw(lines);
    }
    sf::Text text;
    sf::Font font;
    font.loadFromFile("Cantarell-Regular.ttf");
    text.setFont(font);
    text.setFillColor(sf::Color::Black);
    text.setCharacterSize(20);
    sf::RectangleShape buttons(sf::Vector2f(Length / 6 - 90, Width / 10 - 35));
    buttons.setOutlineThickness(2);
    buttons.setOutlineColor(sf::Color::Black);
    buttons.setFillColor(sf::Color(190,200,240));
    std::string dp[10] = {"Insert", "Insert(many)", "Delete line", "Insert substr", "Change char", "Change string",
            "Delete 0","Modify numbers", "Change * to +", "Delete {..}"};
    for (int i = 0; i < 10; ++i) {
        buttons.setPosition(Length - Length / 6 + 50, 10 + (Width / 10 + 2) * i);
        text.setString(dp[i]);
        text.setPosition(Length - Length / 6 + 53, 10 + (Width / 10 + 2) * i + 15);
        window.draw(buttons);
        window.draw(text);
    }
}


int BinaryString(std::string str, int begin, sf::Text text) {
    int lhs = 0;
    int rhs = str.size();
    while (rhs - lhs > 1) {
        int mid = (rhs + lhs) / 2;
        text.setPosition(begin, 0);
        text.setString(str.substr(0, mid));
        if (text.getGlobalBounds().left + text.getLocalBounds().width <= Length - Length / 6 - 10)
            lhs = mid;
        else
            rhs = mid;
    }
    return lhs;
}
void DrawText() {
    int line = 0;
    sf::Text text;
    sf::Font font;
    font.loadFromFile("Cantarell-Regular.ttf");
    text.setFont(font);
    text.setFillColor(sf::Color::Black);
    text.setCharacterSize(40);
    for (int i = 0; i < Array.size() && i < 22; ++i){
        text.setPosition(0, line * 40);
        text.setString(Array[i]);
        if (text.getGlobalBounds().left + text.getLocalBounds().width > Length - Length / 6 - 10) {
            int end = BinaryString(Array[i], 0, text);
            text.setString(Array[i].substr(0, end));
            if (end != 0) {
                Array.insert(std::next(Array.begin(), i + 1), Array[i].substr(end));
                Array[i] = Array[i].substr(0, end);
            } else {
                --i;
            }
        }
        ++line;
        window.draw(text);
    }
}

void ButtonOneInsert() {
    int pos = NumInput("Input line");
    std::string input = StringInput("Input string");
    if (input.empty() || Array.size() > 23)
        return;
    if (pos >= Array.size())
        Array.push_back(input);
    else
        Array.insert(std::next(Array.begin(), pos), input);
}
void ButtonManyInsert() {
    int pos = NumInput("Input start line");
    int num = NumInput("Input number of strings");
    if (pos >= Array.size())
        pos = -1;
    for (int i = 0 ; i < num; ++i) {
        std::string input = StringInput();
        if (input.empty() || Array.size() > 23) {
            continue;
        }
        if (pos == -1)
            Array.push_back(input);
        else
            Array.insert(std::next(Array.begin(), pos + i), input);
    }

}
void ButtonDelete() {
    int line = NumInput("Input line") - 1;
    if (line >= Array.size())
        Array.pop_back();
    else
        Array.erase(std::next(Array.begin(), line));
}
void ButtonStringInsert() {
    int line = NumInput("Input line") - 1;
    int pos = NumInput("Input place of insert(n > 0)") - 1;
    if (line >= Array.size())
        line = Array.size() - 1;
    if (pos >= Array[line].size())
        pos = Array[line].size() - 1;
    std::string input = StringInput("Input inserting string");
    if (input.empty())
        return;
    Array[line].insert(pos, input);
}
void ButtonChangeChar() {
    int line = NumInput("Input line") - 1;
    int pos = NumInput("Input position of char") - 1;
    if (line >= Array.size())
        line = Array.size() - 1;
    if (pos >= Array[line].size())
        pos = Array[line].size() - 1;
    std::string input = StringInput("");
    while(input.size() <= 1)
        return;
    Array[line][pos] = input[0];
}
void ButtonChangeString() {
    int first_line = NumInput("Input start line") - 1;
    int second_line = NumInput("Input end line") - 1;
    if (first_line >= Array.size())
        first_line = Array.size() - 1;
    if (second_line >= Array.size())
        second_line = Array.size() - 1;
    std::string change = StringInput("Input string you want to change");
    std::string replacement = StringInput("Input new string");
    if (change.empty() || replacement.empty())
        return;
    for (int i = first_line; i <= second_line; ++i) {
        int start = 0;
        for(int j = Array[i].find(change, start); j != std::string::npos; start = j + replacement.size(), j = Array[i].find(change, start)) {
            Array[i].erase(j, change.size());
            Array[i].insert(j, replacement);
        }
    }
}
void ButtonZero() {
    int first_line = NumInput("Input start line") - 1;
    int second_line = NumInput("Input end line") - 1;
    if (first_line >= Array.size())
        first_line = Array.size() - 1;
    if (second_line >= Array.size())
        second_line = Array.size() - 1;
    for (int i = first_line; i <= second_line; ++i) {
        int start = -1, count = 0;
        for (int j = 0; j < Array[i].size(); ++j) {
            if (Array[i][j] == '0' && (j == 0 || Array[i][j - 1] == ' ')) { // если первый 0
                start = j;
                count = 1;
            } else if (Array[i][j] == '0') { // если 0 в числе
                ++count;
            } else if (start != -1) {
                Array[i].erase(start, count - (Array[i][j] == ' '));
                j -= count - (Array[i][j] == ' ');
                start = -1;
                count = 0;
            } else {
                start = -1;
                count = 0;
            }
        }
        if (start != -1)
            Array[i].erase(start, count - (Array[i].back() == '0'));
    }
}
void ButtonNumbers() {
    for (int i = 0; i < Array.size(); ++i) {
        int start = -1, count = 0;
        bool remove = false;
        for(int j = 0; j < Array[i].size(); ++j) {
            if (Array[i][j] >= '0' && Array[i][j] <= '9') {
                if (start == -1) {
                    start = j;
                    count = 1;
                }
                else {
                    if (Array[i][j] - Array[i][j - 1] <= 0)
                        remove = true;
                    ++count;
                }
            } else if (remove || count == 1) {
                Array[i].erase(start, count);
                j -= count;
                remove = false;
                count = 0;
                start = -1;
            }
        }
        if (start != -1 && (remove || count == 1)) {
            Array[i].erase(start, count);
        }
    }
}
void ButtonStars() {
    for (int i = 0; i < Array.size(); ++i) {
        int count = 0, start = -1;
        for (int j = 0; j < Array[i].size(); ++j) {
            if (Array[i][j] == '*') {
                if (start == -1)
                    start = j;
                ++count;
            } else if (count > 1 && start != -1) {
                Array[i].erase(start, count);
                j -= count;
                std::string change("+", count / 2);
                Array[i].insert(start,change);
                j += count / 2;
                count = 0;
                start = -1;
            }
        }
    }
}
void ButtonBrace() {
    int line = NumInput("Input line") - 1;
    bool opened = false;
    int count = 0, start = -1;
    for (int i = 0; i < Array[line].size(); ++i) {
        if (Array[line][i] == '{') {
            opened = true;
            start = i;
            count = 1;
        } else if (Array[line][i] == '}' && opened) {
            ++count;
            Array[line].erase(start, count);
            i -= count;
            start = -1;
            count = 0;
            opened = false;
        } else {
            count += opened;
        }

    }
}
int main()
{
    sf::String playerInput;
    sf::Font font;
    if (!font.loadFromFile("Cantarell-Regular.ttf"))
    {
        return -1;
    }
    while (window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode > 31 && event.text.unicode < 127) {
                    playerInput += event.text.unicode;
                    if(Array.empty())
                        Array.push_back(playerInput.toAnsiString());
                    else
                        Array.back().append(playerInput);
                }
            } else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.x >= Length - Length / 6 + 50
            && event.mouseButton.x <= Length - Length / 6 + 50 + Length / 6 - 90 ) {
                if (event.mouseButton.y >= 10 && event.mouseButton.y <= Width / 10 - 25)
                    ButtonOneInsert();
                else if (event.mouseButton.y >= 10 + (Width / 10 + 2) && event.mouseButton.y <= (Width / 10 + 2) + Width / 10 - 25)
                    ButtonManyInsert();
                else if (event.mouseButton.y >= 10 + (Width / 10 + 2) * 2 && event.mouseButton.y <= (Width / 10 + 2) * 2 + Width / 10 - 25)
                    ButtonDelete();
                else if (event.mouseButton.y >= 10 + (Width / 10 + 2) * 3 && event.mouseButton.y <= (Width / 10 + 2) * 3 + Width / 10 - 25)
                    ButtonStringInsert();
                else if (event.mouseButton.y >= 10 + (Width / 10 + 2) * 4 && event.mouseButton.y <= (Width / 10 + 2) * 4 + Width / 10 - 25)
                    ButtonChangeChar();
                else if (event.mouseButton.y >= 10 + (Width / 10 + 2) * 5 && event.mouseButton.y <= (Width / 10 + 2) * 5 + Width / 10 - 25)
                    ButtonChangeString();
                else if (event.mouseButton.y >= 10 + (Width / 10 + 2) * 6 && event.mouseButton.y <= (Width / 10 + 2) * 6 + Width / 10 - 25)
                    ButtonZero();
                else if (event.mouseButton.y >= 10 + (Width / 10 + 2) * 7 && event.mouseButton.y <= (Width / 10 + 2) * 7 + Width / 10 - 25)
                    ButtonNumbers();
                else if (event.mouseButton.y >= 10 + (Width / 10 + 2) * 8 && event.mouseButton.y <= (Width / 10 + 2) * 8 + Width / 10 - 25)
                    ButtonStars();
                else if (event.mouseButton.y >= 10 + (Width / 10 + 2) * 9 && event.mouseButton.y <= (Width / 10 + 2) * 9 + Width / 10 - 25)
                    ButtonBrace();
            } else if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        playerInput.clear();
        window.clear(sf::Color::White);
        DrawButtons();
        DrawText();
        window.display();

    }

    return 0;
}
