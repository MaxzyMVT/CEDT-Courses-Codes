package entity.counter;

import entity.base.Updatable;
import entity.container.Dish;
import logic.Player;

public class DishWasher extends Counter implements Updatable {
    public DishWasher() {
        super("Dish Washer");
    }

    @Override
    public void interact(Player p) {
        if(!isPlacedContentEmpty()) {
            super.interact(p);
        }
        else if(p.getHoldingItem() instanceof Dish dish && dish.isDirty()) {
            super.interact(p);
        }
    }

    @Override
    public void update() {
        if(getPlacedContent() instanceof Dish dish) {
            dish.clean(15);
        }
    }
}
