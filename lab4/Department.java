/*
Сотрудники и отделы.
Создайте сущность Сотрудник, которая описывается именем (в строковой форме) и отделом, в
котором сотрудник работает, причем у каждого отдела есть название и начальник, который
также является Сотрудником. Сотрудник может быть приведен к текстовой форме вида: “Имя
работает в отделе Название, начальник которого Имя”. В случае если сотрудник является
руководителем отдела, то текстовая форма должна быть “Имя начальник отдела Название”.
Необходимо выполнить следующие задачи:
1. Создать Сотрудников Петрова, Козлова, Сидорова работающих в отделе IT.
2. Сделать Козлова начальником IT отдела.
3. Вывести на экран текстовое представление всех трех Сотрудников (у всех троих должен
оказаться один и тот же отдел и начальник).

Сотрудники и отделы.
Измените решение, полученное в задаче 2.4 таким образом, чтобы имея ссылку на сотрудника,
можно было бы узнать список всех сотрудников этого отдела.
*/
import java.util.ArrayList;

public class Department {
    private ArrayList<String> workers = new ArrayList<>();
    private String departmentName;
    private String managerName;

    public Department(String name) {
        this.departmentName = name;
    }

    public void addWorker(String workerName) {
        workers.add(workerName);
    }

    public void assignManager(String name) {
        for (int i = 0; i < workers.size(); i++) {
            if (name.equals(workers.get(i))) {
                this.managerName = name;
                break;
            }
        }
    }

    public String checkEmployee(String name) {
        if (workers.isEmpty()) {
            return "В отделе нет сотрудников.";
        }
        StringBuilder employeeList = new StringBuilder(workers.get(0));
        boolean found = false;
        for (int i = 0; i < workers.size(); i++) {
            employeeList.append(", ").append(workers.get(i));
            if (name.equals(workers.get(i))) {
                found = true;
            }
        }
        if (found) {
            return "Список сотрудников департамента: " + employeeList + ".";
        } else {
            return "В данном отделе такого сотрудника нет, попробуйте проверить другой отдел.";
        }
    }

    public String toString() {
        StringBuilder employeeList = new StringBuilder(workers.get(0));
        for (int i = 1; i < workers.size(); i++) {
            employeeList.append(", ").append(workers.get(i));
        }

        return "Название департамента: "
                + departmentName
                + ". Начальник департамента: "
                + managerName
                + ". Список сотрудников департамента: "
                + employeeList
                + ".";
    }
}
