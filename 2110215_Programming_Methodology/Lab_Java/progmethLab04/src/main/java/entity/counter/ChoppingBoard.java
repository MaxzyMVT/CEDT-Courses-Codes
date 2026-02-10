package entity.counter;

import entity.base.Choppable;
import entity.base.Ingredient;
import logic.Player;

public class ChoppingBoard extends Counter{
    public ChoppingBoard(){
        super("Chopping Board");
    }

    @Override
    public void interact(Player p) {
        if(!isPlacedContentEmpty()) {
            super.interact(p);
        }
        else if (p.getHoldingItem() instanceof Ingredient i) {
            super.interact(p);
            if(i instanceof Choppable ci) {
                ci.chop();
            }
        }
    }
}
