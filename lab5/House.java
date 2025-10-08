package ru.maximov.houses;

/*
Дом над землей.
Измените сущность Дом из задачи 1.4.3. Гарантируйте, что у дома всегда будет положительное
количество этажей. В случае попытки указать отрицательное количество этажей должна
выбрасываться соответствующая ошибка. Продемонстрируйте работоспособность решения на
примерах.
*/

public class House {
    private final int floors;

    public House(int floors) {
        if (floors <= 0) {
            System.out.println("Ошибка: количество этажей должно быть положительным числом. Передано: " + floors);
            this.floors = 1;
        } else {
            this.floors = floors;
        }
    }

    public String toString() {
        if (floors % 10 == 1 && floors % 100 != 11) {
            return "Дом с " + floors + " этажем";
        } else {
            return "Дом с " + floors + " этажами";
        }
    }
}
