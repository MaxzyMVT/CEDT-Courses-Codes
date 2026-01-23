package logic;

import java.util.ArrayList;

public class UnitDeck {
    private ArrayList<CardCounter> cardsInDeck;
    private String deckName;

    public UnitDeck(String deckName) {
        setDeckName(deckName);
        cardsInDeck = new ArrayList<>();
    }

    public void addCard(UnitCard newCard, int count) {
        if (count > 0) {
            for (CardCounter counter : getCardsInDeck()) {
                if(counter.getCard().equals(newCard)) {
                    counter.setCount(counter.getCount() + count);
                    return;
                }
            }
            getCardsInDeck().add(new CardCounter(newCard, count));
        }
    }

    public void removeCard(UnitCard toRemove, int count) {
        if (count > 0) {
            for (int i = 0; i < getCardsInDeck().size(); i++) {
                CardCounter counter = getCardsInDeck().get(i);
                if (counter.getCard().equals(toRemove)) {
                    counter.setCount(counter.getCount() - count);
                    if (counter.getCount() == 0) {
                        getCardsInDeck().remove(i);
                    }
                    return;
                }
            }
        }
    }

    public ArrayList<CardCounter> getCardsInDeck() {
        return cardsInDeck;
    }

    public void setCardsInDeck(ArrayList<CardCounter> cardsInDeck) {
        this.cardsInDeck = cardsInDeck;
    }

    public String getDeckName() {
        return deckName;
    }

    public void setDeckName(String deckName) {
        this.deckName = deckName.isBlank() ? "Untitled Deck" : deckName;
    }

    public int cardCount() {
        int sum = 0;
        for (CardCounter counter : getCardsInDeck()) {
            sum += counter.getCount();
        }
        return sum;
    }

    public boolean existsInDeck(UnitCard card) {
        for (CardCounter counter : getCardsInDeck()) {
            if(counter.getCard().equals(card) && counter.getCount() > 0) {
                return true;
            }
        }
        return false;
    }

    public boolean equals(UnitDeck other) {
        return this.getDeckName().equals(other.getDeckName());
    }
}
