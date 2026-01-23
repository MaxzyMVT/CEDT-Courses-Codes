package card.type;

import card.base.UnitCard;
import player.Player;

public class LeaderUnitCard extends UnitCard {
	private int buffPower;
	private int buffHealth;

	public LeaderUnitCard(String name, String flavorText, int bloodCost, int power, int health, int buffPower, int buffHealth) {
		super(name, flavorText, bloodCost, power, health);
		setBuffPower(buffPower);
		setBuffHealth(buffHealth);
	}

	@Override
	public int attackUnit(UnitCard unitCard) {
		int currentHealth = unitCard.getHealth();
		unitCard.setHealth(currentHealth - this.getPower());
		return currentHealth - unitCard.getHealth();
	}

	public void buffUnit(UnitCard[] alliesCard) {
		for (UnitCard u : alliesCard) {
			if(u != null) {
				u.setPower(u.getPower() + getBuffPower());
				u.setHealth(u.getHealth() + getBuffHealth());
			}
		}
	}

	public int getBuffPower() {
		return buffPower;
	}

	public void setBuffPower(int buffPower) {
		this.buffPower = Math.max(0, buffPower);
	}

	public int getBuffHealth() {
		return buffHealth;
	}

	public void setBuffHealth(int buffHealth) {
		this.buffHealth = Math.max(0, buffHealth);;
	}

	@Override
	public String toString() {
		return super.getName() + " (POW: " + super.getPower() + ", HP: " + super.getHealth() + 
				" | POW Inc: "+ this.getBuffPower() + ", HP Inc: " + this.getBuffHealth() + ")";
	}

}