package card.type;

import card.base.SpellCard;
import card.base.UnitCard;

public class BuffSpellCard extends SpellCard {
	private int powerIncrease;

	public BuffSpellCard(String name, String flavorText, int bloodCost, 
			boolean isBurstSpeed, int powerIncrease) {
		super(name, flavorText, bloodCost, isBurstSpeed);
		setPowerIncrease(powerIncrease);
	}

	@Override
	public void castSpell(UnitCard unitCard) {
		unitCard.setPower(unitCard.getPower() + getPowerIncrease());
	}

	public int getPowerIncrease() {
		return powerIncrease;
	}

	public void setPowerIncrease(int powerIncrease) {
		this.powerIncrease = Math.max(1, powerIncrease);
	}
}