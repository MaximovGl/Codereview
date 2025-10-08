/*
Решение всех задач оформить в одном проекте, но в разных классах. В главном методе main показать
работу всех классов и методов с дружественным интерфейсом. Все исходные данные вводятся с
клавиатуры, организовать проверку на ввод. В каждом классе должны присутствовать свойства,
конструкторы и метод toString().
Необходимо решить задания согласно вашему варианту. Задачи из заданий 1-6 оцениваются по 0,8
баллов, задачи из заданий 7-8 – 0,6 балла. Максимально за лабораторную работу можно получить 10
баллов (8 баллов за решение задач + 2 балла за оформление отчета).
 */
package ru.maximov.main;

import ru.maximov.array.Ilov;
import ru.maximov.tree.Node;
import ru.maximov.geometry.Point;
import ru.maximov.houses.House;
import ru.maximov.mathoperations.Power;
import ru.maximov.weaponry.Machinegun;
import ru.maximov.weaponry.Pistol;
import ru.maximov.weaponry.Shooter;
import ru.maximov.validate.Validate;

import java.util.Arrays;
public class Main {
    public static void main(String[] args) {
        int firstNumber, secondNumber;
        int[] numberArray = {10, 20, 30, 40, 50};
        String inputString = "1,2,3,4,5";

        System.out.println("Выберите задание (1-8): ");
        firstNumber = Validate.intCheck();

        switch (firstNumber) {
            case 1:
                System.out.println("Введите число этажей дома:");
                firstNumber = Validate.positiveIntCheck();
                House house = new House(firstNumber);
                System.out.println(house.toString());
                break;

            case 2:
                System.out.println("Введите максимальное количество патронов, " +
                        "помещающихся в пистолет:");
                firstNumber = Validate.positiveIntCheck();
                Pistol pistol = new Pistol(firstNumber);

                System.out.println("Введите число патронов для зарядки:");
                firstNumber = Validate.positiveIntCheck();
                pistol.reload(firstNumber);

                System.out.println("Введите количество выстрелов:");
                firstNumber = Validate.positiveIntCheck();
                pistol.shoot(firstNumber);

                System.out.println("Введите число патронов для дополнительной зарядки:");
                firstNumber = Validate.positiveIntCheck();
                pistol.reload(firstNumber);

                System.out.println("Введите количество выстрелов:");
                firstNumber = Validate.positiveIntCheck();
                pistol.shoot(firstNumber);

                System.out.println("Введите количество выстрелов:");
                firstNumber = Validate.positiveIntCheck();
                pistol.shoot(firstNumber);

                pistol.reload(0);

                System.out.println("Введите количество выстрелов:");
                firstNumber = Validate.positiveIntCheck();
                pistol.shoot(firstNumber);
                break;

            case 3:
                Ilov numbersList = new Ilov(inputString);
                System.out.println("Введите индекс элемента для замены и его новое значение:");
                firstNumber = Validate.positiveIntCheck();
                secondNumber = Validate.positiveIntCheck();
                numbersList.set(firstNumber, secondNumber);

                System.out.println("Введите индекс элемента для просмотра:");
                firstNumber = Validate.positiveIntCheck();
                System.out.println("Значение элемента: " + numbersList.get(firstNumber));
                System.out.println("Текущий список: " + numbersList.toString());

                Ilov otherList = new Ilov(numberArray);
                System.out.println("Список пуст: " + otherList.isEmpty());
                System.out.println("Размер списка: " + otherList.size());
                System.out.println("Массив: " + Arrays.toString(otherList.toArray()));
                break;

            case 4:
                Machinegun machinegun1 = new Machinegun();
                System.out.println("Введите размер магазина автомата:");
                firstNumber = Validate.intCheck();
                Machinegun machinegun2 = new Machinegun(firstNumber);

                System.out.println("Введите размер магазина и скорострельность автомата:");
                firstNumber = Validate.intCheck();
                secondNumber = Validate.intCheck();
                Machinegun machinegun3 = new Machinegun(firstNumber, secondNumber);

                System.out.println("Введите продолжительность стрельбы из автомата в секундах:");
                firstNumber = Validate.intCheck();
                machinegun3.fire(firstNumber);

                System.out.println("Введите продолжительность стрельбы из автомата в секундах:");
                firstNumber = Validate.intCheck();
                machinegun2.fire(firstNumber);

                machinegun1.shoot();
                break;

            case 5:
                Node tree = new Node();
                tree.addValue(3);
                tree.addValue(5);
                tree.addValue(4);
                tree.addValue(7);
                tree.addValue(1);
                tree.addValue(2);
                System.out.println("Текстовое представление дерева: " + tree.toString());
                break;

            case 6:
                System.out.println("Введите имя стрелка:");
                inputString = Validate.strCheck();
                Shooter shooter1 = new Shooter(inputString);

                System.out.println("Введите имя стрелка:");
                inputString = Validate.strCheck();
                Shooter shooter2 = new Shooter(inputString);

                System.out.println("Введите размер обоймы пистолета:");
                firstNumber = Validate.positiveIntCheck();
                Pistol shooterWeapon2 = new Pistol(firstNumber);
                shooter2.setWeapon(shooterWeapon2);

                System.out.println("Введите имя стрелка:");
                inputString = Validate.strCheck();
                Shooter shooter3 = new Shooter(inputString);

                System.out.println("Введите размер обоймы автомата и его скорострельность:");
                firstNumber = Validate.positiveIntCheck();
                secondNumber = Validate.positiveIntCheck();
                Machinegun shooterWeapon3 = new Machinegun(firstNumber, secondNumber);
                shooter3.setWeapon(shooterWeapon3);

                shooter1.shoot();
                shooter2.shoot();
                shooter3.shoot();
                System.out.println();
                break;

            case 7:
                System.out.println("Введите координаты первой точки:");
                firstNumber = Validate.intCheck();
                secondNumber = Validate.intCheck();
                Point point1 = new Point(firstNumber, secondNumber);

                System.out.println("Введите координаты второй точки:");
                firstNumber = Validate.intCheck();
                secondNumber = Validate.intCheck();
                Point point2 = new Point(firstNumber, secondNumber);

                System.out.println("Утверждение о том, что первая и вторая точки " +
                        "имеют одинаковые координаты является: " +
                        point1.equals(point2));
                break;

            default:
                System.out.println("Неверный номер задания. Выберите от 1 до 7.");
                break;
        }
    }
}