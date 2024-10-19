#include <iostream>
#include <string>

// Базовый класс "Транспортное Средство"
class Transport {
public:
    // Метод "Ехать"
    virtual void Drive() {
        std::cout << "Транспортное средство едет." << std::endl;
    }

    // Метод "Остановиться"
    virtual void Stop() {
        std::cout << "Транспортное средство остановилось." << std::endl;
    }

    // Виртуальный деструктор
    virtual ~Transport() {
        std::cout << "~Transport\n";
    }
};

// Производный класс "Автомобиль"
class Car : public Transport {
public:
    void Drive() override {
        std::cout << "Автомобиль едет." << std::endl;
    }

    void Stop() override {
        std::cout << "Автомобиль остановился." << std::endl;
    }

    ~Car() override {
        std::cout << "~Car\n";
    }

};

// Производный класс "Велосипед"
class Bicycle : public Transport {
public:
    void Drive() override {
        std::cout << "Велосипед едет." << std::endl;
    }

    void Stop() override {
        std::cout << "Велосипед остановился." << std::endl;
    }
    ~Bicycle() override {
        std::cout << "~Bicycle\n";
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    // Создаем объекты классов "Автомобиль" и "Велосипед"
    {
        Car car;
        //Bicycle bicycle;

        // Вызываем методы "Ехать" и "Остановиться" для "Автомобиля"
        car.Drive();
        car.Stop();

        // Вызываем методы "Ехать" и "Остановиться" для "Велосипеда"
        //bicycle.Drive();
        //bicycle.Stop();
    }
    return 0;
}