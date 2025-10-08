package ru.maximov.array;
/*
Необходимо разработать сущность НеизменяемыйСписокЗначений, представляющий собой
обертку над массивом целых чисел, который сохранит функциональные возможности массивов,
но добавит некоторые дополнительные возможности.
Состояние сущности описывают следующие сведения:
 Имеет массив целых чисел. Именно он используется для хранения значений.
Инициализация сущности может быть выполнена следующим образом:
 С указанием значений в виде массива целых чисел.
 С указанием перечня чисел как независимых значений (через запятую)
 С указанием другого Списка, в этом случае копируются все значения указанного списка.
Поведение сущности описывают следующие действия:
 Получение значения из позицииN. Позиция должна попадать в диапазон от 0 до N-1, где
N–текущее количество значений, иначе выкинуть ошибку.
 Замена значения в позиции N на новое значение. Позиция должна попадать в диапазон от
0 до N-1, где N–текущее количество значений, иначе выкинуть ошибку.
 Может быть приведен к строке. Строка должна представлять собой полный перечень всех
хранимых чисел, причем первый символ строки это ”[“, а последний “]”.
 Можно проверить пуст Список или нет. Список пуст если его размер 0.
 Можно узнать текущий размер.
 Все хранящиеся значения можно запросить в виде стандартного массива.
Продемонстрируйте работоспособность решения на примерах.
*/
public class Ilov {
    private final int[] values;

    public Ilov(int... values) {
        if (values == null) {
            System.out.println("Ошибка: передан null массив");
            this.values = new int[0];
        } else {
            this.values = new int[values.length];
            System.arraycopy(values, 0, this.values, 0, values.length);
        }
    }

    public Ilov(Ilov other) {
        if (other == null) {
            System.out.println("Ошибка: передан null объект");
            this.values = new int[0];
        } else {
            this.values = new int[other.values.length];
            System.arraycopy(other.values, 0, this.values, 0, other.values.length);
        }
    }

    public Ilov(String numbers) {
        if (numbers == null || numbers.trim().isEmpty()) {
            this.values = new int[0];
            return;
        }

        String[] parts = numbers.split(",");
        this.values = new int[parts.length];

        for (int i = 0; i < parts.length; i++) {
            try {
                this.values[i] = Integer.parseInt(parts[i].trim());
            } catch (NumberFormatException e) {
                System.out.println("Ошибка: неверный формат числа - " + parts[i]);
                this.values[i] = 0; // Устанавливаем значение по умолчанию
            }
        }
    }

    public int get(int index) {
        if (index < 0 || index >= values.length) {
            System.out.println("Ошибка: индекс " + index + " вне диапазона [0, " + (values.length - 1) + "]");
            return 0;
        }
        return values[index];
    }

    public void set(int index, int value) {
        if (index < 0 || index >= values.length) {
            System.out.println("Ошибка: индекс " + index + " вне диапазона [0, " + (values.length - 1) + "]");
        }
        else
            values[index] = value;
    }

    public boolean isEmpty() {
        return values.length == 0;
    }

    public int size() {
        return values.length;
    }

    public int[] toArray() {
        int[] copy = new int[values.length];
        System.arraycopy(values, 0, copy, 0, values.length);
        return copy;
    }

    @Override
    public String toString() {
        if (values.length == 0) {
            return "[]";
        }

        StringBuilder sb = new StringBuilder("[");
        for (int i = 0; i < values.length; i++) {
            sb.append(values[i]);
            if (i < values.length - 1) {
                sb.append(", ");
            }
        }
        sb.append("]");
        return sb.toString();
    }
}