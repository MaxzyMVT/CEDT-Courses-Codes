package entity.counter;

import entity.base.Container;
import entity.base.Ingredient;
import logic.Player;

public class Bin extends Counter {
    public Bin() {
        super("Bin");
    }

    @Override
    public void interact(Player p) {
        if(!p.isHandEmpty()) {
            if(p.getHoldingItem() instanceof Ingredient) {
                p.placeItem();
            }
            else if(p.getHoldingItem() instanceof Container c) {
                c.clearContent();
            }
        }
    }

}
