package GameTest;

import java.util.ArrayList;
import java.util.List;

public class ListGear {
    List<Gear> listGear;

    public ListGear() {
        listGear = new ArrayList<>();
    }
    
    public void add(Gear item) {
        listGear.add(item);
    }
    
    public void infor() {
        for (Gear item : listGear) {
            item.infor();
        }
    }
    
    public float getTotalDamage() {
        float res = 0;
        for (Gear item : listGear) {
            res += item.damage;
        }
        return res;
    }
}
