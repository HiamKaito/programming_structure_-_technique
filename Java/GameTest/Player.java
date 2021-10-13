package GameTest;

public class Player extends LivingEntity{
    float damage;
    ListGear list;

    public Player(String name, float hp, float damage) {
        list = new ListGear();
        super.name = name;
        super.hp = hp;
        this.damage = damage;
    }
    
    @Override
    public void takeDamage(float damage) {
        super.hp -= damage;
    }
    
    public float dealDamage() {
        float resDamage = damage;
        
        // damage plus from Gear
        resDamage += list.getTotalDamage();
        
        return resDamage;
    }
    
    public void addGear(Gear item) {
        list.add(item);
    }
    
    public void inforGear() {
        System.out.println("Player " + super.name + " have:");
        list.infor();
        System.out.println("End.");
    }
}
