package logic;

import java.util.ArrayList;
import java.util.Random;

public class ShoppingCart {
	private int requiredUnitItems;
	private int requiredWeightItems;
	private int discount; // in percentage 1 - 100;
	
	private ArrayList<Item> items;
	
	public ShoppingCart() {
		// TODO Auto-generated constructor stub
		Random random = new Random();
		requiredUnitItems = 1 + random.nextInt(3);
		requiredWeightItems = 1 + random.nextInt(3);
		discount = 20;
		items = new ArrayList<Item>();
	}
	
	public void addItem(Item item)
	{
		switch (item) {
			case UnitItem ui -> {
				if (ui.getUnitPrice() > 0 && ui.getAmount() > 0) {
					getItems().add(ui);
				}
				else {
					System.out.println("Unable to add. Price and Amount should be greater than 0");
				}
			}
			case WeightItem wi -> {
				if (wi.getUnitPrice() > 0) {
					getItems().add(wi);
				}
				else  {
					System.out.println("Unable to add. Price should be more than $0");
				}
			}
			default -> {}
		}
	}
	
	public double checkOut(){
		double sumPrice = 0;
		for (Item item : getItems()){
			sumPrice += item.cost();
		}
		return sumPrice;
	}
	
	public boolean isDiscounted(){
		int numberOfUnitItems = 0;
		int numberOfWeightItems = 0;

		for (Item item : getItems()){
			if (item instanceof UnitItem) {
				numberOfUnitItems++;
			}
			else if (item instanceof WeightItem) {
				numberOfWeightItems++;
			}
		}

		return numberOfUnitItems >= getRequiredUnitItems() &&  numberOfWeightItems >= getRequiredWeightItems();
	}



	//Create Getter&Setter method for all private fields

	public int getRequiredUnitItems() {
		return requiredUnitItems;
	}

	public void setRequiredUnitItems(int requiredUnitItems) {
		this.requiredUnitItems = requiredUnitItems;
	}

	public int getRequiredWeightItems() {
		return requiredWeightItems;
	}

	public void setRequiredWeightItems(int requiredWeightItems) {
		this.requiredWeightItems = requiredWeightItems;
	}

	public int getDiscount() {
		return discount;
	}

	public void setDiscount(int discount) {
		this.discount = discount;
	}

	public ArrayList<Item> getItems() {
		return items;
	}
}
