package Card;


import java.util.ArrayList;
public class CardGameMain {
    public static void main(String[] args) {
        Deck deck = new Deck();
        Player player1 = new Player(deck);
        Player player2 = new Player(deck);

        Result result = new Result();
        result.printresult(player1,player2);
    }
}
