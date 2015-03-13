#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

vector<sf::Drawable*> drawables;

void pause_thread(int n)
{
    this_thread::sleep_for(chrono::seconds(n));
}

void foo()
{
    for (int i = 0; i < 5; i++) {
        cout << "foo: " << i << endl;
        pause_thread(1);
    }
}

void bar(int x)
{
    for (int i = 0; i < x; i++) {
        cout << "bar: " << i << endl;
        pause_thread(1);
    }
}

void renderingThread(sf::RenderWindow* window)
{
    while (window->isOpen()) {
        window->clear();

        for (vector<sf::Drawable*>::iterator drawable = drawables.begin(); drawable != drawables.end(); ++drawable) {
            window->draw(**drawable);
        }

        window->display();
    }
}

int main()
{
    thread first(foo);
    thread second(bar, 8);

    cout << "main, foo and bar now execute concurrently..." << endl;

    //first.join();
    //second.join();

    cout << "foo and bar completed." << endl;

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::CircleShape smallCircle(10.f);
    smallCircle.setFillColor(sf::Color::Red);
    smallCircle.setOrigin(10, 10);

    drawables.push_back(&shape);
    drawables.push_back(&smallCircle);

    sf::Clock clock;

    sf::Time t1 = clock.getElapsedTime();
    cout << t1.asMilliseconds() << endl;
    clock.restart();

    sf::Time t2 = clock.getElapsedTime();
    cout << t2.asMicroseconds() << endl;

    cout << clock.restart().asMicroseconds() << endl;

    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);

    window.setActive(false);

    thread renderThread(renderingThread, &window);

    int aPressed = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::Resized:
                    cout << "new width: " << event.size.width << endl;
                    cout << "new height: " << event.size.height << endl;
                    break;
                case sf::Event::TextEntered:
                    if (event.text.unicode < 128) {
                        cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << endl;
                    }
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::A) {
                        aPressed = clock.getElapsedTime().asMilliseconds();
                    }
                    break;
                case sf::Event::KeyReleased:
                    if (event.key.code == sf::Keyboard::A) {
                        cout << "A was pressed for " << clock.getElapsedTime().asMilliseconds() - aPressed << " milliseconds." << endl;
                    }
                    break;
                case sf::Event::LostFocus:
                    cout << "Paused!" << endl;
                    break;
                case sf::Event::GainedFocus:
                    cout << "Unpaused!" << endl;
                    break;
                case sf::Event::MouseWheelMoved:
                    cout << "wheel movement: " << event.mouseWheel.delta << endl;
                    cout << "mouse x: " << event.mouseWheel.x << endl;
                    cout << "mouse y: " << event.mouseWheel.y << endl;
                    break;
                case sf::Event::MouseMoved:
                    smallCircle.setPosition(event.mouseMove.x, event.mouseMove.y);
                    break;
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Right) {
                        cout << "RIGHT MOUSE!" << endl;
                    }
                    else if (event.mouseButton.button == sf::Mouse::Left) {
                        cout << "LEFT MOUSE!" << endl;
                    }
                    break;
                default:
                    break;
            }
        }
    }

    return 0;
}

