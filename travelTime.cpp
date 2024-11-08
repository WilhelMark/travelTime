#include <iostream>

int main()
{
    // Объявляем переменные для времени отправления и прибытия
    int depHours, depMinutes;
    int arrHours, arrMinutes;

    // Ввод времени отправления
    std::cout << "Введите время отправления (HH:MM): ";
    std::cin >> depHours;
    std::cin.ignore(); // Игнорируем символ ':'
    std::cin >> depMinutes;

    // Проверка корректности времени отправления
    while (depHours < 0 || depHours >= 24 || depMinutes < 0 || depMinutes >= 60)
    {
        std::cout << "Некорректный ввод. Пожалуйста, введите время в формате HH:MM: ";
        std::cin >> depHours;
        std::cin.ignore();
        std::cin >> depMinutes;
    }

    // Ввод времени прибытия
    std::cout << "Введите время прибытия (HH:MM): ";
    std::cin >> arrHours;
    std::cin.ignore(); // Игнорируем символ ':'
    std::cin >> arrMinutes;

    // Проверка корректности времени прибытия
    while (arrHours < 0 || arrHours >= 24 || arrMinutes < 0 || arrMinutes >= 60)
    {
        std::cout << "Некорректный ввод. Пожалуйста, введите время в формате HH:MM: ";
        std::cin >> arrHours;
        std::cin.ignore();
        std::cin >> arrMinutes;
    }

    // Переводим время в минуты
    int departureTimeInMinutes = depHours * 60 + depMinutes;
    int arrivalTimeInMinutes = arrHours * 60 + arrMinutes;

    /*
    // Если время отправления больше времени прибытия, добавляем сутки к времени прибытия
    if (arrivalTimeInMinutes < departureTimeInMinutes) {
        arrivalTimeInMinutes += 24 * 60; // Добавляем сутки в минуты
    }
    */

    // Используем тернарный оператор для вычисления
    arrivalTimeInMinutes += (arrivalTimeInMinutes < departureTimeInMinutes) ? (24 * 60) : 0;

    // Вычисляем время в пути
    int travelTimeInMinutes = arrivalTimeInMinutes - departureTimeInMinutes;

    // Преобразуем обратно в часы и минуты
    int hours = travelTimeInMinutes / 60;
    int minutes = travelTimeInMinutes % 60;

    // Выводим результат
    std::cout << "Поездка составила " << hours << " ч. " << minutes << " мин." << std::endl;

    return 0;
}
