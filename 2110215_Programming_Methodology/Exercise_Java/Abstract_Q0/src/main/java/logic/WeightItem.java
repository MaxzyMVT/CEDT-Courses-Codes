package logic;

public class WeightItem extends Item {

    private double weight;

    public WeightItem(String name, double unitPrice) {
        setName(name);
        setUnitPrice(unitPrice);
        setWeight(scale());
    }

    @Override
    public double cost() {
        return getUnitPrice() * getWeight();
    }

    public double scale() {
        return Math.round((Math.random() * 3.99 + 0.01) * 100.0) / 100.0; // 0.01 - 4.00
    }

    @Override
    public String toString() {
        return "WeightItem\t:\t" + getName() + "\t\t" + getWeight() + "\t\t$" + getUnitPrice() + "\t\t$" + cost();
    }

    public double getWeight() {
        return weight;
    }

    public void setWeight(double weight) {
        this.weight = weight;
    }
}
