import java.util.Scanner;

public class Validate {
    static Scanner scanner = new Scanner(System.in);
    public static int intInput() {
        if (scanner.hasNextInt()) {
            return scanner.nextInt();
        } else {
            System.out.println("Вы ввели не целое число.");
            return 0;
        }
    }

    public static int nonNegative(int value) {
        if (value >= 0) {
            return value;
        } else {
            System.out.println("Вы ввели отрицательное число.");
            return 0;
        }
    }

    private static String stringInput() {
        if (scanner.hasNextLine()) {
            return scanner.nextLine();

        } else {
            System.out.println("Ошибка ввода строки.");
            return "";
        }
    }
}
