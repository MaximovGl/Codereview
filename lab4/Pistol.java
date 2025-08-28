/*
Пистолет стреляет.
 Создайте сущность Пистолет, которая описывается следующим образом:
 Имеет Количество патронов (целое число)
 Может быть создан с указанием начального количества патронов
 Может быть создан без указания начального количества патронов, в этом случае он
изначально заряжен пятью патронами.
 Может Стрелять, что приводит к выводу на экран текста “Бах!” в том случае, если
количество патронов больше нуля, иначе делает “Клац!”. После каждого выстрела (когда
вывелся “Бах!”) количество патронов уменьшается на один.
Создайте пистолет с тремя патронами и выстрелите из него пять раз.
*/
public class Pistol {
    private int bulletsCount;

    public Pistol(int bullets) {
        this.bulletsCount = bullets;
    }

    public Pistol() {
        this.bulletsCount = 5;
    }

    public void shoot(int shots) {
        while (this.bulletsCount > 0 && shots > 0) {
            System.out.println("Бах!");
            this.bulletsCount = this.bulletsCount - 1;
            shots = shots - 1;
        }
        while (shots > 0) {
            System.out.println("Клац!");
            shots = shots - 1;
        }
    }

    public String toString() {
        return "Количество оставшихся патронов: " + bulletsCount + ".";
    }
}
