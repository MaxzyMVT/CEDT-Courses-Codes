package entity.ingredient;

import entity.base.Choppable;
import entity.base.Cookable;
import entity.base.Ingredient;
import logic.StringUtil;

public class Meat extends Ingredient implements Choppable, Cookable {
    private boolean chopState;
    private int cookedPercentage;

    public Meat() {
        super("Meat");
        chopState = false;
        setCookedPercentage(0);
    }

    public void chop() {
        if (!isChopped()) {
            chopState = true;
            setName("Minced Meat");
        }
    }

    public boolean isChopped() {
        return chopState;
    }

    public void cook() {
        int p = getCookedPercentage();
        boolean edible = false;
        String name;

        if (isChopped()) {
            setCookedPercentage(p += 15);
            edible = (p > 80 && p <= 100);
            name =
                    p > 100 ? "Burnt Burger" :
                    p > 80 ? "Cooked Burger" : "Raw Burger";
        }
        else {
            setCookedPercentage(p += 10);
            edible = (p > 50 && p <= 100);
            name =
                    p > 100 ? "Burnt Steak" :
                    p > 80 ? "Well Done Steak" :
                    p > 50 ? "Medium Rare Steak" : "Raw Meat";
        }

        setName(name);
        setEdible(edible);
    }

    public boolean isBurnt() {
        return getCookedPercentage() > 100;
    }

    public int getCookedPercentage() {
        return cookedPercentage;
    }

    public void setCookedPercentage(int cookedPercentage) {
        this.cookedPercentage = cookedPercentage;
    }

    @Override
    public String toString() {
        return StringUtil.formatNamePercentage(getName(), getCookedPercentage());
    }

    private boolean isEdible(int lower_bound, int upper_bound) {
        int p = getCookedPercentage();
        return p >= lower_bound && p <= upper_bound;
    }
}
