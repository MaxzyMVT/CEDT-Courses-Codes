package card.type;

import card.base.UnitCard;
import player.Player;

public class NormalUnitCard extends UnitCard {
	
	public NormalUnitCard(String name, String flavorText, int bloodCost, int power, int health) {
		super(name, flavorText, bloodCost, power, health);
	}

	public int attackUnit(UnitCard unitCard) {
		int currentHealth = unitCard.getHealth();
		unitCard.setHealth(currentHealth - this.getPower());
		return currentHealth - unitCard.getHealth();
	}
}

