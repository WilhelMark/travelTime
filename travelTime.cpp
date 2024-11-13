#include <iostream>

int main() {
    // Объявляем переменные для времени отправления и прибытия
    int depHours, depMinutes;
    int arrHours, arrMinutes;
    std::string depTime, arrTime;

    // Ввод времени отправления с обработкой
    while (true) {
        std::cout << "Введите время отправления (HH:MM или HH MM): ";
        std::getline(std::cin, depTime); // Читаем строку целиком

        // Проверяем формат времени
        if ((depTime.length() == 5 && depTime[2] == ':') || 
            (depTime.length() == 5 && depTime[2] == ' ')) {
            // Извлекаем часы и минуты
            depHours = (depTime[0] - '0') * 10 + (depTime[1] - '0'); // Часы
            depMinutes = (depTime[3] - '0') * 10 + (depTime[4] - '0'); // Минуты

            // Проверяем диапазон часов и минут
            if (depHours >= 0 && depHours < 24 && depMinutes >= 0 && depMinutes < 60) {
                break; // Ввод корректен, выходим из цикла
            }
        }

        std::cout << "Некорректный ввод. Пожалуйста, введите время в формате HH:MM или HH MM." << std::endl;
    }

    // Ввод времени прибытия с обработкой
    while (true) {
        std::cout << "Введите время прибытия (HH:MM или HH MM): ";
        std::getline(std::cin, arrTime); // Читаем строку целиком

        // Проверяем формат времени
        if ((arrTime.length() == 5 && arrTime[2] == ':') || 
            (arrTime.length() == 5 && arrTime[2] == ' ')) {
            // Извлекаем часы и минуты
            arrHours = (arrTime[0] - '0') * 10 + (arrTime[1] - '0'); // Часы
            arrMinutes = (arrTime[3] - '0') * 10 + (arrTime[4] - '0'); // Минуты

            // Проверяем диапазон часов и минут
            if (arrHours >= 0 && arrHours < 24 && arrMinutes >= 0 && arrMinutes < 60) {
                break; // Ввод корректен, выходим из цикла
            }
        }

        std::cout << "Некорректный ввод. Пожалуйста, введите время в формате HH:MM или HH MM." << std::endl;
    }

    // Переводим время в минуты
    int departureTimeInMinutes = depHours * 60 + depMinutes;
    int arrivalTimeInMinutes = arrHours * 60 + arrMinutes;

    // Если время отправления больше времени прибытия, добавляем сутки к времени прибытия
    if (arrivalTimeInMinutes < departureTimeInMinutes) {
        arrivalTimeInMinutes += 24 * 60; // Добавляем сутки в минуты
    }

    // Вычисляем время в пути
    int travelTimeInMinutes = arrivalTimeInMinutes - departureTimeInMinutes;

    // Преобразуем обратно в часы и минуты
    int hours = travelTimeInMinutes / 60;
    int minutes = travelTimeInMinutes % 60;

    // Выводим результат
    std::cout << "Поездка составила " << hours << " ч. " << minutes << " мин." << std::endl;

    return 0;
}
