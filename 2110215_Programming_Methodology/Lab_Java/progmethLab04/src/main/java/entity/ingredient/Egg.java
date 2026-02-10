package entity.ingredient;

import entity.base.Cookable;
import entity.base.Ingredient;
import logic.StringUtil;

public class Egg extends Ingredient implements Cookable {
    private int cookedPercentage;

    public Egg() {
        super("Egg");
        setCookedPercentage(0);
    }

    public void cook() {
        int p = getCookedPercentage();
        setCookedPercentage(p += 12);

        boolean edible = (p > 50 && p <= 100);
        String name =
                p > 100 ? "Burnt Egg" :
                p > 80 ? "Fried Egg" :
                p > 50 ? "Sunny Side Egg" : "Raw Egg";

        setName(name);
        setEdible(edible);
    }

    public boolean isBurnt() {
        return getCookedPercentage() > 100;
    }

    @Override
    public String toString() {
        return StringUtil.formatNamePercentage(getName(), getCookedPercentage());
    }

    public int getCookedPercentage() {
        return cookedPercentage;
    }

    public void setCookedPercentage(int cookedPercentage) {
        this.cookedPercentage = cookedPercentage;
    }
}
