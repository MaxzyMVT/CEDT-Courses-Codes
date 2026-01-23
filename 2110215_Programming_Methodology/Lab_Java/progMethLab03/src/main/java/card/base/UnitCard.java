package card.base;

import player.Player;

public abstract class UnitCard extends Card  {
	private int power;
	private int health;

	public UnitCard(String name, String flavorText, int bloodCost, int power, int health) {
        super(name, flavorText, bloodCost);
		setPower(power);
		setHealth(health);
    }

	public abstract int attackUnit(UnitCard u);

	public int attackPlayer(Player opponent) {
		opponent.takeDamage(getPower());
		return getPower();
	}
	
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return super.getName() + "\tCost: " + this.getBloodCost() +"\t(POW: " + this.getPower() + ", HP: " + this.getHealth() + ")";
	}

	public int getPower() {
		return power;
	}

	public int getHealth() {
		return health;
	}

	public void setPower(int power) {
		this.power = Math.max(0, power);
	}

	public void setHealth(int health) {
		this.health = Math.max(0, health);
	}
}
