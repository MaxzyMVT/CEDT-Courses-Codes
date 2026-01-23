package logic;

import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
public class CardUtil {
	
	public static boolean isExistsInList(UnitCard card, ArrayList<UnitCard> list) {
		return list.contains(card);
	}
	
	public static boolean isExistsInList(UnitDeck deck, ArrayList<UnitDeck> list) {
		return list.contains(deck);
	}
	
	public static boolean cardExistsInDeckList(ArrayList<UnitDeck> deckList, UnitCard cardToTest) {
		for (UnitDeck ud : deckList) {
			for (CardCounter counter : ud.getCardsInDeck()) {
				if(counter.getCard().equals(cardToTest) && counter.getCount() > 0) {
					return true;
				}
			}
		}
		return false;
	}
	
	public static ArrayList<UnitCard> getCardsFromFile(String filename){

		ArrayList<UnitCard> cardsFromFile = new ArrayList<UnitCard>();
		InputStream inputStream = CardUtil.class.getClassLoader().getResourceAsStream(filename);

		if (inputStream == null) {
			System.out.println("Cannot find file!");
			return null;
		}

        try (Scanner myReader = new Scanner(inputStream)) {
            while (myReader.hasNextLine()) {
                String line = myReader.nextLine();
                String[] cardInfo = line.split(",");

                String name = cardInfo[0];
                int bloodCost = Integer.parseInt(cardInfo[1]);
                int power = Integer.parseInt(cardInfo[2]);
                int health = Integer.parseInt(cardInfo[3]);
                String flavorText = cardInfo[4];
                UnitCard card = new UnitCard(name, bloodCost, power, health, flavorText);

                cardsFromFile.add(card);
            }
        } catch (Exception e) {
            System.out.println("File contains string with incorrect format!");
            return null;
        }
		return cardsFromFile;
	}

	public static void printCardList(ArrayList<UnitCard> cardList, boolean verbose) {
		
		for(int i = 0; i < cardList.size(); i++) {
			System.out.println(i + ") " + cardList.get(i));
			if(verbose) {
				System.out.println("Blood Cost: " + cardList.get(i).getBloodCost());
				System.out.println(cardList.get(i).getFlavorText());
				if(i < cardList.size()-1) System.out.println("-----");
			}
		}
	}
	
	public static void printDeck(UnitDeck ud) {
		
		if(ud.getCardsInDeck().size() == 0) {
			System.out.println("EMPTY DECK");
		}else {
			for(CardCounter cc : ud.getCardsInDeck()) {
				System.out.println(cc);
			}
		}
		
		System.out.println("Total Cards: " + ud.cardCount());
	}
	
	public static void printDeckList(ArrayList<UnitDeck> deckList) {
		
		
		for(int i = 0; i < deckList.size(); i++) {
			System.out.println(i + ") " + deckList.get(i).getDeckName());
			printDeck(deckList.get(i));
			if(i < deckList.size()-1) System.out.println("-----");
		}
	}
}
