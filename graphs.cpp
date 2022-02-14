#include <SFML/Graphics.hpp>
#include <iostream>

const int kWidth = 1000;
const int kHeight = 840;
sf::RenderWindow window(sf::VideoMode(kWidth, kHeight), "Graphs");




// Отвечающие за рисунки и их отображение

void CreateAxes(int = 40); void ColorZones();
void DrawRomb(sf::Color = sf::Color::Black); void DrawRectangle(sf::Color = sf::Color::Black);
void DrawLeftLine(sf::Color = sf::Color::Black); void DrawRightLine(sf::Color = sf::Color::Black);
void DrawCircle(sf::Color = sf::Color::Black); void DrawStraightParab(sf::Color = sf::Color::Black);
void DrawTurnedParab(sf::Color = sf::Color::Black);

//Функциональная часть и побочные функции
void PixelsToCords(int&, int&); void CordsToPixels(int&, int&);
void PlacePixel(int, int, sf::Color = sf::Color::Black);

bool UnderLeftLine(int, int); bool UnderRightLine(int, int); bool InsideCircle(int, int);
bool InsideRomb(int, int); bool InsideRectangle(int, int); bool InsideStraightParab(int, int);
bool InsideTurnedParab(int, int);



int main()
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color(255,255,255,1));
        ColorZones();

        CreateAxes(20);
        window.display();
    }

    return 0;
}

void CreateAxes(int step) {
    for (unsigned int y = 0; y <= kHeight; y += step) {
        sf::RectangleShape axis (sf::Vector2f(kWidth, 1.f)); //
        axis.setFillColor(sf::Color(200,200,200));
        axis.move(0,y);
        window.draw(axis);
    }
    sf::RectangleShape y_axe (sf::Vector2f(2.f, kHeight));
    y_axe.setFillColor(sf::Color::Black);
    y_axe.move(kWidth / (2 * step) * step,0);
    window.draw(y_axe);
    for (unsigned int x = 0; x <= kWidth; x += step) {
        sf::RectangleShape axis (sf::Vector2f(1.f, kHeight));
        axis.setFillColor(sf::Color(200,200,200));
        axis.move(x,0);
        window.draw(axis);
    }
    sf::RectangleShape x_axe (sf::Vector2f(kWidth, 2.f));
    x_axe.setFillColor(sf::Color::Black);
    x_axe.move(0,kHeight / (2 * step) * step);
    window.draw(x_axe);
}





void PixelsToCords(int& x, int& y) {
    x -= kWidth / 2;
    y = kHeight / 2 - y;
}
void CordsToPixels(int& x, int& y) {
    x += kWidth / 2;
    y = kHeight / 2 - y;
}

bool UnderLeftLine(int x, int y) {
    return y <= -1.5 * x - 140;
}
bool  UnderRightLine(int x, int y) {
    return y <= -2 * x + 400;
}
bool InsideCircle(int x, int y) {
    return (x - 140) * (x - 140) + (y - 160) * (y - 160) < 3600;
}
bool  InsideRomb(int x, int y) {
    return 0.5 * abs(x + 80) + abs(y + 20) <= 40;
}
bool  InsideRectangle(int x, int y) {
    if (x >= -40 && x <= 60)
        if (y >= -40 && y <= 40)
            return true;
    return false;
}
bool InsideStraightParab(int x, int y) {
    return -0.0625 * (x + 20) * (x + 20) - 100 >= y;
    // т.к работаем в нат числах c с масштабом, то пришлось ввести корректирующий коэф для параболл и круга
}
bool InsideTurnedParab(int x, int y) {
    return 0.0625 * (y + 100) * (y + 100) - 100 <= x;
}
void PlacePixel(int x, int y, sf::Color color) {
    sf::RectangleShape pixel(sf::Vector2f(3,3));
    pixel.setFillColor(color);
    CordsToPixels(x,y);
    pixel.move(x,y);
    window.draw(pixel);
}
void ColorZones() {
    for (int y = 0; y <= kHeight; ++y) {
        for (int x = 0; x <= kWidth; ++x) {
            PixelsToCords(x, y);
            if (UnderLeftLine(x, y) && !InsideRomb(x, y) && !InsideStraightParab(x, y) && !InsideTurnedParab(x, y))
                PlacePixel(x, y, sf::Color::Blue);
            else if (UnderLeftLine(x, y) && InsideTurnedParab(x, y) && InsideStraightParab(x, y))
                PlacePixel(x, y, sf::Color::Red);
            else if (InsideRectangle(x, y) && !InsideRomb(x, y))
                PlacePixel(x, y, sf::Color::Green);
            else if (InsideCircle(x, y) && UnderRightLine(x, y))
                PlacePixel(x, y, sf::Color::Magenta);
            else if (!InsideCircle(x, y) && !UnderRightLine(x, y))
                PlacePixel(x, y, sf::Color::Yellow);
            CordsToPixels(x, y);
        }
    }
}
void DrawStraightParab(sf::Color color) {
    for (int x = 0; x < kWidth; ++x) {
        for(int y = 0; y < kHeight; ++y) {
            PixelsToCords(x, y);
            if (y >= -0.0625 * (x + 20) * (x + 20) - 105 && y <= -0.0625 * (x + 20) * (x + 20) - 95)
                PlacePixel(x,y, color);
            CordsToPixels(x, y);
        }
    }
}
void DrawRectangle(sf::Color color) {
    sf::RectangleShape rectangle(sf::Vector2f(100, 80));
    int x = -40, y = 40;
    CordsToPixels(x, y);
    rectangle.move(x, y);
    rectangle.setOutlineColor(sf::Color::Black);
    rectangle.setOutlineThickness(3.f);
    window.draw(rectangle);
}
void DrawTurnedParab(sf::Color color) {
    for (int x = 0; x < kWidth; ++x) {
        for (int y = 0; y < kHeight; ++y) {
            PixelsToCords(x, y);
            if (x >= 0.0625 * (y + 100) * (y + 100) - 105 && x <= 0.0625 * (y + 100) * (y + 100) - 95)
                PlacePixel(x, y, color);
            CordsToPixels(x, y);
        }
    }
}
void DrawCircle(sf::Color color) {
    sf::CircleShape circle (60);
    int x = 80, y = 220;
    CordsToPixels(x, y);
    circle.move(x ,y);
    circle.setOutlineColor(color);
    circle.setOutlineThickness(3.f);
    window.draw(circle);

}
void DrawLeftLine(sf::Color color) {
    for (int y = 0; y <= kHeight; ++y) {
        for (int x = 0; x <= kWidth; ++x) {
            PixelsToCords(x, y);
            if (y == -1.5 * x - 140)
                PlacePixel(x, y, color);
            CordsToPixels(x, y);
        }
    }
}
void DrawRightLine(sf::Color color) {
    for (int y = 0; y <= kHeight; ++y) {
        for (int x = 0; x <= kWidth; ++x) {
            PixelsToCords(x, y);
            if (y == -2 * x + 400)
                PlacePixel(x, y, color);
            CordsToPixels(x, y);
        }
    }
}
void DrawRomb(sf::Color color) {
    for (int y = 0; y <= kHeight; ++y) {
        for (int x = 0; x <= kWidth; ++x) {
            PixelsToCords(x, y);
            if (0.5 * abs(x + 80) + abs(y + 20) == 40)
                PlacePixel(x, y, color);
            CordsToPixels(x, y);
        }
    }
}
