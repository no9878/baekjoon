package Card;


import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Deck {
   private ArrayList<Card> deck;
    public Deck(){
        deck = new ArrayList<>();
        for (int i = 1; i < 14; i++) {
            deck.add(new Card(i, '♠'));
            deck.add(new Card(i, '♥'));
            deck.add(new Card(i, '◆'));
            deck.add(new Card(i, '♣'));

        }
        Collections.shuffle(deck);
    }

    public Card getCard(){
        Card firstone = deck.getFirst();
        deck.removeFirst();
        return firstone;
    }

}
