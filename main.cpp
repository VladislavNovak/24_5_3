#include <windows.h>
#include <iostream>
#include <ctime>   // для работы со временем
#include <iomanip>

using std::cout;
using std::endl;
using std::string;

void timer1(int delay) {
    cout << "Отсчет пошёл:" << endl;
    while(delay) {
        Sleep(1000);
        --delay;
        time_t now = time(nullptr);
        std::tm* local = localtime(&now);
        cout << "Осталось " << delay << " секунд ";
        cout << "(" << std::put_time(local, "%M:%S") << ")" << endl;
    }

    cout << "DING! DING! DING!" << endl;
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int minutes{0};
    int seconds{0};
    cout << "Введите количество минут (либо 0): ";
    std::cin >> minutes;
    cout << "Введите количество секунд (либо 0): ";
    std::cin >> seconds;

    timer1(minutes * 60 + seconds);

    return 0;
}
