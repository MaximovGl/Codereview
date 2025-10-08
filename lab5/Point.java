package ru.maximov.geometry;
/*
Сравнение точек.
Измените сущность Точка из задачи 1.4.1. Переопределите метод сравнения объектов по
состоянию таким образом, чтобы две точки считались одинаковыми тогда, когда они
расположены в одинаковых координатах.
*/
public class Point {
    private final int x,y;

    public Point(int x, int y){
        this.x=x;
        this.y=y;
    }
    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }

        if (obj == null || getClass() != obj.getClass()) {
            return false;
        }
        Point point = (Point) obj;
        return x==point.x && y == point.y;
    }
    public String toString() {
        return ("X:"+x+"Y:"+y);
    }
}