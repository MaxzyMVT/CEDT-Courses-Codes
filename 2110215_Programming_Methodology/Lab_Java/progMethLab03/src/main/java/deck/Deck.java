package deck;


import java.util.ArrayList;
import java.util.Arrays;

import card.base.Card;


public class Deck {
	private String name;
	private int deckSize;
	private Card[] deckList;

	public Deck(String name, Card[] deckList) {
		this.name = name;
		this.deckList = deckList;
		setDeckSize(deckList.length);
	}

		public int insertCard(Card card) throws InsertCardFailedException{
			int count = 0;
			for (Card c : this.deckList) {
				if (c.equals(card)) {
					count++;
				}
			}
			if(count >= 4) 
				throw new InsertCardFailedException("You can only put 4 of the same cards into the deck");

            this.deckList = Arrays.copyOf(getDeckList(), getDeckSize() + 1);
			this.deckList[getDeckSize()] = card;
			setDeckSize(getDeckSize() + 1);
			return getDeckSize();
		}

		public Card removeCard(int slotNumber) throws RemoveCardFailedException {
			if (getDeckSize() <= slotNumber) {
				throw new RemoveCardFailedException("Slot number " + slotNumber + " is too big for deck size " + getDeckSize());
			}		
			if (this.deckList[slotNumber] == null) {
				throw new RemoveCardFailedException("There is no card in that slot");
			}

			Card removedCard = this.deckList[slotNumber];

			this.deckList = Arrays.copyOf(getDeckList(), getDeckSize() + 1);
			for (int i = slotNumber; i < getDeckSize(); i++) {
				this.deckList[i] = this.deckList[i + 1];
			}
			this.deckList = Arrays.copyOf(getDeckList(), getDeckSize() - 1);

			setDeckSize(getDeckSize() - 1);
			return removedCard;
		}

	@Override
	public String toString() {
		return new StringBuilder()
				.append("{").append(this.getName()).append("}")
				.append("(").append(this.getDeckSize()).append(" deck size)")
				.toString();
	}

	/* GETTERS & SETTERS */

	public Card[] getDeckList() {
		return deckList;
	}

	public String getName() {
		return name;
	}

	public int getDeckSize() {
		return deckSize;
	}

	public void setDeckSize(int deckSize) {
		this.deckSize = deckSize;
	}
}
