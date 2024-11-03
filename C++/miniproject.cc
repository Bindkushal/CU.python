#include <SFML/Graphics.hpp>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <algorithm>

class SnakeGame {
public:
    SnakeGame() {
        // Initialize the window
        window.create(sf::VideoMode(800, 600), "Snake Game");
        snake.push_front(sf::Vector2i(400, 300));
        direction = sf::Vector2i(10, 0);
        spawnFood();
        score = 0;
    }

    void run() {
        while (window.isOpen()) {
            processInput();
            update();
            render();
        }
    }

private:
    sf::RenderWindow window;
    std::deque<sf::Vector2i> snake;
    sf::Vector2i direction;
    sf::Vector2i food;
    int score;

    void processInput() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up && direction.y == 0)
                    direction = sf::Vector2i(0, -10);
                else if (event.key.code == sf::Keyboard::Down && direction.y == 0)
                    direction = sf::Vector2i(0, 10);
                else if (event.key.code == sf::Keyboard::Left && direction.x == 0)
                    direction = sf::Vector2i(-10, 0);
                else if (event.key.code == sf::Keyboard::Right && direction.x == 0)
                    direction = sf::Vector2i(10, 0);
            }
        }
    }

    void update() {
        sf::Vector2i newHead = snake.front() + direction;

        // Check for collision with food
        if (newHead == food) {
            snake.push_front(food);
            spawnFood();
            score++;
        } else {
            snake.push_front(newHead);
            snake.pop_back();
        }

        // Check for self-collision or out of bounds
        if (newHead.x < 0 || newHead.x >= 800 || newHead.y < 0 || newHead.y >= 600 ||
            std::find(snake.begin() + 1, snake.end(), newHead) != snake.end()) {
            window.close(); // Game over
        }
    }

    void render() {
        window.clear();

        // Draw the snake
        for (const auto& segment : snake) {
            sf::RectangleShape rectangle(sf::Vector2f(10, 10));
            rectangle.setPosition(segment.x, segment.y);
            rectangle.setFillColor(sf::Color::Green);
            window.draw(rectangle);
        }

        // Draw the food
        sf::RectangleShape foodRect(sf::Vector2f(10, 10));
        foodRect.setPosition(food.x, food.y);
        foodRect.setFillColor(sf::Color::Red);
        window.draw(foodRect);

        window.display();
    }

    void spawnFood() {
        food.x = (rand() % (800 / 10)) * 10;
        food.y = (rand() % (600 / 10)) * 10;
    }
};

int main() {
    srand(static_cast<unsigned>(time(0)));
    SnakeGame game;
    game.run();
    return 0;
}
