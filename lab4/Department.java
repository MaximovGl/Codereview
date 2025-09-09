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
    private ArrayList<Worker> workers;
    private String departmentName;
    private Worker manager;

    public Department(String name, Worker manager) {
        this.workers = new ArrayList<>();
        this.departmentName = name;
        setManager(manager);
    }

    public Department(String name) {
        this.workers = new ArrayList<>();
        this.departmentName = name;
    }

    public String getName() {
        return departmentName;
    }

    public String getManagerName() {
        return manager.getName();
    }

    public void setName(String name) {
        this.departmentName = name;
    }

    public void setManager(Worker manager) {
        this.manager = manager;
        if (!workers.contains(manager)) {
            manager.assignToDepartment(this);
        }
    }

    public void addWorker(Worker worker) {
        workers.add(worker);
    }

    public boolean isManager(Worker worker) {
        return worker.equals(manager);
    }

    public String toString() {
        if (!workers.isEmpty()) {
            StringBuilder employeeList = new StringBuilder(workers.get(0).getName());
            for (int i = 1; i < workers.size(); i++) {
                employeeList.append(", ").append(workers.get(i).getName());
            }

            return "Название департамента: "
                    + departmentName
                    + ". Начальник департамента: "
                    + manager.getName()
                    + ". Список сотрудников департамента: "
                    + employeeList
                    + ".";
        }
        else
            return "Название департамента: "
                    + departmentName
                    + ". Начальник департамента: "
                    + manager.getName()
                    + ". Список сотрудников департамента: "
                    + ".";
    }
}
