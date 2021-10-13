package GameTest;

public class Enemy extends LivingEntity {

    public Enemy(String name, float hp) {
        super.name = name;
        super.hp = hp;
    }

    @Override
    public void takeDamage(float damage) {
        super.hp -= damage;
    }

}
