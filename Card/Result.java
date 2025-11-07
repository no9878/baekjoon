package Card;

public class Result {

    private int result(Player p1,Player p2){
        return p1.getSum()>p2.getSum() ? p1.getSum() : p1.getSum()<p2.getSum() ? p2.getSum() : 0;
    }
    public void printresult(Player p1, Player p2){

        System.out.println("p1deck = " + p1.getPlayerdeck() +"합계 = "+p1.getSum());
        System.out.println("p2deck = " + p2.getPlayerdeck() +"합계 = "+p2.getSum());

        if (result(p1,p2)== p1.getSum())
            System.out.println("플레이어1 승리");
        else if (result(p1,p2)== p2.getSum())
            System.out.println("플레이어2 승리");
        else
            System.out.println("무승부");
    }
}
