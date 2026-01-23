package card.type;

import card.base.UnitCard;
import player.Player;

public class VenomUnitCard extends UnitCard {
	
	public VenomUnitCard(String name, String flavorText, int bloodCost, int power, int health) {
		super(name, flavorText, bloodCost, power, health);
	}

	@Override
	public int attackUnit(UnitCard unitCard) {
		int currentHealth = unitCard.getHealth();
		unitCard.setHealth(0);
		return currentHealth;
	}

	public int dead(Player player) {
		player.takeDamage(getPower());
		return getPower();
	}
}
