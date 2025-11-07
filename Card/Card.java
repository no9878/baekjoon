package Card;

public class Card {
    private int number;
    private char shape;
    public Card(int number, char shape) {
        this.number = number;
        this.shape = shape;
    }
    public int getNumber(){
        return number;
    }
    public char getShape(){
        return shape;
    }

    @Override
    public String toString() {
        return
        "["+number +
                ", " + shape
            +    "]"
                ;
    }
}
