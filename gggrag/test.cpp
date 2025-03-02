#include <iostream>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int getch() {
    termios oldt, newt;
    int ch;
    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
    return ch;
}

bool kbhit() {
    termios oldt, newt;
    int bytesWaiting;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ioctl(STDIN_FILENO, FIONREAD, &bytesWaiting);
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return bytesWaiting > 0;
}

const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
vector<pair<int, int>> snake;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void Setup() {
    srand(time(0));
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    snake.push_back({x, y});
    score = 0;
}

void Draw() {
    system("clear");
    for (int i = 0; i < width + 2; i++) cout << "#";
    cout << endl;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) cout << "#";
            if (i == y && j == x)
                cout << "O";
            else if (i == fruitY && j == fruitX)
                cout << "F";
            else {
                bool print = false;
                for (auto s : snake) {
                    if (s.first == j && s.second == i) {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print) cout << " ";
            }
            if (j == width - 1) cout << "#";
        }
        cout << endl;
    }
    for (int i = 0; i < width + 2; i++) cout << "#";
    cout << endl;
    cout << "Score: " << score << endl;
}

void Input() {
    if (kbhit()) {
        switch (getch()) {
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
                exit(0);
        }
    }
}

void Logic() {
    int prevX = snake[0].first;
    int prevY = snake[0].second;
    int prev2X, prev2Y;
    snake[0] = {x, y};
    for (size_t i = 1; i < snake.size(); i++) {
        prev2X = snake[i].first;
        prev2Y = snake[i].second;
        snake[i] = {prevX, prevY};
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir) {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
    }
    if (x >= width) x = 0; else if (x < 0) x = width - 1;
    if (y >= height) y = 0; else if (y < 0) y = height - 1;
    for (size_t i = 1; i < snake.size(); i++) {
        if (snake[i].first == x && snake[i].second == y) {
            cout << "Game Over!" << endl;
            exit(0);
        }
    }
    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        snake.push_back({x, y});
    }
}

int main() {
    Setup();
    while (true) {
        Draw();
        Input();
        Logic();
        usleep(100000);
    }
    return 0;
}