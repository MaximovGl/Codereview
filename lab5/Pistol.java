package ru.maximov.weaponry;

public class Pistol extends Weapon {
    protected int maxbul;


    public Pistol(int maxbul){
        super(maxbul);
        this.maxbul=maxbul;
    }
    public Pistol() {
        super(5);
        this.maxbul=5;
    }

    @Override
    protected void shoot(){
        if (ammo > 0){
            System.out.println("Бах!");
            ammo = ammo - 1;
        }
        else
            System.out.println("Клац!");
    }

    public void shoot(int sh) {
        while (sh > 0) {
            shoot();
            sh = sh - 1;
        }
    }
    public void reload(int ammo){
        load(ammo,maxbul);
    }
    public int unload() {
        return super.unload(); 
    }

    public boolean isLoaded() {
        return super.isLoaded(); 
    }

    public int getMaxCapacity() {
        return maxbul;
    }

    public String toString() {
        return ("Максимальное колличество патронов: "+ maxbul+". "+"Колличество оставшихся патронов: " + ammo + ".");
    }

}


