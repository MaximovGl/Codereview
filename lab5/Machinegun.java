package ru.maximov.weaponry;

public class Machinegun extends Pistol {
    protected final int rateoffire;

    public Machinegun() {
        super(30);
        this.rateoffire = 30;
        this.ammo = this.maxbul; 
    }

    public Machinegun(int maxbul) {
        super(maxbul);
        this.rateoffire = Math.max(1, maxbul / 2);
        this.ammo = this.maxbul; 
    }

    public Machinegun(int maxbul, int rateoffire) {
        super(maxbul);
        this.rateoffire = rateoffire > 0 ? rateoffire : 1;
        this.ammo = this.maxbul; 
    }

    public void shoot(){
        for (int i=0;i<rateoffire;i++){
            if (ammo==0){
                System.out.println("Клац!");
            }
            else {
                System.out.println("Бах!");
                ammo=ammo-1;
            }
        }
    }
    public void fire(int sec){
        for (int i=0;i<rateoffire*sec;i++){
            if (ammo==0){
                System.out.println("Клац!");
            }
            else {
                System.out.println("Бах!");
                ammo=ammo-1;
            }
        }
    }
    @Override
    public String toString() {
        return ("Максимальное колличество патронов: "+ maxbul+". "+"Колличество оставшихся патронов: " + ammo + ". Скорострельность: " + rateoffire+ ".");
    }

}
