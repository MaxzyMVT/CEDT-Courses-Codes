package logic;

import java.util.ArrayList;
import java.util.Scanner;

public class GroceryStore {

	public static Scanner in;
	public static ShoppingCart cart;

	public static void main(String[] args) throws InterruptedException {
		String command;
		in = new Scanner(System.in);
		cart = new ShoppingCart();

		viewPromotion();

		while (true) {
			showMenu();
			command = in.nextLine();

			switch (command) {
			case "U":
				addUnitItemMenu();
				break;
			case "W":
				addWeightItemMenu();
				break;
			case "V":
				viewAllItemMenu();
				break;
			case "":
				checkOutMenu();
				System.exit(0);
				break;
			default:
				System.out.println("Invalid command.");
				break;
			}

			/*
			if (command.equals("U"))
			{
				addUnitItemMenu();
			}
			else if (command.equals("W"))
			{
				addWeightItemMenu();
			}
			else if (command.equals("V"))
			{
				viewAllItemMenu();
			}
			else if (command.equals(""))
			{
				checkOutMenu();
				System.exit(0);
			}
			else
			{
				System.out.println("Invalid command.");
			}
			*/
		}
	}

	public static void showMenu() {
		// TODO Auto-generated method stub
		System.out.println("----------------------------------------");
		System.out.println("Grocery Store Menu");
		System.out.println("----------------------------------------");
		System.out.println("U)\tAdd Unit item to shopping cart");
		System.out.println("W)\tAdd Weight item to shopping cart");
		System.out.println("V)\tView all items in shopping cart");
		System.out.println("Enter)\tCheck out your shopping cart");
		System.out.println("----------------------------------------");
		System.out.print("Enter input command : ");
	}

	public static void addWeightItemMenu() {
		// TODO Auto-generated method stub
		String name;
		double unitPrice;

		System.out.println("----------------------------------------");
		System.out.println("Add Weight item to shopping cart");
		System.out.println("----------------------------------------");

		//fill code
		System.out.print("Enter name : ");
		name = in.nextLine();

		for (Item item : cart.getItems()) {
			if (item instanceof WeightItem weightItem && weightItem.getName().equals(name)) {
				double weight = weightItem.scale();
				System.out.println("Weight is " + weight);
				System.out.println("Total weight of " + name + " is " + (weight + weightItem.getWeight()) + " (Previous is " + weightItem.getWeight() + ")");
				weightItem.setWeight(weight + weightItem.getWeight());

				System.out.println("Cost is $" + weightItem.cost() + " (Price per kilogram is $" + weightItem.getUnitPrice() + ")");
				return;
			}
		}

		System.out.print("Enter price per kilogram : ");
		while(true) {
			try {
				unitPrice = Double.parseDouble(in.nextLine());
				break;
			} catch (NumberFormatException e) {
				System.out.println("Invalid input.");
			}
		}
		WeightItem weightItem = new WeightItem(name, unitPrice);

		System.out.println("Weight is " + weightItem.getWeight());
		System.out.println("Cost is $" + weightItem.cost());
		cart.addItem(weightItem);
	}

	public static void addUnitItemMenu() {
		// TODO Auto-generated method stub
		String name;
		int amount;
		double unitPrice;

		System.out.println("----------------------------------------");
		System.out.println("Add Unit item to shopping cart");
		System.out.println("----------------------------------------");

		//fill code
		System.out.print("Enter name : ");
		name = in.nextLine();

		System.out.print("Number of Units : ");
		while(true) {
			try {
				amount = Integer.parseInt(in.nextLine());
				break;
			}
			catch (NumberFormatException e) {
				System.out.println("Invalid input.");
			}
		}

		for (Item item : cart.getItems()) {
			if (item instanceof UnitItem unitItem && unitItem.getName().equals(name)) {
                System.out.println("Total number of " + name + " is " + (amount + unitItem.getAmount()) + " (Previous is " + unitItem.getAmount() + ")");
				unitItem.setAmount(amount +  unitItem.getAmount());

				System.out.println("Cost is $" + unitItem.cost() + " (Price per unit is $" + unitItem.getUnitPrice() + ")");
				return;
			}
		}

		System.out.print("Enter price per unit : ");
		while(true)
		{
			try {
				unitPrice = Double.parseDouble(in.nextLine());
				break;
			}
			catch (NumberFormatException e) {
				System.out.println("Invalid input.");
			}
		}


		UnitItem unitItem = new UnitItem(name, unitPrice, amount);
		System.out.println("Cost is $" + unitItem.cost());

		cart.addItem(unitItem);
	}

	public static void viewAllItemMenu() {
		// TODO Auto-generated method stub
		System.out.println("----------------------------------------");
		System.out.println("View all items in shopping cart");
		System.out.println("----------------------------------------");

		//fill code
		int counter = 1;
		for(Item item : cart.getItems()) {
			System.out.println("#" + counter++ + "\t" + item);
		}
	}
	
	public static void checkOutMenu(){
		System.out.println("----------------------------------------");
		System.out.println("Check out your shopping cart");
		System.out.println("----------------------------------------");
		
		//fill code
		System.out.println("Grand total cost : $" + cart.checkOut());
	}
	
	public static void viewPromotion(){
		System.out.println("**************************************************");
		System.out.println("Today Promotion");
		System.out.println("Buy at least " + cart.getRequiredUnitItems() +  " UnitItem(s) & " + cart.getRequiredWeightItems() + " WeightItem(s),Get " + cart.getDiscount() + "% off");
		System.out.println("**************************************************");
	}
	
}
