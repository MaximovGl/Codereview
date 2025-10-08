package ru.maximov.validate;

import java.util.Scanner;

public class Validate {
    static Scanner in = new Scanner(System.in);

    public static int intCheck() {
        while (!in.hasNextInt()) {
            System.out.println("Вы ввели не целое число. Попробуйте снова:");
            in.next();
        }
        return in.nextInt();
    }

    public static String strCheck() {
        while (!in.hasNextLine()) {
            System.out.println("Ошибка ввода. Попробуйте снова:");
            in.next();
        }
        return in.nextLine();
    }

    public static int positiveIntCheck() {
        int value;
        do {
            value = intCheck();
            if (value < 0) {
                System.out.println("Число должно быть положительным. Попробуйте снова:");
            }
        } while (value < 0);
        return value;
    }
}
