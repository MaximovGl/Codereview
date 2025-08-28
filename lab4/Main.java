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
                int seconds = validateIntInput();
                Time time1 = new Time(seconds);
                System.out.println("Введите время в секундах(целым числом):");
                seconds = validateIntInput();
                Time time2 = new Time(seconds);
                System.out.println("Введите время в секундах(целым числом):");
                seconds = validateIntInput();
                Time time3 = new Time(seconds);
                System.out.println(time1);
                System.out.println(time2);
                System.out.println(time3);
                break;
            case 2:
                System.out.println("Введите число этажей дома(целым положительным числом):");
                int floors = validateNonNegative(validateIntInput());
                House house1 = new House(floors);
                System.out.println("Введите число этажей дома(целым положительным числом):");
                floors = validateNonNegative(validateIntInput());
                House house2 = new House(floors);
                System.out.println("Введите число этажей дома(целым положительным числом):");
                floors = validateNonNegative(validateIntInput());
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
                itDepartment.addWorker(input);
                System.out.println("Введите имя сотрудника: ");
                input = scanner.next();
                itDepartment.addWorker(input);
                System.out.println("Введите имя сотрудника: ");
                input = scanner.next();
                itDepartment.addWorker(input);
                System.out.println("Введите имя начальника: ");
                input = scanner.next();
                itDepartment.assignManager(input);
                System.out.println(itDepartment);
                break;
            case 4:
                System.out.println("Введите название департамента:");
                input = scanner.next();
                Department tiDepartment = new Department(input);
                System.out.println("Введите имя сотрудника: ");
                input = scanner.next();
                tiDepartment.addWorker(input);
                System.out.println("Введите имя сотрудника: ");
                input = scanner.next();
                tiDepartment.addWorker(input);
                System.out.println("Введите имя сотрудника: ");
                input = scanner.next();
                tiDepartment.addWorker(input);
                System.out.println("Введите имя сотрудника: ");
                input = scanner.next();
                System.out.println(tiDepartment.checkEmployee(input));
                break;
            case 5:
                int Floors;
                System.out.println("Введите число этажей дома(целым положительным числом):");
                Floors = validateNonNegative(validateIntInput());
                House house4 = new House(Floors);
                System.out.println("Введите число этажей дома(целым положительным числом):");
                Floors = validateNonNegative(validateIntInput());
                House house5 = new House(Floors);
                System.out.println("Введите число этажей дома(целым положительным числом):");
                Floors = validateNonNegative(validateIntInput());
                House house6 = new House(Floors);
                System.out.println(house4);
                System.out.println(house5);
                System.out.println(house6);
                break;
            case 6:
                System.out.println(
                        "Введите количество патронов в пистолете(целым положительным числом):");
                int bullets = validateNonNegative(validateIntInput());
                Pistol pistol = new Pistol(bullets);
                System.out.println(
                        "Введите количество выстрелов из пистолета(целым положительным числом):");
                int shots = validateNonNegative(validateIntInput());
                pistol.shoot(shots);
                break;
        }
        scanner.close();
    }

    private static int validateIntInput() {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            scanner.close();
            return scanner.nextInt();
        } else {
            scanner.close();
            System.out.println("Вы ввели не целое число.");
            return 0;
        }

    }

    private static int validateNonNegative(int value) {
        if (value >= 0) {
            return value;
        } else {
            System.out.println("Вы ввели отрицательное число.");
            return 0;
        }
    }

    private static String validateStringInput() {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextLine()) {
            scanner.close();
            return scanner.nextLine();

        } else {
            scanner.close();
            System.out.println("Ошибка ввода строки.");
            return "";
        }
    }
}
