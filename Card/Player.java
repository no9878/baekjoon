package Card;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;


public class Player {
    public ArrayList<Card> playerdeck;
    private Deck deck;

    public Player(Deck deck){
        this.deck = deck;
        playerdeck = new ArrayList<>();
    }
    private void getplayer(){
        for (int i = 0; i < 5; i++) {
            playerdeck.add(deck.getCard());
        }
    }
    public ArrayList<Card> getPlayerdeck(){
        getplayer();
        List<Character> list = List.of('♠','♥','◆','♣');
        Comparator<Card> sort = new Comparator<Card>() {
            @Override
            public int compare(Card c1, Card c2){
                int idx1 = list.indexOf(c1.getShape());
                int idx2 = list.indexOf(c2.getShape());
                if (c1.getNumber()!=c2.getNumber()) return c1.getNumber() - c2.getNumber();
                return idx1 - idx2;

            }
        };
        playerdeck.sort(sort);

        return playerdeck;

    }
    public int getSum(){
        int sum = 0;

        for (int i = 0; i < 5; i++) {
            sum+=playerdeck.get(i).getNumber();
        }
        return sum;
    }

    }




