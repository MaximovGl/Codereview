package ru.maximov.weaponry;

abstract class Weapon {
    protected int ammo;
    protected Weapon (int ammo) {
        if (ammo < 0) {
            System.out.println("Ошибка: количество патронов не может быть отрицательным");
            this.ammo = 0;
        } else {
            this.ammo = ammo;
        }
    }

    abstract void shoot ();
    public int ammo () { return ammo;}

    protected int load (int ammo,int maxbul) {
        if (ammo<0){
            System.out.println("Ошибка: количество патронов не может быть отрицательным");
            return 0;
        }
        if (maxbul<ammo){
            System.out.println(ammo-maxbul+" патронов не влезло в пистолет. Они возвращаются вам.");
            ammo=maxbul;
        }
        this.ammo=ammo;
        return ammo;
    }

    public int unload() {
        int currentAmmo = ammo;
        ammo = 0;
        return currentAmmo;
    }

    public boolean isLoaded() {
        return ammo > 0;
    }


}

