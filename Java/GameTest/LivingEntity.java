package GameTest;

public abstract class LivingEntity {
    protected String name;
    protected float hp;
    
    public abstract void takeDamage(float damage);
    
    public void infor() {
        System.out.println("Name: " + name + ",HP: " + hp);
    }
}
