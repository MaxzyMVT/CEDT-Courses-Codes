package logic;

public class UnitItem extends Item {
    private int amount;


    public UnitItem(String name, double unitPrice, int amount) {
        setName(name);
        setUnitPrice(unitPrice);
        setAmount(amount);
    }

    @Override
    public double cost() {
        return getUnitPrice() * getAmount();
    }

    @Override public String toString() {
        return "UnitItem\t:\t" + getName() + "\t\t" +  getAmount() + "\t\t$" + getUnitPrice() + "\t\t$" + cost();
    }

    public int getAmount() {
        return amount;
    }

    public void setAmount(int amount) {
        this.amount = amount;
    }
}
