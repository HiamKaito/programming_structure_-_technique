public class Sword extends Gear {

    public Sword(String name, float price, float damage) {
        super.name = name;
        super.price = price;
        super.damage = damage;
    }

    public float getDamage() {
        return damage;
    }

    public void setDamage(float damage) {
        this.damage = damage;
    }

    @Override
    public void infor() {
        System.out.println(super.name + " " + super.price + " " + damage);
    }
}
