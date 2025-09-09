/*
Решение всех задач оформить в одном проекте, но в разных классах. В главном методе main показать
работу всех классов и методов с дружественным интерфейсом. Если исходные данные вводятся с
клавиатуры, то организовать проверку на ввод. В каждом классе должны присутствовать свойства,
конструкторы и метод toString().
Необходимо решить задания согласно вашему варианту. Задания 1, 2 и 4 оцениваются по 1 баллу,
задание 3 и 5  - 2 балла. Максимально за лабораторную работу можно получить 10 баллов (8 баллов за
решение задач + 2 балла за оформление отчета).
*/

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int choice;
        String input;

        System.out.println("Выберите задание: ");
        choice = scanner.nextInt();

        switch (choice) {
            case 1:
                System.out.println("Введите время в секундах(целым числом):");
                int seconds = Validate.intInput();
                Time time1 = new Time(seconds);
                System.out.println("Введите время в секундах(целым числом):");
                seconds = Validate.intInput();
                Time time2 = new Time(seconds);
                System.out.println("Введите время в секундах(целым числом):");
                seconds = Validate.intInput();
                Time time3 = new Time(seconds);
                System.out.println(time1);
                System.out.println(time2);
                System.out.println(time3);
                break;
            case 2:
                System.out.println("Введите число этажей дома(целым положительным числом):");
                int floors = Validate.nonNegative(Validate.intInput());
                House house1 = new House(floors);
                System.out.println("Введите число этажей дома(целым положительным числом):");
                floors = Validate.nonNegative(Validate.intInput());
                House house2 = new House(floors);
                System.out.println("Введите число этажей дома(целым положительным числом):");
                floors = Validate.nonNegative(Validate.intInput());
                House house3 = new House(floors);
                System.out.println(house1);
                System.out.println(house2);
                System.out.println(house3);
                break;
            case 3:
                System.out.println("Введите название департамента:");
                input = scanner.next();
                Department itDepartment = new Department(input);
                System.out.println("Введите имя сотрудника: ");
                input = scanner.next();
                Worker first = new Worker(input, itDepartment);
                System.out.println("Введите имя сотрудника: ");
                input = scanner.next();
                Worker second = new Worker(input, itDepartment);
                System.out.println("Введите имя сотрудника: ");
                input = scanner.next();
                Worker third = new Worker(input, itDepartment);
                System.out.println("Введите имя начальника: ");
                itDepartment.setManager(third);
                System.out.println(itDepartment.toString());
                break;
            case 6:
                System.out.println(
                        "Введите количество патронов в пистолете(целым положительным числом):");
                int bullets = Validate.nonNegative(Validate.intInput());
                Pistol pistol = new Pistol(bullets);
                System.out.println(
                        "Введите количество выстрелов из пистолета(целым положительным числом):");
                int shots = Validate.nonNegative(Validate.intInput());
                pistol.shoot(shots);
                break;
        }
        scanner.close();
    }
}
