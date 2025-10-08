package ru.maximov.weaponry;

public class Shooter {
    protected String name;
    protected Weapon weapon;

    public Shooter(String name){
        this.name=name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setWeapon(Weapon Weapon) {
        this.weapon = Weapon;
    }

    public void shoot(){
        if (weapon==null){
            System.out.println("Не могу участвовать в перестрелке");
        }
        else{
            weapon.shoot();
        }
    }
    public String toString(){
        if (weapon == null) {
            return "Имя стрелка: " + name + ". Оружие: отсутствует.";
        } else {
            return "Имя стрелка: " + name + ". Оружие: " + weapon.toString() + ".";
        }
    }
}