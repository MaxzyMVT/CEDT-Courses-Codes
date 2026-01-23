package logic;

import java.util.ArrayList;

public class OrderItem {
    Item item;
    int itemAmount;

    public OrderItem(Item item, int itemAmount) {
        setItem(item);
        setItemAmount(itemAmount);
    }

    public Item getItem() {
        return item;
    }

    public void setItem(Item item) {
        this.item = item;
    }

    public int getItemAmount() {
        return itemAmount;
    }

    public void setItemAmount(int itemAmount) {
        this.itemAmount = Math.max(itemAmount, 0);
    }

    public int calculateTotalPrice() {
        return  itemAmount * item.getPricePerPiece();
    }

    public void increaseItemAmount(int amount) {
        if (amount > 0) {
            itemAmount += amount;
        }
    }
}
