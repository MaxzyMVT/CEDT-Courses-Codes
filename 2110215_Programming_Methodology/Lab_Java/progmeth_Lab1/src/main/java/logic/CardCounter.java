package logic;

public class CardCounter {
	
	private UnitCard card;
	private int count;
	
	public String toString() {
		return  this.getCard() + " x " + this.getCount();
	}

	public CardCounter(UnitCard card, int count) {
		setCard(card);
		setCount(count);
	}

	public UnitCard getCard() {
		return card;
	}

	public void setCard(UnitCard card) {
		this.card = card;
	}

	public int getCount() {
		return count;
	}

	public void setCount(int count) {
		this.count = Math.max(count, 0);
	}
}
