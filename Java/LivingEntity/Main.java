public class Main {

    public static void main(String[] args) {
        Player Hiam = new Player("HiamKaito", 10.0f, 5.5f);
        Enemy UnNameFrog = new Enemy("Frog ", 50.0f);

        Hiam.infor();
        UnNameFrog.infor();

        System.out.println("Player attack");
        UnNameFrog.takeDamage(Hiam.dealDamage());

        Hiam.infor();
        UnNameFrog.infor();

        System.out.println("Create gear sword");
        Sword sword1 = new Sword("Diamond Sword", 15f, 3.5f);
        Sword sword2 = new Sword("Gold Sword", 30f, 0.5f);
        Hiam.addGear(sword1);
        Hiam.addGear(sword2);

        System.out.println("Hiam has equip gear");
        Hiam.inforGear();

        System.out.println("Player attack");
        UnNameFrog.takeDamage(Hiam.dealDamage());

        Hiam.infor();
        UnNameFrog.infor();
    }
}
