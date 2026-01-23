package card.type;

import card.base.UnitCard;
import player.Player;

public class DebuffUnitCard extends UnitCard {
	private int debuffPower;

	public DebuffUnitCard(String name, String flavorText, int bloodCost, int power, int health, int debuffPower) {
		super(name, flavorText, bloodCost, power, health);
		setDebuffPower(debuffPower);
	}

	@Override
	public int attackUnit(UnitCard unitCard) {
		int currentHealth = unitCard.getHealth();
		unitCard.setHealth(currentHealth - this.getPower());
		unitCard.setPower(unitCard.getPower() - this.getDebuffPower());
		return currentHealth - unitCard.getHealth();
	}

	public int getDebuffPower() {
		return debuffPower;
	}

	public void setDebuffPower(int level) {
		this.debuffPower = Math.max(0, level);;
	}
}
