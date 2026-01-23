package logic;

public class UnitCard {
	private String name;
	private int bloodCost;
	private int power;
	private int health;
	private String flavorText;

	public String toString() {
		return this.getName() + " (POW: " + this.getPower() + ", HP: " + this.getHealth() + ")";
	}

	public int attack(UnitCard target) {
		return 0;
	}

	public boolean equals(UnitCard other) {
		return this.getName().equals(other.getName());
	}

	public UnitCard(String name, int bloodCost, int power, int health, String flavorText) {
		setName(name);
		setBloodCost(bloodCost);
		setPower(power);
		setHealth(health);
		setFlavorText(flavorText);
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name.isBlank() ? "Creature" : name;
	}

	public int getBloodCost() {
		return bloodCost;
	}

	public void setBloodCost(int bloodCost) {
		this.bloodCost = Math.max(bloodCost, 0);
	}

	public int getPower() {
		return power;
	}

	public void setPower(int power) {
		this.power = Math.max(power, 0);
	}

	public int getHealth() {
		return health;
	}

	public void setHealth(int health) {
		this.health = Math.max(health, 1);
	}

	public String getFlavorText() {
		return flavorText;
	}

	public void setFlavorText(String flavorText) {
		this.flavorText = flavorText;
	}
}
